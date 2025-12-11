/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:06:40 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/10 14:34:56 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include  <mlx.h>

#include "display.h"

void my_mlx_pixel_put_minimap(t_data *data, int x, int y, t_pixel *color)
{
    t_pixel *dst;

    if (x < 0 || x > WIDTH_MINIMAP || y < 0 || y > HEIGHT_MINIMAP) 
	return ;
    if (!data->img.addr) 
	return ;
    dst = (t_pixel*)(data->img.addr + (y * data->img.line_length + x * 4));
    *dst = *color;
}

void	t_cast_dir_vec(t_data* data, int tile_size)
{
	t_pixel	color;
	float	c_x = (data->map.player.pos.elements[0] + data->map.player.dir.elements[0]) * tile_size + (tile_size * 0.5);
	float	c_y = (data->map.player.pos.elements[1] + data->map.player.dir.elements[1]) * tile_size + (tile_size * 0.5);
	printf("c_x : %lf\n", c_x);
	printf("c_y : %lf\n", c_y);
	color.value = WHITE;
	int i = 0;
	while (i < 500)
	{
		my_mlx_pixel_put_minimap(data, c_x, c_y, &color);
		c_y -= 0.1f;
		i++;
	}
}

void	draw_hero(t_data* data, int tile_size)
{
	t_pixel	color;
	int	px_start; 
	int	py_start; 
	int	py;
	int	px;

	px_start = data->map.player.pos.elements[0] * tile_size;
	py_start = data->map.player.pos.elements[1] * tile_size;
	color.value = GREEN;
	py = 0;
	px = 0;
	while (py < tile_size)
	{
		py++;
		while (px < tile_size)
		{
			my_mlx_pixel_put_minimap(data, px_start + px, py_start + py, &color);
			px++;
		}
		px = 0;
	}
}

void	fill_color(t_map map, int x, int y, t_pixel* color)
{
	if (map.grid[y][x] == '0')
		color->value = RED;
	else
		color->value = BLUE;
}

static void convert_and_draw_map(t_data* data, int x, int y, int tile_size)
{
	t_pixel		color;
	int		px_start; 
	int		py_start;

	fill_color(data->map, x, y, &color);	
	px_start = x * tile_size;
	py_start = y * tile_size;
	int	py = 0;
	int	px = 0;
	while (py < tile_size)
	{
		while (px < tile_size)
		{
			my_mlx_pixel_put_minimap(data, px_start + px, py_start + py, &color);
			px++;
		}
		py++;
		px = 0;
	}
}

bool	draw_map(t_data* data, int tile_size)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < data->map.rows)
	{
		while (x < data->map.cols)
		{
			convert_and_draw_map(data, x, y, tile_size);		
			x++;
		}
		x = 0;
		y++;
	}
		
	return (true);
}

bool	display_minimap(t_data* data)
{
	int size_cols; 
	int size_rows;
	int tile_size;
	
	size_cols = WIDTH_MINIMAP / data->map.cols;
	size_rows = HEIGHT_MINIMAP / data->map.rows;
	if (size_cols <= size_rows)
		tile_size = size_cols;
	else
		tile_size = size_rows;
	draw_map(data, tile_size);
	draw_hero(data, tile_size);
	t_cast_dir_vec(data, tile_size);	
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.ptr, 0, 0);
	return (true);
}
