/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:06:40 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/16 14:50:32 by lud-adam         ###   ########.fr       */
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
	int tile_size;
	
	size_cols = WIDTH_MINIMAP / data->map.cols;
	size_rows = HEIGHT_MINIMAP / data->map.rows;
	if (size_cols <= size_rows)
		tile_size = size_cols;
	else
		tile_size = size_rows;
	draw_map(data, tile_size);
	draw_hero(data, tile_size);
	t_cast_dir_vec(data, tile_size);	
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.ptr, 0, 0);
	return (true);
}
