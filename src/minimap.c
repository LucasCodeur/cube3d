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

// void	update_maps(t_data* data)
// {
// 	for (int i = 0; i < data->map.rows; i++)
// 	{
// 		for (int j = 0; j < data->map.rows; j++)
// 		{
// 			if (data->map.grid[i][j] == 'P')
// 				data->map.grid[i][j] = '0';
// 		}
// 	}
// 	data->map.grid[data->map.hero_pos.x][data->map.hero_pos.y] = 'P';
// 	d_print_grid(data->map);
// }

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	t_pixel	*dst;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

bool	display_minimap(t_data* data)
{
	int i;
	int j;
	int x;
	int y;
	int	temp_x;
	int	temp_y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	mlx_clear_window(data->mlx.ptr, data->mlx.win);
	while (i < data->map.cols)
	{
		while (j < data->map.rows)
		{
			if (data->map.grid[i][j] == '0')
			{
				if (i == data->map.hero_pos.x && j == data->map.hero_pos.y)
					fill_frame(data, ASSET_PLAYER, &temp_x, &temp_y);
				else
					fill_frame(data, ASSET_TILE, &temp_x, &temp_y);
			}
			else if (data->map.grid[i][j] == '1')
					fill_frame(data, ASSET_BG, &temp_x, &temp_y);
			j++;
			x += temp_x;
			temp_x = 0;
		}
		x = 0;
		y += temp_y;
		temp_y = 0;
		j = 0;
		i++;
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.ptr, x, y);
	return (true);
}
