/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:06:40 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/14 16:49:02 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include  <mlx.h>

#include "display.h"

// void	update_maps(t_data* data)
// {
// 	for (int i = 0; i < rows; i++)
// 	{
// 		for (int j = 0; j < cols; j++)
// 		{
// 			if (i == 0 || i == rows - 1)
// 				data.map[i][j] = '1';
// 			else if (j == 0 || j == cols - 1)
// 				data.map[i][j] = '1';
// 			else if (j == 2 && i == 3)
// 				data.map[i][j] = 'P';
// 			else
// 				data.map[i][j] = '0';
// 		}
// 		data.map[i][cols] = '\0';
// 	}
//
// 	data->map[data->hero_pos.x][data->hero_pos.y] = 'P';
// }

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
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
			{
				data->img = fill_image(data, ASSET_TILE);
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->img.img, x, y);
			}
			else if (data->map[i][j] == '1')
			{
				data->img = fill_image(data, ASSET_BG);
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->img.img, x, y);
			}
			else if (data->map[i][j] == 'P')
			{
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
