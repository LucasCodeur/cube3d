/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:16 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/15 11:38:11 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "display.h"
#include "error.h"
#include "parsing.h"
#include "test.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>

static void	ininitialize_values(t_data *data, t_parsing *parsing_data)
{
	ft_bzero(data, sizeof(t_data));
	ft_bzero(parsing_data, sizeof(t_parsing));
	data->mlx.max_height = WIN_HEIGHT;
	data->mlx.max_width = WIN_WIDTH;
	data->map.cols = SIZE_X;
	data->map.rows = SIZE_Y;
	data->map.player.pos = new_vector_2D(10.0f, 10.0f);
	data->map.player.dir = new_vector_2D(1.0f, 0.0f);
	data->map.player.plane = new_vector_2D(0.0f, 0.66f);
	data->map.player.camera = new_vector_2D(0.0f, 0.0f);
	parsing_data->map = &data->map;
	return ;
}

void	launcher(t_data *data)
{
	// mlx_init_window(data);
	// display_map(data);
	// display_minimap(data);
	init_screen_mlx(data);
	load_imgs(data);
	draw_map(data);
	// t_display_map_2D(data);
	// display_minimap(data);
	mlx_hook(data->mlx.win, KeyPress, KeyPressMask, move_hero, data);
	mlx_loop(data->mlx.ptr);
}

int	main(int argc, char *argv[])
{
	t_data		data;
	t_parsing	parsing_data;
	t_error		error;

	ininitialize_values(&data, &parsing_data);
	error = parsing(argc, argv, &parsing_data);
	if (error.code != ERR_OK)
	{
		// free_all(&parsing_data);
		return (EXIT_FAILURE);
	}
	launcher(&data);
	// mlx_hook_loop(parsing_data);
	// free_all(parsing_data);
	return (EXIT_SUCCESS);
}
