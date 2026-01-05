/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:13:52 by lud-adam          #+#    #+#             */
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

/**
* @brief allow to move inside the map and set different keyhook like aswd
* @param data contains all information necessary to the project.
* @param keycode, link keybind to an effect
* @return 0 if success
*/
int move_hero(int keycode, t_data *data)
{
	if (keycode == XK_d || keycode == XK_D || keycode == XK_l || keycode == XK_L)
	{
		data->map.player.dir = rotate_vect(data->map.player.dir, 10.0 * (M_PI / 180));
		data->map.player.plane = rotate_vect(data->map.player.plane, 10.0 * (M_PI / 180));
	}
	else if (keycode == XK_a || keycode == XK_A || keycode == XK_h || keycode == XK_H)
	{
		data->map.player.dir = rotate_vect(data->map.player.dir, -10.0 * (M_PI / 180));
		data->map.player.plane = rotate_vect(data->map.player.plane, -10.0 * (M_PI / 180));
	}
	else if ((keycode == XK_s || keycode == XK_S || keycode == XK_J || keycode == XK_j) &&
		data->map.grid[(int)(data->map.player.pos.elements[1] - 0.5f * data->map.player.dir.elements[1])][(int)(data->map.player.pos.elements[0] - 0.5f * data->map.player.dir.elements[0])] == '0')
	{
		data->map.player.pos.elements[0] -= 0.5f * data->map.player.dir.elements[0];
		data->map.player.pos.elements[1] -= 0.5f * data->map.player.dir.elements[1];
	}
	else if ((keycode == XK_w || keycode == XK_W || keycode == XK_k || keycode == XK_K) && 
		data->map.grid[(int)(data->map.player.pos.elements[1] + 0.5f * data->map.player.dir.elements[1])][(int)(data->map.player.pos.elements[0] + 0.5f * data->map.player.dir.elements[0])] == '0')
	{
		data->map.player.pos.elements[0] += 0.5f * data->map.player.dir.elements[0];
		data->map.player.pos.elements[1] += 0.5f * data->map.player.dir.elements[1];
	}
	//WARN: have to change
	draw_map(data);
	t_display_map_2D(data);
	return (true);
}

// int	key_press(int keycode, void *param)
// {
// 	t_mlx	*mlx;
//
// 	if (!param)
// 		return (0);
// 	mlx = (t_mlx *)param;
// 	if (keycode == 65307)
// 	{
// 		free_img(mlx);
// 		exit(0);
// 	}
// 	return (0);
// }

// int	close_win(void *param)
// {
// 	t_mlx	*win;
//
// 	if (!param)
// 		return (0);
// 	win = (t_mlx *)param;
// 	// free_img(win);
// 	exit(0);
// }
