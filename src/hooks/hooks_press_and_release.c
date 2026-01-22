/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_press_and_release.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:43:33 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/22 17:03:35 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <X11/keysym.h>
#include <mlx.h>

static bool	handle_up_and_down(t_data *data, int keycode);

/**
 * @brief allow to handle the press of the keys
 * @param data all information about the program.
 * @param keycode is an int that represents a
 * touch of the keyboard in the mlx.
 * @return 0 if success
 */
int	press_move(int keycode, t_data *data)
{
	if (handle_up_and_down(data, keycode) == true)
		return (0);
	if (keycode == XK_d || keycode == XK_D)
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

/**
 * @brief allow to handle the release of the keys
 * @param data all information about the program.
 * @param keycode is an int that represents a
 * touch of the keyboard in the mlx.
 * @return 0 if success
 */
int	release_move(int keycode, t_data *data)
{
	if ((keycode == XK_s || keycode == XK_S) && data->keycode.down == true)
		data->keycode.down = false;
	else if ((keycode == XK_w || keycode == XK_W) && data->keycode.up == true)
		data->keycode.up = false;
	else if ((keycode == XK_d || keycode == XK_D)
		&& data->keycode.right == true)
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

static bool	handle_up(t_data *data, int keycode, int x, int y)
{
	if (keycode == XK_s || keycode == XK_S)
	{
		y = data->map.player.pos.elements[1] - SPEED
			* data->map.player.dir.elements[1];
		x = data->map.player.pos.elements[0] - 0.5f
			* data->map.player.dir.elements[0];
		if (data->map.grid[y][x] == '0')
			data->keycode.down = true;
		return (true);
	}
	return (false);
}

static bool	handle_down(t_data *data, int keycode, int x, int y)
{
	if (keycode == XK_w || keycode == XK_W)
	{
		y = (int)(data->map.player.pos.elements[1] + SPEED
				* data->map.player.dir.elements[1]);
		x = (int)(data->map.player.pos.elements[0] + 0.5f
				* data->map.player.dir.elements[0]);
		if (data->map.grid[y][x] == '0')
			data->keycode.up = true;
		return (true);
	}
	return (false);
}

/**
 * @brief allow to handle w and s
 * @param data all information about the program.
 * @param keycode is an int that represents a
 *  key of the keyboard inside the mlx.

	* @return true if the correspondent keycode inside
	the boolean structure or false
 */
static bool	handle_up_and_down(t_data *data, int keycode)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (handle_up(data, keycode, x, y))
		return (true);
	if (handle_down(data, keycode, x, y))
		return (true);
	return (false);
}
