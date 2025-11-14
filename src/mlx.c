/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:01:10 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/14 15:24:42 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

#include <stdlib.h>
#include <mlx.h>

void	init_screen_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		return ;
	mlx_get_screen_size(data->mlx.mlx, &data->mlx.max_width, &data->mlx.max_height);
	data->mlx.win = mlx_new_window(data->mlx.mlx, WIDTH, HEIGHT, "cube3D");
	if (!data->mlx.win || WIDTH > data->mlx.max_width || HEIGHT > data->mlx.max_height)
	{
		free_img(data);
		return ;
	}
	data->img.img = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	if (!data->img.img)
	{
		free_img(data);
		return ;
	}
}

void	free_img(t_data *data)
{
	if (!data)
		return ;
	if (data->img.img)
	{
		mlx_destroy_image(data->mlx.mlx, data->img.img);
		data->img.img = NULL;
	}
	if (data->img.addr)
		data->img.addr = NULL;
	if (data->mlx.win)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		data->mlx.win = NULL;
	}
	if (data->mlx.mlx)
	{
		mlx_destroy_display(data->mlx.mlx);
		free(data->mlx.mlx);
		data->mlx.mlx = NULL;
	}
}
