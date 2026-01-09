/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:05:29 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/18 13:21:33 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>

#include "display.h"

/**
 * @brief fill draw_start and draw_end, that the born of the line in order to display the walls.
 * @param data all information about the program.
 * @param top_strip the beginning of the line to draw in order to display the wall.
 * @param bottom_strip the ending of the line to draw in order to display the wall.
 * @return
 */
void compute_height_of_line(t_data* data, int* top_strip, int* bottom_strip)
{
	int		strip_height;
	double	dist;

	dist = compute_dist(data, data->ray_dir);
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
	strip_height = (int)(WIN_HEIGHT / dist);
	*top_strip = -strip_height * 0.5 + WIN_HEIGHT * 0.5;
	*bottom_strip = strip_height * 0.5 + WIN_HEIGHT * 0.5;
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
