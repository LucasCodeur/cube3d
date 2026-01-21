/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:01:10 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/21 15:00:41 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <mlx.h>

static void	init_windows_and_image(t_data *data, t_error *error);

/**
* @brief allow to init the mlx
* @param data contains all information necessary to the project.
* @return error mlx if there is a problem or ok if success
*/
t_error	init_screen_mlx(t_data *data)
{
	t_error	error;

	data->mlx.ptr = mlx_init();
	if (!data->mlx.ptr)
	{
		error.code = ERR_MLX;
		error.message = "mlx_init failed";
		return (error);
	}
	mlx_get_screen_size(data->mlx.ptr, &data->mlx.max_width,
		&data->mlx.max_height);
	if ((WIN_WIDTH > data->mlx.max_width) || (WIN_HEIGHT > data->mlx.max_height)
		|| WIN_WIDTH < 100 || WIN_HEIGHT < 100)
	{
		error.code = ERR_MLX;
		error.message = "size of screen isn't correct";
		return (error);
	}
	init_windows_and_image(data, &error);
	if (error.code == ERR_MLX)
		return (error);
	data->img.pixels_per_line = data->img.line_length / sizeof(t_pixel);
	return (ERROR_OK);
}

/**
* @brief allow to init the windows and he image
* @param data contains all information necessary to the project.
* @return 
*/
static void	init_windows_and_image(t_data *data, t_error *error)
{
	data->mlx.win = mlx_new_window(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT,
			"cube3D");
	if (!data->mlx.win || WIN_WIDTH > data->mlx.max_width
		|| WIN_HEIGHT > data->mlx.max_height)
	{
		error->code = ERR_MLX;
		error->message = "mlx_new_window failed";
		return ;
	}
	data->img.img = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.img)
	{
		error->code = ERR_MLX;
		error->message = "mlx_new_image failed";
		return ;
	}
	data->img.addr = (t_pixel *)mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	if (!data->img.addr)
	{
		error->code = ERR_MLX;
		error->message = "mlx_get_data_addr failed";
	}
}
