/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:06:40 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/06 19:58:55 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "test.h"

#include  <mlx.h>
#include <math.h>

static int	compute_x_of_texture(t_data *data, int text_size);
static void draw_line(t_data* data, int top_strip, int bottom_wall, int x);

/**
* @brief allow to display the map
* @param data contains all information necessary to the project.
* @return true if success
*/
bool	draw_map(t_data* data)
{
	int x;
	int	top_strip;
	int	bottom_strip;
	
	x = 0;
	while (x < WIN_WIDTH)
	{
		data->map.player.camera = define_percentage_of_fov(x);
		data->ray_dir = define_ray(data);
		compute_height_of_line(data, &top_strip, &bottom_strip);	
		draw_line(data, top_strip, bottom_strip, x);
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
static void draw_line(t_data* data, int top_strip, int bottom_strip, int x)
{
	t_img		*text;
	t_pixel		color;
	t_pixel		*dst;
	double		step;	
	double		tex_y;
	int			tex_x;
	int			y;

	y = 0;
	// y += data->z;
	top_strip += data->z;
	bottom_strip += data->z;
	text = NULL;

	if (data->side == 0)
	{
		if (data->ray_dir.elements[0] >= 0)
			text = &data->imgs.wall_east;
		else
			text = &data->imgs.wall_west;
	}
	else
	{
		if (data->ray_dir.elements[1] >= 0)
			text = &data->imgs.wall_south;
		else
			text = &data->imgs.wall_north;
	}
	step = (double)text->height / (double)(bottom_strip - top_strip);
	dst = (t_pixel *)data->img.addr + x;
	color.value = BLACK;
	int pixels_per_line = data->img.line_length / sizeof(t_pixel);
	while (y < top_strip && y < WIN_HEIGHT)
	{
		*dst = color;
		dst += pixels_per_line;
		y++;
	}
	tex_x = compute_x_of_texture(data, text->height);
	if (top_strip < 0)
		tex_y = (y - top_strip) * step;
	else
		tex_y = 0;
	tex_x *= 4;
	while (y < bottom_strip && y < WIN_HEIGHT)
	{
		color.value = *(int *)(text->addr + (int)tex_y * text->line_length + tex_x);
		tex_y += step;
		if (tex_y > text->height)
			tex_y = text->height - 1;
		*dst = color;
		dst += pixels_per_line;
		y++;
	}
	color.value = BLACK;
	// 	my_mlx_pixel_put(data, x, y++, &color);
	while (y < WIN_HEIGHT)
	{
		*dst = color;
		dst += pixels_per_line;
		y++;
	}
}

/**
* @brief allow to compute x and y of the texture
* @param data all information about the program.
* @param text_size size of the texture
* @param x boolean to know if I have to compute x or y of the texture 
* @return x or y of the texture
*/
static int	compute_x_of_texture(t_data *data, int text_size)
{
	int	texture_x;;

	texture_x = (int)(data->wall_x * text_size);
	if (texture_x < 0)
		texture_x = 1;
	else if (texture_x > text_size)
		texture_x = text_size - 1;
	return (texture_x);
}
