/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:27:25 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/20 16:37:52 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

#include "matrice.h"
#include "vector.h"

#include <mlx.h>
#include <X11/keysym.h>

static	void move_left_or_right(t_data *data, bool right);

/**
* @brief allow to deplace the hero
* @param data all information about the program
* @return
*/
void	move_hero(t_data *data)
{
	if (data->keycode.down == true && 
		data->map.grid[(int)(data->map.player.pos.elements[1] - SPEED * data->map.player.dir.elements[1])][(int)(data->map.player.pos.elements[0] - SPEED * data->map.player.dir.elements[0])] == '0')
	{
		data->map.player.pos.elements[0] -= SPEED * data->map.player.dir.elements[0];
		data->map.player.pos.elements[1] -= SPEED * data->map.player.dir.elements[1];
	}
	else if (data->keycode.up == true && 
		data->map.grid[(int)(data->map.player.pos.elements[1] + SPEED * data->map.player.dir.elements[1])][(int)(data->map.player.pos.elements[0] + SPEED * data->map.player.dir.elements[0])] == '0')	
	{
		data->map.player.pos.elements[0] += SPEED * data->map.player.dir.elements[0];
		data->map.player.pos.elements[1] += SPEED * data->map.player.dir.elements[1];
	}
	else if (data->keycode.left == true)
			move_left_or_right(data, false);
	else if (data->keycode.right == true)
			move_left_or_right(data, true);
}

/**
* @brief allow to deplace the hero on the sides
* @param data all information about the program
* @param right boolean if true move on the right 
* and if false move on the right
* @return
*/
static	void move_left_or_right(t_data *data, bool right)
{
	double side_x;
	double side_y;

	side_x = -data->map.player.dir.elements[1];
	side_y = data->map.player.dir.elements[0];
	if (right == true && data->map.grid[(int)(data->map.player.pos.elements[1] + data->map.player.plane.elements[1] * SPEED)][(int)(data->map.player.pos.elements[0] + data->map.player.plane.elements[0] * SPEED)] == '0')
	{
		data->map.player.pos.elements[0] += data->map.player.plane.elements[0] * SPEED;
		data->map.player.pos.elements[1] += data->map.player.plane.elements[1] * SPEED;
	}
	else if (right == false && data->map.grid[(int)(data->map.player.pos.elements[1] - data->map.player.plane.elements[1] * SPEED)][(int)(data->map.player.pos.elements[0] - data->map.player.plane.elements[0] * SPEED)] == '0')
	{
		data->map.player.pos.elements[0] -= data->map.player.plane.elements[0] * SPEED;
		data->map.player.pos.elements[1] -= data->map.player.plane.elements[1] * SPEED;
	}
}

/**
* @brief allow to rotate the player if boolean are true
* @param data all information about the program
* @return
*/
void	rotate_hero(t_data *data)
{
	if (data->keycode.rotate_left == true)
	{
		data->map.player.dir = rotate_vect(data->map.player.dir, SUBT_SPEED);
		data->map.player.plane = rotate_vect(data->map.player.plane, SUBT_SPEED);
		data->keycode.rotate_left = false;
	}
	else if (data->keycode.rotate_right == true)
	{
		data->map.player.dir = rotate_vect(data->map.player.dir, ADD_SPEED);
		data->map.player.plane = rotate_vect(data->map.player.plane, ADD_SPEED);
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
	int			delta_x;
	int			delta_y;

	delta_x = MIDDLE_SCREEN_X - x;
	delta_y = MIDDLE_SCREEN_Y - y;
	if (delta_y > 0 && data->raycasting.z < 800)
		data->raycasting.z += delta_y;
	if (delta_y < 0 && data->raycasting.z > -800)
		data->raycasting.z += delta_y;
	if (delta_x > 0)
		data->keycode.rotate_left = true;
	else if (delta_x < 0)
		data->keycode.rotate_right = true;
	mlx_mouse_move(data->mlx.ptr, data->mlx.win, MIDDLE_SCREEN_X, MIDDLE_SCREEN_Y);
	return (0); 
}
