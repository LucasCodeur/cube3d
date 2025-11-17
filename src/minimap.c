/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:06:40 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/17 14:44:23 by lud-adam         ###   ########.fr       */
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

bool	display_minimap(t_data* data)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (i < data->map.cols)
	{
		while (j < data->map.rows)
		{
			if (data->map.grid[i][j] == '0')
			{
				data->img = fill_image(data, ASSET_TILE);
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->img.img, x, y);
			}
			else if (data->map.grid[i][j] == '1')
			{
				data->img = fill_image(data, ASSET_BG);
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->img.img, x, y);
			}
			else if (data->map.grid[i][j] == 'P')
			{
				data->map.hero_pos.x = j;
				data->map.hero_pos.y = i;
				data->img = fill_image(data, ASSET_PLAYER);
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->img.img, x, y);
			}
			j++;
			x += 32;
		}
		x = 0;
		y += 32;
		j = 0;
		i++;
	}
	return (true);
}
