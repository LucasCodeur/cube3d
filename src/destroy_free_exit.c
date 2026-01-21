/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_free_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:09:35 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/21 14:55:22 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <mlx.h>

static void	free_textures_ea_we(t_data *data)
{
	(void)data;
	if (data->imgs.wall_east.img)
	{
		mlx_destroy_image(data->mlx.ptr, data->imgs.wall_east.img);
		data->imgs.wall_east.img = NULL;
	}
	if (data->imgs.wall_east.addr)
		data->imgs.wall_east.addr = NULL;
	if (data->imgs.wall_west.img)
	{
		mlx_destroy_image(data->mlx.ptr, data->imgs.wall_west.img);
		data->imgs.wall_west.img = NULL;
	}
	if (data->imgs.wall_west.addr)
		data->imgs.wall_west.addr = NULL;
}

static void	free_textures_no_so(t_data *data)
{
	(void)data;
	if (data->imgs.wall_north.img)
	{
		mlx_destroy_image(data->mlx.ptr, data->imgs.wall_north.img);
		data->imgs.wall_north.img = NULL;
	}
	if (data->imgs.wall_north.addr)
		data->imgs.wall_north.addr = NULL;
	if (data->imgs.wall_south.img)
	{
		mlx_destroy_image(data->mlx.ptr, data->imgs.wall_south.img);
		data->imgs.wall_south.img = NULL;
	}
	if (data->imgs.wall_south.addr)
		data->imgs.wall_south.addr = NULL;
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
	if (data->img.img)
	{
		mlx_destroy_image(data->mlx.ptr, data->img.img);
		data->img.img = NULL;
	}
	if (data->img.addr)
		data->img.addr = NULL;
	free_textures_no_so(data);
	free_textures_ea_we(data);
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

static void	free_all(t_data *data)
{
	t_garbage	*tamp;

	if (data)
	{
		while (data->garbage)
		{
			free(data->garbage->ptr);
			tamp = data->garbage;
			data->garbage = data->garbage->next;
			free(tamp);
		}
		data->garbage = NULL;
	}
	return ;
}

int	destroy_free_exit(t_data *data)
{
	free_img(data);
	free_all(data);
	exit(EXIT_SUCCESS);
	return (1);
}
