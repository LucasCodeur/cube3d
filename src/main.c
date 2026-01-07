/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:06:38 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/02 14:49:13 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "debug.h"
#include "test.h"

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

bool	ininitialize_values(t_data* data)
{
	ft_bzero(data, sizeof(t_data));
	data->mlx.max_height = WIN_HEIGHT;
	data->mlx.max_width = WIN_WIDTH;
	data->map.cols = SIZE_X;
	data->map.rows = SIZE_Y;
	data->map.player.pos = new_vector_2D(1.0f, 1.0f);
	data->map.player.dir = new_vector_2D(1.0f, 0.0f);
	data->map.player.plane = new_vector_2D(0.0f, 0.66f);
	data->map.player.camera = new_vector_2D(0.0f, 0.0f);
	return (true);
}

void	launcher(t_data *data)
{
	init_screen_mlx(data);
	load_imgs(data);
	draw_map(data);
	t_display_map_2D(data);
	mlx_hook(data->mlx.win, KeyPress, KeyPressMask, move_hero, data);
	mlx_loop(data->mlx.ptr);
}

int main(void)
{
	t_data	data;

	ininitialize_values(&data);
	d_generate_map(&data);
	launcher(&data);
	return (0);
}
