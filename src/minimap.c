/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:59:23 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/21 16:26:16 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "parsing.h"

static void	init_values(t_data *data, t_minimap_variables *minimap_var)
{
	minimap_var->start_x = data->map.player.pos.elements[0] - MINI_RADIUS;
	minimap_var->start_y = data->map.player.pos.elements[1] - MINI_RADIUS;
	if (minimap_var->start_x < 0)
		minimap_var->start_x = 0;
	if (minimap_var->start_x + 2 * MINI_RADIUS + 1 > data->map.width)
		minimap_var->start_x = data->map.width - (2 * MINI_RADIUS + 1);
	if (minimap_var->start_y < 0)
		minimap_var->start_y = 0;
	if (minimap_var->start_y + 2 * MINI_RADIUS + 1 > data->map.height)
		minimap_var->start_y = data->map.height - (2 * MINI_RADIUS + 1);
	minimap_var->end_x = minimap_var->start_x + 2 * MINI_RADIUS + 1;
	minimap_var->end_y = minimap_var->start_y + 2 * MINI_RADIUS + 1;
}

static void	draw_player_minimap(t_data *data, t_minimap_variables *minimap_var)
{
	t_drawing_infos	drawing_infos;

	minimap_var->color.value = 0xFF0000;
	minimap_var->player_screen_x = MINI_OFFSET_X
		+ (data->map.player.pos.elements[0] - minimap_var->start_x) * MINI_TILE;
	minimap_var->player_screen_y = MINI_OFFSET_Y
		+ (data->map.player.pos.elements[1] - minimap_var->start_y) * MINI_TILE;
	drawing_infos.x = minimap_var->player_screen_x - PLAYER_SIZE / 2;
	drawing_infos.y = minimap_var->player_screen_y - PLAYER_SIZE / 2;
	drawing_infos.size = PLAYER_SIZE;
	draw_square(data, drawing_infos, minimap_var->color);
}

static void	draw_structure_minimap(t_data *data,
		t_minimap_variables *minimap_var)
{
	t_drawing_infos	drawing_infos;

	if (minimap_var->x >= 0 && minimap_var->y >= 0
		&& minimap_var->x < data->map.width
		&& minimap_var->y < data->map.height)
	{
		if (minimap_var->x < (int)ft_strlen(data->map.grid[minimap_var->y]))
		{
			if (data->map.grid[minimap_var->y][minimap_var->x] == '1')
				minimap_var->color.value = 0x808080;
			else
				minimap_var->color.value = 0xFFFAF0;
		}
	}
	else
	{
		minimap_var->color.value = 0x000000;
	}
	drawing_infos.x = MINI_OFFSET_X + (minimap_var->x - minimap_var->start_x)
		* MINI_TILE;
	drawing_infos.y = MINI_OFFSET_Y + (minimap_var->y - minimap_var->start_y)
		* MINI_TILE;
	drawing_infos.size = MINI_TILE;
	draw_square(data, drawing_infos, minimap_var->color);
}

void	draw_minimap(t_data *data)
{
	t_minimap_variables	minimap_var;

	init_values(data, &minimap_var);
	minimap_var.y = minimap_var.start_y;
	while (minimap_var.y < minimap_var.end_y)
	{
		minimap_var.x = minimap_var.start_x;
		while (minimap_var.x < minimap_var.end_x)
		{
			draw_structure_minimap(data, &minimap_var);
			minimap_var.x++;
		}
		minimap_var.y++;
	}
	draw_player_minimap(data, &minimap_var);
}
