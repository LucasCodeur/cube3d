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

void	load_imgs(t_data *data);

/**
* @brief allow to init the mlx
* @param data contains all information necessary to the project.
* @return
*/
void	init_screen_mlx(t_data *data)
{
	data->mlx.ptr = mlx_init();
	if (!data->mlx.ptr)
		return ;
	mlx_get_screen_size(data->mlx.ptr, &data->mlx.max_width, &data->mlx.max_height);
	data->mlx.win = mlx_new_window(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "cube3D");
	if (!data->mlx.win || WIN_WIDTH > data->mlx.max_width || WIN_HEIGHT > data->mlx.max_height)
	{
		perror("mlx win:");
		free_img(data);
		exit(1);
	}
	data->img.ptr = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.ptr)
	{
		perror("mlx img ptr:");
		free_img(data);
		exit(1);
	}
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	if (!data->img.addr)
	{
		perror("mlx img addr:");
		free_img(data);
		exit(1);
	}
}

/**
* @brief allow to free the different composants of the mlx
* @param data contains all information necessary to the project.
* @return
*/
void	free_img(t_data *data)
{
	if (!data)
		return ;
	if (data->img.ptr)
	{
		mlx_destroy_image(data->mlx.ptr, data->img.ptr);
		data->img.ptr = NULL;
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
