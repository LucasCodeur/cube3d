/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:51:45 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/18 13:41:47 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

/**
 * @brief fill draw_start and draw_end, that the born of the line in order to display the walls.
 * @param data all information about the program.
 * @param draw_start the beginning of the line to draw in order to display the wall.
 * @param draw_end the ending of the line to draw in order to display the wall.
 * @return
 */
void compute_height_of_line(t_data* data, int* draw_start, int* draw_end)
{
	double	line_height;
	double	dist;

	dist = compute_dist(data, data->ray.dir);
	line_height = (int)(WIN_HEIGHT / dist);
	*draw_start = -line_height / 2 + (double)WIN_HEIGHT / 2 + 0.5f;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = line_height / 2 + (double)WIN_HEIGHT / 2 + 0.5f;
	if (*draw_end >= WIN_HEIGHT)
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

	camera.elements[0] = 2 * x / (double)WIN_WIDTH - 1;
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
	int	y;

	y = 0;
	color.value = YELLOW;
	while (y++ < draw_start)
		my_mlx_pixel_put(data, x, y, &color);
	color.value = ORANGE;
	y = draw_start;
	while (y++ < draw_end)
		my_mlx_pixel_put(data, x, y, &color);
	color.value = GREEN;
	y = draw_end;
	while (y++ < WIN_HEIGHT)
		my_mlx_pixel_put(data, x, y, &color);
	return ;
}
