/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:59:23 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/21 11:59:40 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <mlx.h>

static void	put_pixel(t_img *img, int x, int y, t_pixel color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	dst = (char *)img->addr + (y * img->line_length + x * (img->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color.value;
}

static void	draw_square(t_data *data, int x, int y, int size, t_pixel color)
{
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			put_pixel(&data->img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_minimap(t_data *data)
{
	t_pixel	color;
	int		x;
	int		y;
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	int		player_screen_x;
	int		player_screen_y;

	start_x = data->map.player.pos.elements[0] - MINI_RADIUS;
	start_y = data->map.player.pos.elements[1] - MINI_RADIUS;
	if (start_x < 0)
		start_x = 0;
	if (start_x + 2 * MINI_RADIUS + 1 > data->map.width)
		start_x = data->map.width - (2 * MINI_RADIUS + 1);
	if (start_y < 0)
		start_y = 0;
	if (start_y + 2 * MINI_RADIUS + 1 > data->map.height)
		start_y = data->map.height - (2 * MINI_RADIUS + 1);
	end_x = start_x + 2 * MINI_RADIUS + 1;
	end_y = start_y + 2 * MINI_RADIUS + 1;
	y = start_y;
	while (y < end_y)
	{
		x = start_x;
		while (x < end_x)
		{
			if (x >= 0 && y >= 0 && x < data->map.width && y < data->map.height)
			{
				if (data->map.grid[y][x] == '1')
					color.value = 0x808080;
				else
					color.value = 0xFFFAF0;
				draw_square(data, MINI_OFFSET_X + (x - start_x) * MINI_TILE,
					MINI_OFFSET_Y + (y - start_y) * MINI_TILE, MINI_TILE,
					color);
			}
			else
			{
				color.value = 0x000000;
			}
			draw_square(data, MINI_OFFSET_X + (x - start_x) * MINI_TILE,
				MINI_OFFSET_Y + (y - start_y) * MINI_TILE, MINI_TILE, color);
			x++;
		}
		y++;
	}
	color.value = 0xFF0000;
	player_screen_x = MINI_OFFSET_X + (data->map.player.pos.elements[0]
			- start_x) * MINI_TILE;
	player_screen_y = MINI_OFFSET_Y + (data->map.player.pos.elements[1]
			- start_y) * MINI_TILE;
	draw_square(data, player_screen_x - PLAYER_SIZE / 2, player_screen_y
		- PLAYER_SIZE / 2, PLAYER_SIZE, color);
}
