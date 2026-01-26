/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:26:12 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/26 10:54:23 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "error.h"
#include "parsing.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include <sys/time.h>

int			execute(t_data *data);
static void	ininitialize_compute(t_compute *cube);
static void	ininitialize_math_values(t_data *data);

/**
 * @brief allow to launch the main algorithm of the program
 * @param data all information about the program.
 * @return error ok if success
 */
t_error	launcher(t_data *data)
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
	mlx_hook(data->mlx.win, MotionNotify, PointerMotionMask, mouse_hook, data);
	mlx_loop_hook(data->mlx.ptr, execute, data);
	mlx_loop(data->mlx.ptr);
	return (error_ok());
}

/**
 * @brief function that execute the different function to display
 * maps and handle the movements
 * @param data all information about the program.
 * @return 0 if success
 */
int	execute(t_data *data)
{
	data->fps.current_time = get_time();
	data->fps.delta_time = data->fps.current_time - data->fps.last_time;
	if (data->fps.delta_time >= data->cube.frame_duration)
	{
		data->fps.count_frame++;
		move_hero(data);
		if (data->keycode.escape == true)
			destroy_free_exit(data);
		rotate_hero(data);
		draw_map(data);
		draw_minimap(data);
		data->fps.last_time = data->fps.current_time;
	}
	return (0);
}

/**
 * @brief ininitialize all values of maths to do the raycasting
 * @param data all information about the program.
 * @return
 */
static void	ininitialize_math_values(t_data *data)
{
	data->map.player.pos = new_vector_2d(data->map.player.x + 0.01 + HITBOX,
			data->map.player.y + HITBOX + 0.01);
	if (data->map.player.orientation == 'N')
	{
		data->map.player.plane = new_vector_2d(0.66f, 0.0f);
		data->map.player.dir = new_vector_2d(0.0f, -1.0f);
	}
	else if (data->map.player.orientation == 'S')
	{
		data->map.player.plane = new_vector_2d(-0.66f, 0.0f);
		data->map.player.dir = new_vector_2d(0.0f, 1.0f);
	}
	else if (data->map.player.orientation == 'E')
	{
		data->map.player.plane = new_vector_2d(0.0f, 0.66f);
		data->map.player.dir = new_vector_2d(1.0f, 0.0f);
	}
	else if (data->map.player.orientation == 'W')
	{
		data->map.player.plane = new_vector_2d(0.0f, -0.66f);
		data->map.player.dir = new_vector_2d(-1.0f, 0.0f);
	}
	data->map.player.camera = new_vector_2d(0.0f, 0.0f);
	data->map.grid[data->map.player.y][data->map.player.x] = '0';
	ininitialize_compute(&data->cube);
}

/**
 * @brief ininitialize all computes of maths to do the raycasting
 * @param cube structure to stock all precompute of different formulas
 * @return
 */
static void	ininitialize_compute(t_compute *cube)
{
	cube->add_speed = 5.0 * (M_PI / 180);
	cube->subt_speed = -5.0 * (M_PI / 180);
	cube->middle_screen_x = WIN_WIDTH / 2;
	cube->middle_screen_y = WIN_HEIGHT / 2;
	cube->frame_duration = 1.0 / FPS;
}
