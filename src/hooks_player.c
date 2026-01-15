/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:27:25 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/15 14:26:45 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "matrice.h"
#include "vector.h"

#include <mlx.h>
#include <X11/keysym.h>

int press_move(int keycode, t_data *data)
{
	if ((keycode == XK_s || keycode == XK_S) &&
		data->map.grid[(int)(data->map.player.pos.elements[1] - SPEED * data->map.player.dir.elements[1])][(int)(data->map.player.pos.elements[0] - 0.5f * data->map.player.dir.elements[0])] == '0')
		data->keycode.down = true;
	else if ((keycode == XK_w || keycode == XK_W) && 
		data->map.grid[(int)(data->map.player.pos.elements[1] + SPEED * data->map.player.dir.elements[1])][(int)(data->map.player.pos.elements[0] + 0.5f * data->map.player.dir.elements[0])] == '0')
		data->keycode.up = true;
	else if(keycode == XK_d || keycode == XK_D)
		data->keycode.right = true;
	else if (keycode == XK_a || keycode == XK_A)
		data->keycode.left = true;
	else if (keycode == XK_Left)
		data->keycode.rotate_left = true;
	else if (keycode == XK_Right)
		data->keycode.rotate_right = true;
	else if (keycode == XK_Escape)
		data->keycode.escape = true;
	return (0);
}

int release_move(int keycode, t_data *data)
{
	if ((keycode == XK_s || keycode == XK_S) && data->keycode.down == true)
		data->keycode.down = false;
	else if ((keycode == XK_w || keycode == XK_W) && data->keycode.up == true)	
		data->keycode.up = false;
	else if((keycode == XK_d || keycode == XK_D) && data->keycode.right == true)
		data->keycode.right = false;
	else if ((keycode == XK_a || keycode == XK_A) && data->keycode.left == true)
		data->keycode.left = false;
	else if (keycode == XK_Left && data->keycode.rotate_left == true)
		data->keycode.rotate_left = false;
	else if (keycode == XK_Right && data->keycode.rotate_right == true)
		data->keycode.rotate_right = false;
	else if (keycode == XK_Escape && data->keycode.escape == true)
		data->keycode.escape = false;
	return (0);
}

static	void move_left_or_right(t_data *data, int to_rotate);

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
			move_left_or_right(data, ROTATE_BACKWARD);
		else if (data->keycode.right == true)
			move_left_or_right(data, ROTATE_FORWARD);
	return (true);
}

static	void move_left_or_right(t_data *data, int to_rotate)
{
	t_vec dir_rotate;

	dir_rotate = rotate_vect(data->map.player.dir, to_rotate);
	if (data->map.grid[(int)(data->map.player.pos.elements[1] + SPEED * dir_rotate.elements[1])][(int)(data->map.player.pos.elements[0] + SPEED * dir_rotate.elements[0])] == '0')	
	{
		data->map.player.pos.elements[0] += SPEED * dir_rotate.elements[0];
		data->map.player.pos.elements[1] += SPEED * dir_rotate.elements[1];
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
