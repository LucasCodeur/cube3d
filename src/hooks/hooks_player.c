/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:27:25 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/26 10:37:35 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "lmath.h"

#include <X11/keysym.h>
#include <mlx.h>

static void	move_left_or_right(t_data *data, bool right);
static void	handle_up(t_data *data);
static void	handle_down(t_data *data);

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
 * @brief allow to handle up
 * @param data all information about the program.
 * @param map_x x of the player on the map
 * @param map_y y of the player on the map
 * @return
 */
static void	handle_up(t_data *data)
{
	double	dx;
	double	dy;
	double	px;
	double	py;

	px = data->map.player.pos.elements[0];
	py = data->map.player.pos.elements[1];
	dx = SPEED * data->map.player.dir.elements[0];
	dy = SPEED * data->map.player.dir.elements[1];
	if (dx > 0 && data->map.grid[(int)py][(int)(px + dx + HITBOX)] == '0')
		px += dx;
	else if (dx < 0 && data->map.grid[(int)(py)][(int)(px + dx - HITBOX)] == '0')
		px += dx;
	if (dy > 0 && data->map.grid[(int)(py + dy + HITBOX)][(int)px] == '0')
		py += dy;
	else if (dy < 0 && data->map.grid[(int)(py + dy - HITBOX)][(int)px] == '0')
		py += dy;
	data->map.player.pos.elements[0] = px;
	data->map.player.pos.elements[1] = py;
}

/**
 * @brief allow to handle up
 * @param data all information about the program.
 * @param map_x x of the player on the map
 * @param map_y y of the player on the map
 * @return
 */
static void	handle_down(t_data *data)
{
	double	dx;
	double	dy;
	double	px;
	double	py;

	px = data->map.player.pos.elements[0];
	py = data->map.player.pos.elements[1];
	dx = SPEED * data->map.player.dir.elements[0];
	dy = SPEED * data->map.player.dir.elements[1];
	if (dx > 0 && data->map.grid[(int)py][(int)(px - dx - HITBOX)] == '0')
		px -= dx;
	else if (dx < 0 && data->map.grid[(int)(py)][(int)(px - dx - -HITBOX)] == '0')
		px -= dx;
	if (dy > 0 && data->map.grid[(int)(py - dy - HITBOX)][(int)px] == '0')
		py -= dy;
	else if (dy < 0 && data->map.grid[(int)(py - dy - -HITBOX)][(int)px] == '0')
		py -= dy;
	data->map.player.pos.elements[0] = px;
	data->map.player.pos.elements[1] = py;
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
