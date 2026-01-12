/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:06:40 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/12 16:40:31 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "test.h"

#include  <mlx.h>
#include <math.h>

static int	compute_x_of_texture(t_data *data, int text_size);
static int	compute_y_of_texture(t_img *text, int top_strip, int y);
static void	put_all_pixels(t_data *data, t_img *text, int x, int y);
static void draw_line(t_data* data, int x);

/**
* @brief allow to display the map
* @param data contains all information necessary to the project.
* @return true if success
*/
bool	draw_map(t_data* data)
{
	int x;
	
	x = 0;
	while (x < WIN_WIDTH)
	{
		data->map.player.camera = define_percentage_of_fov(x);
		data->ray_dir = define_ray(data);
		compute_height_of_line(data, &data->img.top_strip, &data->img.bottom_strip);	
		draw_line(data, x);
		x++;
	}
	// t_display_map_2D(data);
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
static void draw_line(t_data* data, int x)
{
	t_img		*text;
	int			y;

	y = 0;
	data->img.top_strip += data->z;
	data->img.bottom_strip += data->z;
	text = NULL;
	choose_texture(data, &text);
	text->step = text->double_height / (double)(data->img.bottom_strip - data->img.top_strip);
	text->x = compute_x_of_texture(data, text->height);
	text->y = compute_y_of_texture(text, data->img.top_strip, y);
	put_all_pixels(data, text, x, y);
}

/**
* @brief allow to compute x of the texture
* @param data all information about the program.
* @param text_size size of the texture
* @return x of the texture
*/
static int	compute_x_of_texture(t_data *data, int text_size)
{
	int	texture_x;

	texture_x = (int)(data->wall_x * text_size);
	if (texture_x < 0)
		texture_x = 1;
	else if (texture_x > text_size)
		texture_x = text_size - 1;
	return (texture_x);
}
/**
* @brief allow to compute y of the texture
* @param data all information about the program.
* @return y of the texture
*/
static int	compute_y_of_texture(t_img *text, int top_strip, int y)
{
	int	text_y;

	text_y = 0;
	if (top_strip < 0)
		text_y = (y - top_strip) * text->step;
	else
		text_y = 0;
	return (text_y);
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
	t_pixel		*dst;
	t_pixel		color;

	color.value = BLACK;	
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
	color.value = BLACK;
	while (y++ < WIN_HEIGHT)
	{
		*dst = color;
		dst += data->img.pixels_per_line;
	}
}
