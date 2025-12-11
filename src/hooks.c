/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:13:52 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/10 14:34:57 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "display.h"

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include "matrice.h"

/**
* @brief allow to move inside the map and set asdw
* @param data contains all information necessary to the project.
* @param keycode, link keybind to an effect
* @return 0 if success
*/
int move_hero(int keycode, t_data *data)
{
	bool display = false;
	if ((keycode == XK_d || keycode == XK_D || keycode == XK_l || keycode == XK_L) && data->map.player.pos.elements[0] < data->map.cols - 2)
	{
		data->map.player.pos.elements[0] += 0.1f;
		display = true;
	}
	else if ((keycode == XK_a || keycode == XK_A || keycode == XK_h || keycode == XK_H) && data->map.player.pos.elements[0] > 1)
	{
		data->map.player.pos.elements[0] -= 0.1f;
		display = true;
	}
	else if ((keycode == XK_s || keycode == XK_S || keycode == XK_J || keycode == XK_j ) && data->map.player.pos.elements[1] < data->map.rows - 2)
	{
		data->map.player.pos.elements[1] += 0.1f;
		display = true;
	}
	else if ((keycode == XK_w || keycode == XK_W || keycode == XK_k || keycode == XK_K) && data->map.player.pos.elements[0] > 1)
	{
		data->map.player.pos.elements[1] -= 0.1f;
		display = true;
	}
	else if (keycode == XK_q || keycode == XK_Q || keycode == XK_Left)
	{
		data->map.player.dir.elements[0] = data->map.player.pos.elements[0] * cos(5) ;
		data->map.player.dir.elements[1] = data->map.player.pos.elements[1] * sin(5) ;
		display = true;
	}
	else if (keycode == XK_e || keycode == XK_E || keycode == XK_Right)
	{
		data->map.player.dir.elements[0] = data->map.player.pos.elements[0] * cos(-5) ;
		data->map.player.dir.elements[1] = data->map.player.pos.elements[1] * sin(-5) ;
		display = true;
	}
	if (display == true)
	{
		// update_maps(data);
		display_minimap(data);
	}
	return (0);
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
