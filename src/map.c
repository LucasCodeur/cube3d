/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:06:40 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/18 16:58:56 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include  <mlx.h>

#include "display.h"
#include "test.h"

/**
* @brief allow to display the map
* @param data contains all information necessary to the project.
* @return true if success
*/
bool	display_map(t_data* data)
{
	int size_cols; 
	int size_rows;
	
	size_cols = WIN_WIDTH / data->map.cols;
	size_rows = WIN_HEIGHT / data->map.rows;
	if (size_cols <= size_rows)
		data->tile_size = size_cols;
	else
		data->tile_size = size_rows;
	clear_img(&data->img);
	draw_map(data, data->tile_size);
	draw_hero(data, data->tile_size);
	t_display_fov(data);
	// t_cast_plane_vec(data, data->tile_size);
	// t_ray_casting_2D(data);
	t_cast_dir_vec(data, data->tile_size);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.ptr, 0, 0);
	return (true);
}
