/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:59:23 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/09 10:54:09 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <mlx.h>

// return pixel color in (x,y)
unsigned int	get_pixel(t_img *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

void	put_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	scale_image(t_img *dst, t_img *src)
{
	int	x;
	int	y;
	int	src_x;
	int	src_y;

	y = 0;
	while (y < dst->height)
	{
		x = 0;
		while (x < dst->width)
		{
			src_x = x * src->width / dst->width;
			src_y = y * src->height / dst->height;
			put_pixel(dst, x, y, get_pixel(src, src_x, src_y));
			x++;
		}
		y++;
	}
}
// Create sprite 8x8 with image 32x32
static t_img	get_wall(t_data *data)
{
	t_img	wall32;
	t_img	wall_minimap;

	wall32.img = mlx_xpm_file_to_image(data->mlx.ptr, "./assets/wall.xpm",
			&wall32.width, &wall32.height);
	wall32.addr = mlx_get_data_addr(wall32.img, &wall32.bits_per_pixel,
			&wall32.line_length, &wall32.endian);
	wall_minimap.img = mlx_xpm_file_to_image(data->mlx.ptr, "./assets/wall.xpm",
			&wall_minimap.width, &wall_minimap.height);
	wall_minimap.addr = mlx_get_data_addr(wall_minimap.img,
			&wall_minimap.bits_per_pixel, &wall_minimap.line_length,
			&wall_minimap.endian);
	scale_image(&wall_minimap, &wall32);
	return (wall_minimap);
}

static void	wall_to_map(t_data *data, t_img wall, t_img *map, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;
	int				map_x;
	int				map_y;

	// int				coef;
	j = 0;
	while (j < wall.height)
	{
		i = 0;
		while (i < wall.width)
		{
			map_x = x + i;
			map_y = y + j;
			if (map_x >= 0 && map_x < (data->map.width) * 32 && map_y >= 0
				&& map_y < (data->map.height) * 32)
			{
				color = *(int *)(wall.addr + j * wall.line_length + i * 4);
				if (color != 0xFF000000)
				{
					*(int *)(map->addr + map_y * map->line_length + map_x
							* 4) = color;
				}
			}
			i++;
		}
		j++;
	}
}

// wall = 8 * 8px
int	display_minimap(t_data *data)
{
	t_img	minimap;
	t_img	wall;
	int		x;
	int		y;

	wall = get_wall(data);
	minimap.img = mlx_new_image(data->mlx.ptr, 500, 300);
	minimap.addr = mlx_get_data_addr(minimap.img, &minimap.bits_per_pixel,
			&minimap.line_length, &minimap.endian);
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.grid[y][x] == '1')
			{
				wall_to_map(data, wall, &minimap, x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, minimap.img, 0, 0);
	return (0);
}
