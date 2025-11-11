/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:01:10 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/11 20:16:03 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_custom.h"

#include <stdlib.h>

void	free_img(t_mlx *data)
{
	if (!data)
		return ;
	if (data->img.img)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = NULL;
	}
	if (data->img.addr)
		data->img.addr = NULL;
	if (data->mlx_win)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		data->mlx_win = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

void	init_screen_mlx(t_mlx *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return ;
	mlx_get_screen_size(data->mlx, &data->max_width, &data->max_height);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cube3D");
	if (!data->mlx_win || WIDTH > data->max_width || HEIGHT > data->max_height)
	{
		free_img(data);
		return ;
	}
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.img)
	{
		free_img(data);
		return ;
	}
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	if (!data->img.addr)
	{
		free_img(data);
		return ;
	}
}
