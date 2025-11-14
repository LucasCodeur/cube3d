/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:13:52 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/14 16:49:19 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

#include <mlx.h>
#include <stdlib.h>

/**
* @brief allow to move inside the map and set asdw
* @param data contains all information necessary to the project.
* @param keycode, link keybind to an effect
* @return 0 if success
*/
int key_hook_movements(t_data *data, int keycode)
{
    if (keycode == 119)
        data->hero_pos.y -= 1;
    else if (keycode == 115)
        data->hero_pos.y += 1;
    else if (keycode == 97)
        data->hero_pos.x -= 1;
    else if (keycode == 100)
		data->hero_pos.x += 1;
	// update_maps(data);
	display_minimap(data);
    return (0);
}

int	key_press(int keycode, void *param)
{
	t_mlx	*mlx;

	if (!param)
		return (0);
	mlx = (t_mlx *)param;
	if (keycode == 65307)
	{
		// free_img(mlx);
		exit(0);
	}
	return (0);
}

int	close_win(void *param)
{
	t_mlx	*win;

	if (!param)
		return (0);
	win = (t_mlx *)param;
	// free_img(win);
	exit(0);
}

void	hook_mandelbrot(t_data* data)
{
	mlx_hook(data->mlx.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data->mlx.win, 17, 0, close_win, &data);
	mlx_loop(data->mlx.win);
	key_hook_movements(data, int keycode);
	// free_img(&data);
}
