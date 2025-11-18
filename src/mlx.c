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
	data->mlx.ptr = mlx_init();
	if (!data->mlx.ptr)
		return ;
	mlx_get_screen_size(data->mlx.ptr, &data->mlx.max_width, &data->mlx.max_height);
	data->mlx.win = mlx_new_window(data->mlx.ptr, WIDTH, HEIGHT, "cube3D");
	if (!data->mlx.win || WIDTH > data->mlx.max_width || HEIGHT > data->mlx.max_height)
	{
		free_img(data);
		return ;
	}
	data->img.img = mlx_new_image(data->mlx.ptr, WIDTH, HEIGHT);
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
		mlx_destroy_image(data->mlx.ptr, data->img.img);
		data->img.img = NULL;
	}
	if (data->img.addr)
		data->img.addr = NULL;
	if (data->mlx.win)
	{
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
		data->mlx.win = NULL;
	}
	if (data->mlx.ptr)
	{
		mlx_destroy_display(data->mlx.ptr);
		free(data->mlx.ptr);
		data->mlx.ptr = NULL;
	}
}
