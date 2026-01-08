/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:59:23 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/08 09:54:18 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// return pixel color in (x,y)
unsigned int	get_pixel(t_img *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)pixel);
}

void	put_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
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
static t_img	*get_wall(t_data *data)
{
	t_img	*wall32;
	t_img	*wall8;

	wall32->img = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/wall.xpm",
			&wall32->width, &wall32->height);
	wall32->addr = mlx_get_data_addr(wall32->img, &wall32->bpp,
			&wall32->line_len, &wall32->endian);
	wall8->img = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/wall.xpm",
			&wall8->width, &wall8->height);
	wall8->addr = mlx_get_data_addr(wall8->img, &wall8->bpp, &wall8->line_len,
			&wall8->endian);
	scale_image(&wall8, &wall32);
	return (wall8);
}

static void	wall_to_map(t_data *data, t_img *wall, t_img *map, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;
	int				map_x;
	int				map_y;

	j = 0;
	while (j < wall->height)
	{
		i = 0;
		while (i < wall->width)
		{
			map_x = x + i;
			map_y = y + j;
			if (map_x >= 0 && map_x < (data->map->width) * 32 && map_y >= 0
				&& map_y < (data->map->height) * 32)
			{
				color = *(int *)(wall->addr + j * wall->line_len + i * 4);
				if (color != 0xFF000000)
				{
					*(int *)(map->addr + map_y * map->line_len + map_x
							* 4) = color;
				}
			}
			i++;
		}
		j++;
	}
}

// wall = 8*8px
int	display_minimap(t_data *data)
{
	t_img *minimap;
	t_img *wall;
	int x;
	int y;
	int minimap_x;
	int minimap_y;

	wall = get_wall(data);

	minimap = malloc(sizeof(t_img));
	minimap.img = mlx_new_image(data->mlx_ptr, 500, 300);
	minimap.addr = mlx_get_data_addr(minimap.img, &minimap.bpp,
			&minimap.line_len, &minimap.endian);
	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (data->map->map_lines[y][x] == '1')
			{
				minimap_x = minimap.width * x / data->map->width;
				minimap_y = minimap.height * y / data->map->height;
				// scale_image(&minimap, data->map);
			}
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, minimap.img, 0, 0);

	return (0);
}
