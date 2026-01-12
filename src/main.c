/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:16 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/12 17:03:10 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "parsing.h"
#include "debug.h"
#include "test.h"
#include "matrice.h"

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <sys/time.h>

bool	ininitialize_values(t_data *data, t_parsing *parsing_data)
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
	return (true);
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
	}
	return (0);
}

void	launcher(t_data *data)
{
	init_screen_mlx(data);
	load_imgs(data);
	data->fps.last_time = get_time();
	mlx_hook(data->mlx.win, 17, 0, close_win, &data);
	mlx_hook(data->mlx.win, KeyPress, KeyPressMask, press_move, data);
	mlx_hook(data->mlx.win, KeyRelease, KeyReleaseMask, release_move, data);
	mlx_loop_hook(data->mlx.ptr, execute, data);
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
	free_img(&data);
	// mlx_destroy_image(data.mlx.ptr, data.imgs.wall_east.img);
	// mlx_destroy_image(data.mlx.ptr, data.imgs.wall_west.img);
	// mlx_destroy_image(data.mlx.ptr, data.imgs.wall_north.img);
	// mlx_destroy_image(data.mlx.ptr, data.imgs.wall_south.img);
	return (0);
}
