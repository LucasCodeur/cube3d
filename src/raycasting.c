/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:05:29 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/21 17:05:42 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <math.h>
#include <stdbool.h>

/**
 * @brief fill top strip and bottom_strip, that the born of the line in order to display the walls.
 * @param data all information about the program.
 * @param top_strip the beginning of the line to draw in order to display the wall.
 * @param bottom_strip the ending of the line to draw in order to display the wall.
 * @return
 */
void	compute_height_of_line(t_data *data, int *top_strip, int *bottom_strip)
{
	int		strip_height;
	double	dist;

	dist = compute_dist(data, data->raycasting.ray_dir);
	if (dist < 0.1)
		dist = 0.5;
	if (data->raycasting.side == 0)
	{
		data->raycasting.wall_x = data->map.player.pos.elements[1] + dist
			* data->raycasting.ray_dir.elements[1];
		data->raycasting.wall_y = data->map.player.pos.elements[0] + dist
			* data->raycasting.ray_dir.elements[0];
	}
	else
	{
		data->raycasting.wall_x = data->map.player.pos.elements[0] + dist
			* data->raycasting.ray_dir.elements[0];
		data->raycasting.wall_y = data->map.player.pos.elements[1] + dist
			* data->raycasting.ray_dir.elements[1];
	}
	data->raycasting.wall_x -= floor(data->raycasting.wall_x);
	strip_height = (int)(WIN_HEIGHT / dist);
	*top_strip = -strip_height * 0.5 + WIN_HEIGHT * 0.5;
	*bottom_strip = strip_height * 0.5 + WIN_HEIGHT * 0.5;
}

/**
 * @brief define camera according x
 * @param x position on the abscisse
 * @return the value of camera that correspond at of percentage of the fov
 */
t_vec	mapping_x_on_screen(int x)
{
	t_vec	camera;

	camera.elements[0] = (x * 2 / (double)WIN_WIDTH) - 1;
	camera.elements[1] = 0.0f;
	return (camera);
}

/**
 * @brief define the ray to cast
 * @param data all information about the program
 * @return the ray
 */
t_vec	define_ray(t_data *data)
{
	t_vec	ret;

	ret.elements[0] = data->map.player.dir.elements[0]
		+ data->map.player.plane.elements[0]
		* data->map.player.camera.elements[0];
	ret.elements[1] = data->map.player.dir.elements[1]
		+ data->map.player.plane.elements[1]
		* data->map.player.camera.elements[0];
	return (ret);
}
