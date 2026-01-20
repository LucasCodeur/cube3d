/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:06:40 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/19 15:15:49 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "parsing.h"
#include "test.h"
#include <math.h>
#include <mlx.h>

static int	compute_x_of_texture(t_data *data, t_img *text);
static int	compute_y_of_texture(t_img *text, int top_strip, int y);
static void	put_all_pixels(t_data *data, t_img *text, int x, int y);
static void	draw_line(t_data *data, int x);

/**
 * @brief allow to display the map
 * @param data contains all information necessary to the project.
 * @return true if success
 */
bool	draw_map(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		data->map.player.camera = define_percentage_of_fov(x);
		data->raycasting.ray_dir = define_ray(data);
		compute_height_of_line(data, &data->img.top_strip,
			&data->img.bottom_strip);
		draw_line(data, x);
		x++;
	}
	// t_display_map_2D(data);
	// display_minimap(data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.img, 0, 0);
	return (true);
}

/**
 * @brief draw the line define by x, the sky and the sol.
 * @param data all information about the program.
 * @param top_strip begin of the line to draw.
 * @param bottom_strip end of the line to draw.
 * @return
 */
static void	draw_line(t_data *data, int x)
{
	t_img	*text;
	int		y;

	y = 0;
	data->img.top_strip += data->raycasting.z;
	data->img.bottom_strip += data->raycasting.z;
	text = NULL;
	choose_texture(data, &text);
	text->step = text->double_height / (double)(data->img.bottom_strip
			- data->img.top_strip);
	text->x = compute_x_of_texture(data, text);
	text->y = compute_y_of_texture(text, data->img.top_strip, y);
	put_all_pixels(data, text, x, y);
}

/**
 * @brief allow to compute x of the texture
 * @param data all information about the program.
 * @param text texture to map.
 * @return x of the texture
 */
static int	compute_x_of_texture(t_data *data, t_img *text)
{
	int	texture_x;

	texture_x = (int)(data->raycasting.wall_x * text->height);
	if (texture_x < 0)
		texture_x = 1;
	else if (texture_x > text->height)
		texture_x = text->height - 1;
	if ((data->raycasting.side == 0 && data->raycasting.ray_dir.elements[0] < 0) || (data->raycasting.side == 1 && data->raycasting.ray_dir.elements[1] > 0))
		texture_x = text->height - texture_x - 1;
	return (texture_x);
}
/**
 * @brief allow to compute y of the texture
 * @param text texture to map.
 * @param top_strip top of the strip that have to display.
 * @param coordinate has to map inside the cordinate of the texture.
 * @return y of the texture
 */
static int	compute_y_of_texture(t_img *text, int top_strip, int y)
{
	int	texture_y;

	texture_y = 0;
	if (top_strip < 0)
		texture_y = (y - top_strip) * text->step;
	else
		texture_y = 0;
	return (texture_y);
}

/**
 * @brief allow to put all the pixels on the main screen
 * @param data all information about the program.
 * @param text pointer of the texture to map
 * @param x abcisssa of the screen
 * @param y ordinate of the screen on the strip of x
 * @return
 */
static void	put_all_pixels(t_data *data, t_img *text, int x, int y)
{
	t_pixel	*dst;
	t_pixel	color;

	color.channels[0] = data->parsing->ceiling_rgb_color[2];
	color.channels[1] = data->parsing->ceiling_rgb_color[1];
	color.channels[2] = data->parsing->ceiling_rgb_color[0];
	color.channels[3] = 255;
	dst = data->img.addr + x;
	while (y++ < data->img.top_strip && y < WIN_HEIGHT)
	{
		*dst = color;
		dst += data->img.pixels_per_line;
	}
	while (y++ < data->img.bottom_strip && y < WIN_HEIGHT)
	{
		color = *(text->addr + (int)text->y * text->pixels_per_line + text->x);
		text->y += text->step;
		if (text->y > text->height)
			text->y = text->height - 1;
		*dst = color;
		dst += data->img.pixels_per_line;
	}
	color.channels[0] = data->parsing->floor_rgb_color[2];
	color.channels[1] = data->parsing->floor_rgb_color[1];
	color.channels[2] = data->parsing->floor_rgb_color[0];
	color.channels[3] = 255;
	while (y++ < WIN_HEIGHT)
	{
		*dst = color;
		dst += data->img.pixels_per_line;
	}
}
