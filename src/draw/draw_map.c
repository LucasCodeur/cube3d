/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:51:45 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/06 19:55:52 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "display.h"

static int	compute_x_y_text(t_data *data, int text_size, bool x);
t_img choose_texture(t_data *data);
/**
 * @brief fill draw_start and draw_end, that the born of the line in order to display the walls.
 * @param data all information about the program.
 * @param draw_start the beginning of the line to draw in order to display the wall.
 * @param draw_end the ending of the line to draw in order to display the wall.
 * @return
 */
void compute_height_of_line(t_data* data, int* draw_start, int* draw_end)
{
	int		line_height;
	double	dist;

	dist = compute_dist(data, data->ray_dir);
	if (dist < 0)
		dist = 1;
	if (data->side == 0)
	{
		data->wall_x = data->map.player.pos.elements[1] + dist * data->ray_dir.elements[1];
		data->wall_y = data->map.player.pos.elements[0] + dist * data->ray_dir.elements[0];
	}
	else
	{
		data->wall_x = data->map.player.pos.elements[0] + dist * data->ray_dir.elements[0];
		data->wall_y = data->map.player.pos.elements[1] + dist * data->ray_dir.elements[1];
	}
	data->wall_x -= floor(data->wall_x);
	line_height = (int)(WIN_HEIGHT / dist);
	*draw_start = -line_height * 0.5 + WIN_HEIGHT * 0.5;
	*draw_end = line_height * 0.5 + WIN_HEIGHT * 0.5;
}

/**
* @brief define camera according x 
* @param x position on the abscisse
* @return the value of camera that correspond at of percentage of the fov
*/
t_vec define_percentage_of_fov(int x)
{
	t_vec camera;

	camera.elements[0] = (x * 2) / (double)WIN_WIDTH - 1;
	camera.elements[1] = 0.0f;
	return (camera);
}

/**
* @brief define the ray to cast
* @param data all information about the program
* @return the ray
*/
t_vec define_ray(t_data* data)
{
	t_vec ret;

	ret.elements[0] = data->map.player.dir.elements[0] + data->map.player.plane.elements[0] * data->map.player.camera.elements[0];
	ret.elements[1] = data->map.player.dir.elements[1] + data->map.player.plane.elements[1] * data->map.player.camera.elements[0];
	return (ret);
}

/**
* @brief draw the line define by x, the sky and the sol.
* @param data all information about the program.
* @param draw_start begin of the line to draw.
* @param draw_end end of the line to draw.
* @return
*/
void draw_line(t_data* data, int top_wall, int bottom_wall, int x)
{
	t_pixel color;
	t_img	text;
	int		tex_x;
	double	tex_y;
	int		y;

	y = 0;
	text = choose_texture(data);
	color.value = BLACK;
	while (y < top_wall)
		my_mlx_pixel_put(data, x, y++, &color);
	tex_x = compute_x_y_text(data, text.height, true);
	double	step =  (double)text.height / (double)(bottom_wall - top_wall);
	if (top_wall < 0)
		tex_y = (y - top_wall) * step;
	else
		tex_y = 0;
	while (y < bottom_wall)
	{
		color.value = *(int *)(text.addr + (int)tex_y * text.line_length + tex_x * (text.bits_per_pixel / 8));
		my_mlx_pixel_put(data, x, y++, &color);
		tex_y += step;
		if (tex_y > text.height)
			tex_y = (double)text.height;
	}
	color.value = WHITE;
	while (y < WIN_HEIGHT - 1)
		my_mlx_pixel_put(data, x, y++, &color);
}

/**
* @brief allow to compute x and y of the texture
* @param data all information about the program.
* @param text_size size of the texture
* @param x boolean to know if I have to compute x or y of the texture 
* @return x or y of the texture
*/
static int	compute_x_y_text(t_data *data, int text_size, bool x)
{
	int	tex_x_or_y;

	if (x == true)
		tex_x_or_y = (int)(data->wall_x * text_size);
	else
		tex_x_or_y = (int)(data->wall_y * text_size);
	if (tex_x_or_y < 0)
		tex_x_or_y = 1;
	else if (tex_x_or_y > text_size)
		tex_x_or_y = text_size - 1;
	return (tex_x_or_y);
}
