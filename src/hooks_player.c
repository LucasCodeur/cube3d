/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:27:25 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/20 11:47:04 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

#include "matrice.h"
#include "vector.h"

#include <mlx.h>
#include <X11/keysym.h>

static	void move_left_or_right(t_data *data, bool right);

bool	move_hero(t_data *data)
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
	return (true);
}

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

bool	rotate_hero(t_data *data)
{
	if (data->keycode.rotate_left == true)
	{
		data->map.player.dir = rotate_vect(data->map.player.dir, SUBT_SPEED);
		data->map.player.plane = rotate_vect(data->map.player.plane, SUBT_SPEED);
	}
	else if (data->keycode.rotate_right == true)
	{
		data->map.player.dir = rotate_vect(data->map.player.dir, ADD_SPEED);
		data->map.player.plane = rotate_vect(data->map.player.plane, ADD_SPEED);
	}
	return (true);
}
