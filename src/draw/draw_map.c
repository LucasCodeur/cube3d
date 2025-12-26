/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:51:45 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/18 13:41:47 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "display.h"

static void	fill_color(t_map map, int x, int y, t_pixel* color);
static void convert_and_draw_map(t_data* data, int x, int y, int tile_size);

/**
* @brief allow to draw the map
* @param data all information about the program
* @param tile_size size of the pixel to draw
* @return true if success false if not
*/
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

/**
* @brief allow to draw the hero on the map
* @param data all information about the program
* @param tile_size size of the pixel to draw
* @return 
*/
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
			my_mlx_pixel_put(data, px_start + px, py_start + py, &color);
			px++;
		}
		px = 0;
	}
}

/**
	* @brief allow to choose the color according the case of the 2D map
	* @param map 2D array of the map
	* @param int x ray.pos on the line
	* @param int y ray.pos of the line
	* @param color structure we have to fill know the color to display
	* @return
*/
static void	fill_color(t_map map, int x, int y, t_pixel* color)
{
	if (map.grid[y][x] == '0')
		color->value = RED;
	else
		color->value = BLUE;
}

/**
	* @brief allow to draw the pixel with a conversion of x and y in order to draw correctly
	* @param data all information about the program
	* @param int x ray.pos on the line
	* @param int y ray.pos of the line
	* @param tile_size size of the pixel to draw
	* @return
*/
static void convert_and_draw_map(t_data* data, int x, int y, int tile_size)
{
	t_pixel	color;
	int		px_start; 
	int		py_start;
	int		py;
	int		px;

	fill_color(data->map, x, y, &color);	
	px_start = x * tile_size;
	py_start = y * tile_size;
	px = 0;
	py = 0;
	while (py < tile_size)
	{
		while (px < tile_size)
		{
			my_mlx_pixel_put(data, px_start + px, py_start + py, &color);
			px++;
		}
		py++;
		px = 0;
	}
}
