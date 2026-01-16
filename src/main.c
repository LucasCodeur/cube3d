/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:03:49 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/16 11:07:14 by prigaudi         ###   ########.fr       */
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

static t_error	ininitialize_values(t_data *data)
{
	t_error	error;

	ft_bzero(data, sizeof(t_data));
	error = ft_malloc(&data->garbage, sizeof(t_parsing),
			(void **)&data->parsing);
	if (error.code != ERR_OK)
	{
		error.code = ERR_MEMORY;
	}
	ft_bzero(data->parsing, sizeof(t_parsing));
	data->mlx.max_height = WIN_HEIGHT;
	data->mlx.max_width = WIN_WIDTH;
	data->map.cols = SIZE_X;
	data->map.rows = SIZE_Y;
	data->map.player.pos = new_vector_2D(10.0f, 10.0f);
	data->map.player.dir = new_vector_2D(1.0f, 0.0f);
	data->map.player.plane = new_vector_2D(0.0f, 0.66f);
	data->map.player.camera = new_vector_2D(0.0f, 0.0f);
	return (ERROR_OK);
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
			close_win(data);
			// free_all(data);
			// exit(0);
		}
	}
	return (0);
}

void	launcher(t_data *data)
{
	init_screen_mlx(data);
	load_imgs(data);
	data->fps.last_time = get_time();
	mlx_hook(data->mlx.win, 17, 0, close_win, data);
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
	if (error.message)
		printf("%s\n", error.message);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_error	error;

	ininitialize_values(&data);
	error = parsing(argc, argv, &data);
	launcher(&data);
	free_all(&data);
	error.code = ERR_MLX;
	printf("exit code : %d\n", error.code);
	print_message_error(error);
	return (error.code);
}
