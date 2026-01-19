/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:59:23 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/19 15:05:32 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <mlx.h>

// return pixel color in (x,y)
unsigned int	get_pixel(t_img *img, int x, int y)
{
	t_pixel	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

void	put_pixel(t_img *img, int x, int y, unsigned int color)
{
	t_pixel	*pixel;

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
	t_img	wall_minimap;

	// t_img	wall32;
	// wall32.img = mlx_xpm_file_to_image(data->mlx.ptr, "./assets/wall.xpm",
	// 		&wall32.width, &wall32.height);
	// wall32.addr = (t_pixel *)mlx_get_data_addr(wall32.img,
	// 		&wall32.bits_per_pixel, &wall32.line_length, &wall32.endian);
	wall_minimap.img = mlx_xpm_file_to_image(data->mlx.ptr, "./assets/wall.xpm",
			&wall_minimap.width, &wall_minimap.height);
	wall_minimap.addr = (t_pixel *)mlx_get_data_addr(wall_minimap.img,
			&wall_minimap.bits_per_pixel, &wall_minimap.line_length,
			&wall_minimap.endian);
	// scale_image(&wall_minimap, &wall32);
	return (wall_minimap);
}
/*
color = 4 octets soit 32 bits
color = *(int *)(wall.addr + j * wall.line_length + i * 4);
wall.line_length = nombre d'octet pour une ligne entière
i * 4 correspond a i x 32 bits par pixel / 8 (bits par octets)

wall.addr =
*/
// static void	wall_to_map(t_img *wall, t_img *map, int x, int y)
// {
// 	int		j;
// 	int		i;
// 	int		minimap_x;
// 	int		minimap_y;
// 	t_pixel	color;

// 	// int				coef;
// 	j = 0;
// 	while (j < wall->height)
// 	{
// 		i = 0;
// 		while (i < wall->width)
// 		{
// 			minimap_x = x + i;
// 			minimap_y = y + j;
// 			if (minimap_x >= 0 && minimap_x < map->width * 32 && minimap_y >= 0
// 				&& minimap_y < map->height)
// 			{
// 				color = *(t_pixel *)((char *)wall->addr + j * wall->line_length
// 						+ i * 4);
// 				*(t_pixel *)((char *)map->addr + minimap_y * map->line_length
// 						+ minimap_x * 4) = color;
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// }

static void	wall_to_map(t_img *wall, t_img *map, int x, int y, char c)
{
	int		j;
	int		i;
	int		map_x;
	int		map_y;
	t_pixel	color;

	// int				coef;
	j = 0;
	while (j < wall->height)
	{
		i = 0;
		while (i < wall->width)
		{
			map_x = x + i;
			map_y = y + j;
			if (map_x >= 0 && map_x < map->width * 32 && map_y >= 0
				&& map_y < map->height * 32)
			{
				if (c == '1')
				{
					color = *(t_pixel *)((char *)wall->addr + j
							* wall->line_length + i * 4);
					*(t_pixel *)((char *)map->addr + map_y * map->line_length
							+ map_x * 4) = color;
				}
				else if (c == '0')
				{
					color.value = BLUE;
					*(t_pixel *)((char *)map->addr + map_y * map->line_length
							+ map_x * 4) = color;
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
	int		x;
	int		y;
	t_img	wall;

	wall = get_wall(data);
	// data->minimap.width = data->map.width * 32;
	// data->minimap.height = data->map.height * 32;
	// data->minimap.img = mlx_new_image(data->mlx.ptr, data->minimap.width,
	// 		data->minimap.height);
	// data->minimap.addr = (t_pixel *)mlx_get_data_addr(data->minimap.img,
	// 		&data->minimap.bits_per_pixel, &data->minimap.line_length,
	// 		&data->minimap.endian);
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			wall_to_map(&wall, &data->img, x * 32, y * 32,
				data->map.grid[y][x]);
			// if (data->map.grid[y][x] == '1')
			// {
			// 	wall_to_map(&wall, &data->img, x * 32, y * 32, );
			// }
			// if (data->map.grid[y][x] == '0')
			// {
			// 	color.value = BLUE;
			// 	// wall_to_map(&wall, &data->img, x * 32, y * 32);
			// }
			x++;
		}
		y++;
	}
	/*mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->minimap.img,
		0,
		0);*/
	return (0);
}
