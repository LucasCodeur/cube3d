/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 09:38:14 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/07 16:22:32 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mlx_hook_loop(t_data *data)
{
	// mlx_key_hook(data->win_ptr, button_press, data);
	// mlx_hook(data->win_ptr, 17, 0, exit_prog, data);
	mlx_loop(data->mlx_ptr);
}

// Multiplicate by 32 because of sprite size
/*
bpp	bits par pixel
line_len	octets par ligne
endian	ordre des octets
*/
int	mlx_init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		printf("Problem with mlx_init\n");
		return (1);
	}
	// data->win_ptr = mlx_new_window(data->mlx_ptr, (data->map->width) * 32,
	// 		(data->map->height) * 32, "CUB3D");
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1800, 1600, "CUB3D");
	if (!data->win_ptr)
	{
		printf("Problem with mlx_new_windows\n");
		return (1);
	}
	return (0);
}
