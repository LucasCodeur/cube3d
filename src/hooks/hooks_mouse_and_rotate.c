/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mouse_and_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:53:44 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/21 20:57:22 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "lmath.h"

#include <X11/keysym.h>
#include <mlx.h>

/**
 * @brief allow to rotate the player if boolean are true
 * @param data all information about the program
 * @return
 */
void	rotate_hero(t_data *data)
{
	if (data->keycode.rotate_left == true)
	{
		data->map.player.dir = rotate_vect(data->map.player.dir,
				data->cube.subt_speed);
		data->map.player.plane = rotate_vect(data->map.player.plane,
				data->cube.subt_speed);
		data->keycode.rotate_left = false;
	}
	else if (data->keycode.rotate_right == true)
	{
		data->map.player.dir = rotate_vect(data->map.player.dir,
				data->cube.add_speed);
		data->map.player.plane = rotate_vect(data->map.player.plane,
				data->cube.add_speed);
		data->keycode.rotate_right = false;
	}
}

/**
 * @brief allow to move the camera with the mouse
 * @param x abscisse of the mouse
 * @param y ordinate of the mouse
 * @param data all information about the program
 * @return 0 if success
 */
int	mouse_hook(int x, int y, t_data *data)
{
	int	delta_x;
	int	delta_y;

	delta_x = data->cube.middle_screen_x - x;
	delta_y = data->cube.middle_screen_y - y;
	if (delta_y > 0 && data->raycasting.z < 800)
		data->raycasting.z += delta_y;
	if (delta_y < 0 && data->raycasting.z > -800)
		data->raycasting.z += delta_y;
	if (delta_x > 0)
		data->keycode.rotate_left = true;
	else if (delta_x < 0)
		data->keycode.rotate_right = true;
	mlx_mouse_move(data->mlx.ptr, data->mlx.win, data->cube.middle_screen_x,
		data->cube.middle_screen_y);
	return (0);
}
