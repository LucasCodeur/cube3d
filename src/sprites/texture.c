/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:55:13 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/26 12:28:46 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "error.h"
#include "parsing.h"
#include <mlx.h>

static t_error	fill_image(t_data *data, char *path_to_asset, t_img *img);

/**

	* @brief allow to choose which texture according
		side and the direction of the ray
	* @param all informatio about the program
	* @return the texture to display
	*/
void	choose_texture(t_data *data, t_img **text)
{
	if (data->raycasting.side == 0)
	{
		if (data->raycasting.ray_dir.elements[0] >= 0)
			*text = &data->imgs.wall_west;
		else
			*text = &data->imgs.wall_east;
	}
	else
	{
		if (data->raycasting.ray_dir.elements[1] >= 0)
			*text = &data->imgs.wall_north;
		else
			*text = &data->imgs.wall_south;
	}
}

/**
 * @brief allow to loads all textures
 * @param data all information about the program
 * @return
 */
t_error	load_imgs(t_data *data)
{
	t_error	error;

	error = fill_image(data, data->parsing->east_texture,
			&data->imgs.wall_east);
	if (error.code != ERR_OK)
		return (error);
	error = fill_image(data, data->parsing->west_texture,
			&data->imgs.wall_west);
	if (error.code != ERR_OK)
		return (error);
	error = fill_image(data, data->parsing->north_texture,
			&data->imgs.wall_north);
	if (error.code != ERR_OK)
		return (error);
	error = fill_image(data, data->parsing->south_texture,
			&data->imgs.wall_south);
	if (error.code != ERR_OK)
		return (error);
	return (error_ok());
}

/**
 * @brief function allows to create an image with an xpm.
 * @param data contains all information necessary to the project.
 * @param path_to_asset is the path to finding the asset to display.
 * @return img or exit in case of a problem.
 */
static t_error	fill_image(t_data *data, char *path_to_asset, t_img *img)
{
	t_error	error;

	img->img = mlx_xpm_file_to_image(data->mlx.ptr, path_to_asset, &img->width,
			&img->height);
	if (!img->img)
	{
		error.code = ERR_MLX;
		error.message = "mlx_xpm_file_to_image failed";
		return (error);
	}
	img->addr = (t_pixel *)(mlx_get_data_addr(img->img, &img->bits_per_pixel,
				&img->line_length, &img->endian));
	if (!img->addr)
	{
		error.code = ERR_MLX;
		error.message = "mlx_get_data_addr failed";
		return (error);
	}
	img->double_height = (double)img->height;
	img->pixels_per_line = img->line_length / sizeof(t_pixel);
	return (error_ok());
}
