/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20.25/11/14 15:13:52 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/12 15:28:40 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <mlx.h>
#include <stdlib.h>

// int	close_win(void *param)
// {
// 	t_mlx	*win;

// 	if (!param)
// 		return (1);
// 	win = (t_mlx *)param;
// 	return (0);
// }

int	close_win(t_data *data)
{
	// if (data->mlx.win)
	// 	mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	// if (data->mlx.ptr)
	// 	mlx_destroy_display(data->mlx.ptr);
	free_img(data);
	free_all(data);
	exit(EXIT_SUCCESS);
	return (1);
}
