/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:55:13 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/06 19:56:53 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <mlx.h>

#include "display.h"

/**
* @brief allow to choose which texture according side and the direction of the ray
* @param all informatio about the program
* @return the texture to display
*/
void choose_texture(t_data *data, t_img *text)
{
	if (data->side == 0)
	{
		if (data->ray_dir.elements[0] >= 0)
			text = &data->imgs.wall_east;
		else
			text = &data->imgs.wall_west;
	}
	else
	{
		if (data->ray_dir.elements[1] >= 0)
			text = &data->imgs.wall_south;
		else
			text = &data->imgs.wall_north;
	}
}

/**
 * @brief function allows to create an image with an xpm.
 * @param data contains all information necessary to the project.
 * @param path_to_asset is the path to finding the asset to display.
 * @return img or exit in case of a problem.
 */
t_img	fill_image(t_data* data, char *path_to_asset)
{
	t_img	img;

	// if (img.img)
	// 	free(img.img);
	img.img = mlx_xpm_file_to_image(data->mlx.ptr, path_to_asset, &img.width, &img.height);
	if (!img.img)
	{
		perror("Error: Image not create\n");
		// exit(1);
	}
	img.addr = (t_pixel *)(mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian));
	if (!img.addr)
	{
		perror("Error: addr not create\n");
		// exit(1);
	}
	img.bits_per_pixel = img.bits_per_pixel / 8;
	img.double_height = (double)img.height;
	img.pixels_per_line = img.line_length / sizeof(t_pixel);
	return (img);
}

/**
* @brief allow to loads all textures
* @param data all information about the program
* @return
*/
void	load_imgs(t_data *data)
{
	data->imgs.wall_east.img = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	data->imgs.wall_west.img = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	data->imgs.wall_north.img = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	data->imgs.wall_south.img = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);

	data->imgs.wall_east = fill_image(data, ASSET_W_EAST);
	data->imgs.wall_west = fill_image(data, ASSET_W_WEST);
	data->imgs.wall_north = fill_image(data, ASSET_W_NORTH);
	data->imgs.wall_south = fill_image(data, ASSET_W_SOUTH);
}
