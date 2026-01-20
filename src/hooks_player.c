/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:27:25 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/20 09:57:00 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

#include "matrice.h"
#include "vector.h"

#include <mlx.h>
#include <X11/keysym.h>

static	void move_left_or_right(t_data *data, double to_rotate);

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
	{
		if (data->map.player.dir.elements[0] != -1 && data->map.player.dir.elements[1] != 0)
		{
			move_left_or_right(data, ROTATE_BACKWARD);
			printf("backward\n");
		}
		else
		{
			printf("forward\n");
			move_left_or_right(data, ROTATE_FORWARD);
		}
	}
	else if (data->keycode.right == true)
	{
		if (data->map.player.dir.elements[0] != 0 && data->map.player.dir.elements[1] != -1)
		{
			printf("forward\n");
			move_left_or_right(data, ROTATE_FORWARD);
		}
		else
		{
			printf("backward\n");
			move_left_or_right(data, ROTATE_BACKWARD);
		}
	}
	return (true);
}

static	void move_left_or_right(t_data *data, double to_rotate)
{
	t_vec dir_rotate;

	dir_rotate = rotate_vect(data->map.player.dir, to_rotate);
	if (data->map.grid[(int)(data->map.player.pos.elements[1] + SPEED * dir_rotate.elements[1])][(int)(data->map.player.pos.elements[0] + SPEED * dir_rotate.elements[0])] == '0')	
	{
		data->map.player.pos.elements[0] += SPEED * dir_rotate.elements[0];
		data->map.player.pos.elements[1] += SPEED * dir_rotate.elements[1];
	}
	else
		return ;
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
