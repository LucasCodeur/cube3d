/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:51:45 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/02 16:05:03 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "display.h"

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
	if (data->side == 0)
		data->wall_x = data->map.player.pos.elements[1] + dist * data->ray_dir.elements[1];
	else
		data->wall_x = data->map.player.pos.elements[0] + dist * data->ray_dir.elements[0];
	data->wall_x -= floor(data->wall_x);
	line_height = (int)(WIN_HEIGHT / dist);
	*draw_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = line_height / 2 + WIN_HEIGHT / 2;
	if (*draw_end > WIN_HEIGHT)
		*draw_end = WIN_HEIGHT - 1;
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
void draw_line(t_data* data, int draw_start, int draw_end, int x)
{
	t_pixel color;
	t_img	text;
	int		tex_y;
	int		tex_x;
	int		y;

	y = 0;
	text = choose_texture(data);
	color.value = YELLOW;
	tex_x = (int)(data->wall_x * 64);
	if (tex_x < 0)
		tex_x = 0;
	else if (tex_x > 64)
		tex_x = 64;
	while (y < draw_start)
		my_mlx_pixel_put(data, x, y++, &color);
	y = draw_start;
	while (y < draw_end)
	{
		data->wall_y = (double)(y - draw_start) / (draw_end - draw_start);
		tex_y = (int)(data->wall_y * 64);
		if (tex_y < 0)
			tex_y = 0;
		else if (tex_y > 64)
			tex_y = 64;
		color.value = *(int *)(text.addr + tex_y * text.line_length + tex_x * (text.bits_per_pixel / 8));
		my_mlx_pixel_put(data, x, y++, &color);
	}
	color.value = GREEN;
	y = draw_end;
	while (y < WIN_HEIGHT)
		my_mlx_pixel_put(data, x, y++, &color);
	return ;
}

/**
* @brief allow to choose which texture according side and the direction of the ray
* @param all informatio about the program
* @return the texture to display
*/
t_img choose_texture(t_data *data)
{
	if (data->side == 0)
	{
		if (data->ray_dir.elements[0] >= 0)
			return (data->imgs.wall_east);
		else
			return (data->imgs.wall_west);
	}
	else
	{
		if (data->ray_dir.elements[1] >= 0)
			return (data->imgs.wall_south);
		else
			return (data->imgs.wall_north);
	}
}
