/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:03:49 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/19 15:20:24 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "display.h"
#include "error.h"
#include "matrice.h"
#include "parsing.h"
#include "test.h"
#include "vector.h"

#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include <sys/time.h>

static t_error	ininitialize_values(t_data *data)
{
	t_error	error;

	ft_bzero(data, sizeof(t_data));
	error = ft_malloc(&data->garbage, sizeof(t_parsing),
			(void **)&data->parsing);
	if (error.code != ERR_OK)
		return (error);
	ft_bzero(data->parsing, sizeof(t_parsing));
	data->mlx.max_height = WIN_HEIGHT;
	data->mlx.max_width = WIN_WIDTH;
	return (ERROR_OK);
}

static void	ininitialize_math_values(t_data *data)
{
	data->map.player.pos = new_vector_2D(data->map.player.x,
			data->map.player.y);
	if (data->map.player.orientation == 'N')
	{
		data->map.player.plane = new_vector_2D(0.66f, 0.0f);
		data->map.player.dir = new_vector_2D(0.0f, -1.0f);
	}
	else if (data->map.player.orientation == 'S')
	{
		data->map.player.plane = new_vector_2D(0.66f, 0.0f);
		data->map.player.dir = new_vector_2D(0.0f, 1.0f);
	}
	else if (data->map.player.orientation == 'E')
	{
		data->map.player.plane = new_vector_2D(0.0f, -0.66f);
		data->map.player.dir = new_vector_2D(1.0f, 0.0f);
	}
	else if (data->map.player.orientation == 'W')
	{
		data->map.player.plane = new_vector_2D(0.0f, 0.66f);
		data->map.player.dir = new_vector_2D(-1.0f, 0.0f);
	}
	data->map.player.camera = new_vector_2D(0.0f, 0.0f);
	data->map.grid[data->map.player.y][data->map.player.x] = '0';
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
		// display_minimap(data);
		count_fps(data);
		if (data->keycode.escape == true)
			destroy_free_exit(data);
	}
	return (0);
}

static t_error	launcher(t_data *data)
{
	t_error	error;

	ininitialize_math_values(data);
	error = init_screen_mlx(data);
	if (error.code != ERR_OK)
		return (error);
	error = load_imgs(data);
	if (error.code != ERR_OK)
		return (error);
	data->fps.last_time = get_time();
	mlx_hook(data->mlx.win, 17, 0, destroy_free_exit, data);
	mlx_hook(data->mlx.win, KeyPress, KeyPressMask, press_move, data);
	mlx_hook(data->mlx.win, KeyRelease, KeyReleaseMask, release_move, data);
	mlx_loop_hook(data->mlx.ptr, execute, data);
	mlx_loop(data->mlx.ptr);
	return (ERROR_OK);
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

	error = ininitialize_values(&data);
	if (error.code != ERR_OK)
	{
		print_message_error(error);
		destroy_free_exit(&data);
	}
	error = parsing(argc, argv, &data);
	if (error.code != ERR_OK)
	{
		print_message_error(error);
		destroy_free_exit(&data);
	}
	error = launcher(&data);
	if (error.code != ERR_OK)
	{
		print_message_error(error);
		destroy_free_exit(&data);
	}
	return (error.code);
}
