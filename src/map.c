/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:06:40 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/27 17:28:26 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <mlx.h>

#include "display.h"

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
		data->ray.dir = define_ray(data);
		compute_height_of_line(data, &draw_start, &draw_end);	
		draw_line(data, draw_start, draw_end, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.ptr, 0, 0);
	return (true);
}
