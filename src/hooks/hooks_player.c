/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:27:25 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/21 21:05:27 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vector.h"

#include <X11/keysym.h>
#include <mlx.h>

static void	move_left_or_right(t_data *data, bool right);
static void handle_up(t_data *data);
static void handle_down(t_data *data);

/**
 * @brief allow to deplace the hero
 * @param data all information about the program
 * @return
 */
void	move_hero(t_data *data)
{
	if (data->keycode.down == true)
		handle_down(data);
	else if (data->keycode.up == true)
		handle_up(data);
	else if (data->keycode.left == true)
		move_left_or_right(data, false);
	else if (data->keycode.right == true)
		move_left_or_right(data, true);
}

/**
* @brief allow to handle down
* @param data all information about the program.
* @return
*/
static void handle_down(t_data *data)
{
	int		x;
	int		y;

	y = data->map.player.pos.elements[1] - SPEED * data->map.player.dir.elements[1];
	x = data->map.player.pos.elements[0] - 0.5f * data->map.player.dir.elements[0];
	if (data->map.grid[y][x] == '0')
	{
		data->map.player.pos.elements[0] -= SPEED
			* data->map.player.dir.elements[0];
		data->map.player.pos.elements[1] -= SPEED
			* data->map.player.dir.elements[1];
	}
}

/**
* @brief allow to handle up
* @param data all information about the program.
* @return
*/
static void handle_up(t_data *data)
{
	int		x;
	int		y;

	y = (int)(data->map.player.pos.elements[1] + SPEED * data->map.player.dir.elements[1]);
	x = (int)(data->map.player.pos.elements[0] + 0.5f * data->map.player.dir.elements[0]);	
	if (data->map.grid[y][x] == '0')
	{
		data->map.player.pos.elements[0] += SPEED
			* data->map.player.dir.elements[0];
		data->map.player.pos.elements[1] += SPEED
			* data->map.player.dir.elements[1];
	}
}

/**
 * @brief allow to deplace the hero on the sides
 * @param data all information about the program
 * @param right boolean if true move on the right
 * and if false move on the right
 * @return
 */
static void	move_left_or_right(t_data *data, bool right)
{
	if (right == true && data->map.grid[(int)(data->map.player.pos.elements[1]
			+ data->map.player.plane.elements[1]
			* SPEED)][(int)(data->map.player.pos.elements[0]
			+ data->map.player.plane.elements[0] * SPEED)] == '0')
	{
		data->map.player.pos.elements[0] += data->map.player.plane.elements[0]
			* SPEED;
		data->map.player.pos.elements[1] += data->map.player.plane.elements[1]
			* SPEED;
	}
	else if (right == false
		&& data->map.grid[(int)(data->map.player.pos.elements[1]
			- data->map.player.plane.elements[1]
			* SPEED)][(int)(data->map.player.pos.elements[0]
			- data->map.player.plane.elements[0] * SPEED)] == '0')
	{
		data->map.player.pos.elements[0] -= data->map.player.plane.elements[0]
			* SPEED;
		data->map.player.pos.elements[1] -= data->map.player.plane.elements[1]
			* SPEED;
	}
}
