/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:16 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/08 12:37:43 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "parsing.h"
#include "debug.h"
#include "test.h"

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

bool	ininitialize_values(t_data *data, t_parsing *parsing_data)
{
	ft_bzero(data, sizeof(t_data));
	ft_bzero(parsing_data, sizeof(t_parsing *));
	data->mlx.max_height = WIN_HEIGHT;
	data->mlx.max_width = WIN_WIDTH;
	data->map.cols = SIZE_X;
	data->map.rows = SIZE_Y;
	data->map.player.pos = new_vector_2D(1.0f, 1.0f);
	data->map.player.dir = new_vector_2D(1.0f, 0.0f);
	data->map.player.plane = new_vector_2D(0.0f, 0.66f);
	parsing_data->map = &data->map;
	data->map.player.camera = new_vector_2D(0.0f, 0.0f);
	return (true);
}

void	launcher(t_data *data)
{
	// mlx_init_window(data);
	// display_map(data);
	// display_minimap(data);
	init_screen_mlx(data);
	load_imgs(data);
	draw_map(data);
	t_display_map_2D(data);
	mlx_hook(data->mlx.win, KeyPress, KeyPressMask, move_hero, data);
	mlx_loop(data->mlx.ptr);
}

int main(int argc, char *argv[])
{
	t_data		data;
	t_parsing	parsing_data;

	
	ininitialize_values(&data, &parsing_data);
	if (parsing(argc, argv, &parsing_data))
	{
		free_all(&parsing_data);
		return (1);
	}
	launcher(&data);
	// mlx_hook_loop(parsing_data);
	// free_all(parsing_data);
	return (0);
}
