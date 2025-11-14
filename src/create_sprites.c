/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:10:20 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/14 11:48:40 by lud-adam         ###   ########.fr       */
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
t_img	fill_image(t_data* data, char *path_to_asset)
{
	t_img	img;
	int		x;
	int		y;

	img.img = mlx_xpm_file_to_image(data->mlx.mlx, path_to_asset, &x, &y);
	if (!img.img)
	{
		perror("Error: Image not create\n");
		exit(1);
	}
	return (img);
}
