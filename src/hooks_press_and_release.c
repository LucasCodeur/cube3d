/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_press_and_release.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:43:33 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/20 09:45:11 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

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
