/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:06:40 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/26 18:09:46 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include  <mlx.h>

#include "debug.h"
#include "display.h"

void	update_maps(t_data* data)
{
	for (int i = 0; i < data->map.rows; i++)
	{
		for (int j = 0; j < data->map.rows; j++)
		{
			if (data->map.grid[i][j] == 'P')
				data->map.grid[i][j] = '0';
		}
	}
	data->map.grid[data->map.hero_pos.x][data->map.hero_pos.y] = 'P';
	d_print_grid(data->map);
}


void my_mlx_pixel_put_minimap(t_data *data, int x, int y, t_pixel *color)
{
    t_pixel *dst;
    if (x < 0 || x > WIDTH_MINIMAP || y < 0 || y > HEIGHT_MINIMAP) return;
    if (!data->img.addr) return;
    
    dst = (t_pixel*)(data->img.addr + (y * data->img.line_length + x * 4));
    *dst = *color;
}

bool	display_minimap(t_data* data)
{
	int size_cols = 0;
	int size_rows = 0;
	int tile_size = 0;
	
	size_cols = WIDTH_MINIMAP / data->map.cols;
	size_rows = HEIGHT_MINIMAP / data->map.rows;
	if (size_cols <= size_rows)
		tile_size = size_cols;
	else
		tile_size = size_rows;
	t_pixel color;
	for (int y = 0; y < data->map.rows; y++)
		for (int x = 0; x < data->map.cols; x++)
		{
			if (data->map.grid[y][x] == '0')
				color.value = RED;
			else if (data->map.grid[y][x] == 'P')
				color.value = GREEN;
			else
				color.value = BLUE;
			int px_start = x * tile_size;
			int py_start = y * tile_size;
			
			for (int py = 0; py < tile_size; py++)
				for (int px = 0; px < tile_size; px++)
					my_mlx_pixel_put_minimap(data, px_start + px, py_start + py, &color);
		}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.ptr, 0, 0);
	return (true);
}
