/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_2D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:02:32 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/26 18:06:51 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "test.h"

#include <stdbool.h>
#include  <mlx.h>

/**
* @brief allow to display the map
* @param data contains all information necessary to the project.
* @return true if success
*/
bool	t_display_map_2D(t_data* data)
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
	// t_display_fov(data);
	// t_cast_plane_vec(data, data->tile_size);
	t_ray_casting_2D(data);
	t_cast_dir_vec(data, data->tile_size);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.ptr, 0, 0);
	return (true);
}
