/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:03:49 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/15 15:55:39 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "display.h"
#include "error.h"
#include "matrice.h"
#include "parsing.h"
#include "test.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include <stdlib.h>
#include <sys/time.h>

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
	return ;
}

int	execute(t_data *data)
{
	data->fps.current_time = get_time();
	data->fps.delta_time = data->fps.current_time - data->fps.last_time;
	if (data->fps.delta_time >= FRAME_DURATION)
	{
		move_hero(data);
		rotate_hero(data);
		data->fps.count_frame++;
		draw_map(data);
		count_fps(data);
		if (data->keycode.escape == true)
		{
			exit(0);
		}
	}
	return (0);
}

void	launcher(t_data *data)
{
	init_screen_mlx(data);
	load_imgs(data);
	data->fps.last_time = get_time();
	if (mlx_hook(data->mlx.win, 17, 0, close_win, &data) == 0)
		return ;
	mlx_hook(data->mlx.win, KeyPress, KeyPressMask, press_move, data);
	mlx_hook(data->mlx.win, KeyRelease, KeyReleaseMask, release_move, data);
	mlx_loop_hook(data->mlx.ptr, execute, data);
	mlx_loop(data->mlx.ptr);
}

void	print_message_error(t_error error)
{
	if (error.code == ERR_FAIL)
		printf("Generic problem\n");
	else if (error.code == ERR_MEMORY)
		printf("Memory problem\n");
	else if (error.code == ERR_INVALID_ARG)
		printf("Invalid argument problem\n");
	else if (error.code == ERR_IO)
		printf("Open/Read file problem\n");
	else if (error.code == ERR_MLX)
		printf("Mlx problem\n");
	else
		printf("No problem\n");
	printf("%s\n", error.message);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_error	error;

	ininitialize_values(&data, data.parsing);
	error = parsing(argc, argv, &data);
	launcher(&data);
	// mlx_hook_loop(parsing_data);
	// free_all(parsing_data);
	error.code = ERR_MLX;
	printf("exit code : %d\n", error.code);
	print_message_error(error);
	return (error.code);
}
