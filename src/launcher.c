/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:28:43 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/02 15:05:05 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

//WARN: have to take off
#include "test.h"

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

// enum test {
// 	TESt1,
// 	TEST2,
// 	TEST3,
// 	JUMP,
// 	INVENTORY
// 	TEST_MAX
// }

// static const keymap[TEST_MAX] = {
// 	[JUMP] = xk_left;
// 	[TEST2] = xk_right;
// 	[INVENTORY] = xk_e
// }

/*
* * @brief allows to launch the main program.
* * @param data structure contain all information about the program.
* * @return 
* */

// struct LivingEntity
// {
// 	int hp
// }
//
// struct Movement 
// {
//
// }
//
// struct Player
// {
// 	LivingEntity livingData;
// 	Movement	testMovement;
// 	t_vec2	pos;
// }
//
// void	test(Movement *entity)
// {
//
// }

void	launcher(t_data *data)
{
	// Player player;
	// test((Movement *)(&Player + sizeof(LivingEntity+3
	// )))
	// bool keys_status[TEST_MAX]
	// if (keys_status[JUMP])
	// 	jump();
	// if (keys_status[INVENTORY])
	// 	open_inventory
	init_screen_mlx(data);
	load_imgs(data);
	draw_map(data);
	t_display_map_2D(data);
	mlx_hook(data->mlx.win, KeyPress, KeyPressMask, move_hero, data);
	mlx_loop(data->mlx.ptr);
}
