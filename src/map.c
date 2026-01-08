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
static void draw_line(t_data* data, int top_wall, int bottom_wall, int x);

/**
* @brief allow to display the map
* @param data contains all information necessary to the project.
* @return true if success
*/
bool	draw_map(t_data* data)
{
	int x;
	int	draw_start;
	int	draw_end;
	
	x = 0;
	clear_img(&data->img);
	while (x < WIN_WIDTH)
	{
		data->map.player.camera = define_percentage_of_fov(x);
		data->ray_dir = define_ray(data);
		compute_height_of_line(data, &draw_start, &draw_end);	
		draw_line(data, draw_start, draw_end, x);
		x++;
	}
	// t_display_map_2D(data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.img, 0, 0);
	return (true);
}

/**
* @brief draw the line define by x, the sky and the sol.
* @param data all information about the program.
* @param draw_start begin of the line to draw.
* @param draw_end end of the line to draw.
* @return
*/
static void draw_line(t_data* data, int top_wall, int bottom_wall, int x)
{
	t_img	text;
	double	step;	
	double	tex_y;
	int		tex_x;
	int		y;

	y = 0;
	text = choose_texture(data);
	text.color.value = BLACK;
	step = (double)text.height / (double)(bottom_wall - top_wall);
	while (y < top_wall)
		my_mlx_pixel_put(data, x, y++, &text.color);
	tex_x = compute_x_of_texture(data, text.height);
	if (top_wall < 0)
		tex_y = (y - top_wall) * step;
	else
		tex_y = 0;
	while (y < bottom_wall)
	{
		text.color.value = *(int *)(text.addr + (int)tex_y * text.line_length + tex_x * (text.bits_per_pixel / 8));
		my_mlx_pixel_put(data, x, y++, &text.color);
		tex_y += step;
		if (tex_y > text.height)
			tex_y = (double)text.height;
	}
	text.color.value = BLACK;
	while (y < WIN_HEIGHT - 1)
		my_mlx_pixel_put(data, x, y++, &text.color);
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
