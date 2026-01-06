/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:10:20 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/26 18:09:49 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>

/**
 * @brief function allows to create an image with an xpm.
 * @param data contains all information necessary to the project.
 * @param path_to_asset is the path to finding the asset to display.
 * @return img or exit in case of a problem.
 */
// NOTE: x and y is the size of my image.
// NOTE: mlx_xpm_file_to_image allow to read a file directly into a image object.
t_img	fill_frame(t_data* data, char *path_to_asset, int* x, int* y)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(data->mlx.ptr, path_to_asset, x, y);
	if (!img.ptr)
	{
		perror("Error: Image not create\n");
		exit(1);
	}	
	img.addr = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (!img.addr)
	{
		perror("Error: Image not create\n");
		exit(1);
	}
	return (img);
}
