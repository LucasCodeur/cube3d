/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20.25/11/14 15:13:52 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/02 18:00:27 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "matrice.h"
#include "vector.h"

#include <mlx.h>
#include <math.h>
#include <X11/keysym.h>

//WARN: have to take off
	#include "test.h"

static bool	rotate_hero(t_data *data, int keycode);

/**
* @brief allow to move inside the map and set different keyhook like aswd
* @param data contains all information necessary to the project.
* @param keycode, link keybind to an effect
* @return
*/
int move_hero(int keycode, t_data *data)
{
	if ((keycode == XK_s || keycode == XK_S) &&
		data->map.grid[(int)(data->map.player.pos.elements[1] - 0.25f * data->map.player.dir.elements[1])][(int)(data->map.player.pos.elements[0] - 0.5f * data->map.player.dir.elements[0])] == '0')
	{
		data->map.player.pos.elements[0] -= 0.25f * data->map.player.dir.elements[0];
		data->map.player.pos.elements[1] -= 0.25f * data->map.player.dir.elements[1];
		draw_map(data);
	}
	else if ((keycode == XK_w || keycode == XK_W) && 
		data->map.grid[(int)(data->map.player.pos.elements[1] + 0.25f * data->map.player.dir.elements[1])][(int)(data->map.player.pos.elements[0] + 0.5f * data->map.player.dir.elements[0])] == '0')
	{
		data->map.player.pos.elements[0] += 0.25f * data->map.player.dir.elements[0];
		data->map.player.pos.elements[1] += 0.25f * data->map.player.dir.elements[1];
		draw_map(data);
	}
	else if ((keycode == XK_q || keycode == XK_Q) && data->z < 500)
	{
		data->z += 50;
	}
	else if ((keycode == XK_e || keycode == XK_E) && data->z > -500)
	{
		data->z -= 50;
	}
	else
	{
		if (rotate_hero(data, keycode) == true)
			draw_map(data);
	}
	return (0);
}

/**
* @brief allow to rotate the hero according keycode
* @param data contains all information necessary to the project.
* @param keycode, link keybind to an effect
* @return
*/
static bool	rotate_hero(t_data *data, int keycode)
{
	if (keycode == XK_d || keycode == XK_D)
	{
		data->map.player.dir = rotate_vect(data->map.player.dir, ADD_SPEED);
		data->map.player.plane = rotate_vect(data->map.player.plane, ADD_SPEED);
		return (true);
	}
	else if (keycode == XK_a || keycode == XK_A)
	{
		data->map.player.dir = rotate_vect(data->map.player.dir, SUBT_SPEED);
		data->map.player.plane = rotate_vect(data->map.player.plane, SUBT_SPEED);
		return (true);
	}
	return (false);
}
