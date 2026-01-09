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
#include <stdlib.h>

#include "display.h"

/**
* @brief allow to choose which texture according side and the direction of the ray
* @param all informatio about the program
* @return the texture to display
*/
void choose_texture(t_data *data, t_img **text)
{
	if (data->side == 0)
	{
		if (data->ray_dir.elements[0] >= 0)
			*text = data->imgs->wall_east;
		else
			*text = data->imgs->wall_west;
	}
	else
	{
		if (data->ray_dir.elements[1] >= 0)
			*text = data->imgs->wall_south;
		else
			*text = data->imgs->wall_north;
	}
}

/**
 * @brief function allows to create an image with an xpm.
 * @param data contains all information necessary to the project.
 * @param path_to_asset is the path to finding the asset to display.
 * @return img or exit in case of a problem.
 */
void	fill_image(t_data* data)
{
	data->imgs->wall_east->img = mlx_xpm_file_to_image(data->mlx.ptr, ASSET_W_EAST, &data->imgs->wall_east->width, &data->imgs->wall_east->height);
	if (!data->imgs->wall_east->img)
	{
		perror("Error: Image not create\n");
		// exit(1);
	}
	printf("height : %d, width : %d\n", data->imgs->wall_east->height, data->imgs->wall_east->width);
	data->imgs->wall_east->addr = mlx_get_data_addr(data->imgs->wall_east->img, &data->imgs->wall_east->bits_per_pixel, &data->imgs->wall_east->line_length, &data->imgs->wall_east->endian);
	if (!data->imgs->wall_east->addr)
	{
		perror("Error: addr not create\n");
		// exit(1);
	}
	data->imgs->wall_east->bits_per_pixel = data->imgs->wall_east->bits_per_pixel / 8;
	data->imgs->wall_north->img = mlx_xpm_file_to_image(data->mlx.ptr, ASSET_W_NORTH, &data->imgs->wall_north->width, &data->imgs->wall_north->height);
	if (!data->imgs->wall_north->img)
	{
		perror("Error: Image not create\n");
		// exit(1);
	}
	data->imgs->wall_north->addr = mlx_get_data_addr(data->imgs->wall_north->img, &data->imgs->wall_north->bits_per_pixel, &data->imgs->wall_north->line_length, &data->imgs->wall_north->endian);
	if (!data->imgs->wall_north->addr)
	{
		perror("Error: addr not create\n");
		// exit(1);
	}
	data->imgs->wall_north->bits_per_pixel = data->imgs->wall_north->bits_per_pixel / 8;
	data->imgs->wall_south->img = mlx_xpm_file_to_image(data->mlx.ptr, ASSET_W_SOUTH, &data->imgs->wall_south->width, &data->imgs->wall_south->height);
	if (!data->imgs->wall_south->img)
	{
		perror("Error: Image not create\n");
		// exit(1);
	}
	data->imgs->wall_south->addr = mlx_get_data_addr(data->imgs->wall_south->img, &data->imgs->wall_south->bits_per_pixel, &data->imgs->wall_south->line_length, &data->imgs->wall_south->endian);
	if (!data->imgs->wall_south->addr)
	{
		perror("Error: addr not create\n");
		// exit(1);
	}
	data->imgs->wall_south->bits_per_pixel = data->imgs->wall_south->bits_per_pixel / 8;
	data->imgs->wall_west->img = mlx_xpm_file_to_image(data->mlx.ptr, ASSET_W_WEST, &data->imgs->wall_west->width, &data->imgs->wall_west->height);
	if (!data->imgs->wall_west->img)
	{
		perror("Error: Image not create\n");
		// exit(1);
	}
	data->imgs->wall_west->addr = mlx_get_data_addr(data->imgs->wall_west->img, &data->imgs->wall_west->bits_per_pixel, &data->imgs->wall_west->line_length, &data->imgs->wall_west->endian);
	if (!data->imgs->wall_west->addr)
	{
		perror("Error: addr not create\n");
		// exit(1);
	}
	data->imgs->wall_west->bits_per_pixel = data->imgs->wall_west->bits_per_pixel / 8;
}

/**
* @brief allow to loads all textures
* @param data all information about the program
* @return
*/
void	load_imgs(t_data *data)
{
	data->imgs->wall_east = malloc(sizeof(t_img));
	data->imgs->wall_west = malloc(sizeof(t_img));
	data->imgs->wall_south = malloc(sizeof(t_img));
	data->imgs->wall_north = malloc(sizeof(t_img));
	data->imgs->wall_east->img = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	data->imgs->wall_west->img = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	data->imgs->wall_north->img = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	data->imgs->wall_south->img = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	fill_image(data);
}
