/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:06:40 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/27 17:28:26 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <mlx.h>

#include "display.h"

/**
 * @brief function allows to create an image with an xpm.
 * @param data contains all information necessary to the project.
 * @param path_to_asset is the path to finding the asset to display.
 * @return img or exit in case of a problem.
 */
// NOTE: mlx_xpm_file_to_image allow to read a file directly into a image object.
t_img	fill_image(t_data* data, char *path_to_asset)
{
	t_img	img;
	int		x;
	int		y;

	// if (img.img)
	// 	free(img.img);
	img.ptr = mlx_xpm_file_to_image(data->mlx.ptr, path_to_asset, &x, &y);
	if (!img.ptr)
	{
		perror("Error: Image not create\n");
		// exit(1);
	}
	img.addr = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (!img.addr)
	{
		perror("Error: addr not create\n");
		// exit(1);
	}
	return (img);
}

void	load_imgs(t_data *data)
{
	data->imgs.wall_east.ptr = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	data->imgs.wall_west.ptr = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	data->imgs.wall_north.ptr = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	data->imgs.wall_south.ptr = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	data->imgs.ground.ptr = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);

	data->imgs.ground = fill_image(data, ASSET_TILE);
	data->imgs.wall_east = fill_image(data, ASSET_W_EAST);
	data->imgs.wall_west = fill_image(data, ASSET_W_WEST);
	data->imgs.wall_north = fill_image(data, ASSET_W_NORTH);
	data->imgs.wall_south = fill_image(data, ASSET_W_SOUTH);
}

/**
* @brief allow to display the map
* @param data contains all information necessary to the project.
* @return true if success
*/
bool	draw_map(t_data* data)
{
	int x;
	int	draw_start;
	int	draw_end;
	
	x = 0;
	clear_img(&data->img);
	while (x < WIN_WIDTH)
	{
		data->map.player.camera = define_percentage_of_fov(x);
		data->ray_dir = define_ray(data);
		compute_height_of_line(data, &draw_start, &draw_end);	
		draw_line(data, draw_start, draw_end, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.ptr, 0, 0);
	return (true);
}
