/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:06:38 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/18 14:56:42 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "display.h"
#include "debug.h"
#include "test.h"

bool	ininitialize_values(t_data* data)
{
	ft_bzero(data, sizeof(t_data));
	data->mlx.max_height = WIN_HEIGHT;
	data->mlx.max_width = WIN_WIDTH;
	data->map.cols = SIZE_X;
	data->map.rows = SIZE_Y;
	data->map.player.pos = new_vector_2D(1.0f, 1.0f);
	if (!data->map.player.pos.elements)
		return (false);
	data->map.player.dir = new_vector_2D(1.0f, 0.0f);
	if (!data->map.player.dir.elements)
	{
		free(data->map.player.pos.elements);
		return (false);
	}
	data->map.player.plane = new_vector_2D(0.0f, 0.66f);
	if (!data->map.player.plane.elements)
	{
		free(data->map.player.pos.elements);
		free(data->map.player.dir.elements);
		return (false);
	}
	data->map.player.camera = new_vector_2D(0.0f, 0.0f);
	if (!data->map.player.camera.elements)
	{
		free(data->map.player.pos.elements);
		free(data->map.player.dir.elements);
		free(data->map.player.plane.elements);
		return (false);
	}
	return (true);
}

bool	free_mallocs(t_data *data)
{
	free(data->map.player.pos.elements);
	free(data->map.player.dir.elements);
	free(data->map.player.plane.elements);
	free(data->map.player.camera.elements);
	return (true);
}

int main(void)
{
	t_data	data;

	ininitialize_values(&data);
	print(data.map.player.dir);
	d_generate_map(&data);
	d_print_grid(data.map);
	launcher(&data);
	free_mallocs(&data);
	return (0);
}
