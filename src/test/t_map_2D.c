/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_2D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:02:32 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/27 17:14:22 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "test.h"

#include <stdbool.h>
#include  <mlx.h>

bool	t_draw_map(t_data* data, int tile_size);
void	t_draw_hero(t_data* data, int tile_size);

/**
* @brief allow to display the map
* @param data contains all information necessary to the project.
* @return true if success
*/
bool	t_display_map_2D(t_data* data)
{
	int size_cols; 
	int size_rows;
	
	size_cols = (WIN_WIDTH / 8) / data->map.width;
	size_rows = (WIN_HEIGHT / 8) / data->map.height;
	if (size_cols <= size_rows)
		data->tile_size = size_cols;
	else
		data->tile_size = size_rows;
	t_draw_map(data, data->tile_size);
	t_draw_hero(data, data->tile_size);
	// t_display_fov(data);
	// t_cast_plane_vec(data, data->tile_size);
	t_ray_casting_2D(data);
	t_cast_dir_vec(data, data->tile_size);
	return (true);
}

static void    t_set_value(t_data* data, int* map_x, int* map_y, int* screen_x, int* screen_y, int test_x, int test_y);

/**
* @brief allow to draw any ray on the screen
* @param data contain all information about the program
* @param ray_dir_x abscisse of direction ray
* @param ray_dir_x ordinate of direction ray
* @param hex_color color of the ray 
* @return
*/
void t_draw_ray(t_data* data, t_vec ray_dir, int hex_color)
{
	t_pixel		color;
	double		dist;
	int		map_x; 
	int		map_y;
	int		screen_x;
	int		screen_y;
	int		test_x;
	int		test_y;

	color.value = hex_color;
	dist = 0;
	while (dist < 300.0)
	{ 
	test_x = data->map.player.pos.elements[0] + ray_dir.elements[0] * dist;
	test_y = data->map.player.pos.elements[1] + ray_dir.elements[1] * dist;
	t_set_value(data, &map_x, &map_y, &screen_x, &screen_y, test_x, test_y);
	if ((screen_x >= 0 && screen_x < WIN_WIDTH &&
	    screen_y >= 0 && screen_y < WIN_HEIGHT &&
	    test_x >= 0 && test_x < WIN_WIDTH &&
	    test_y >= 0 && test_y < WIN_HEIGHT) && (data->map.grid[map_y][map_x] == '0'))
	{
	    my_mlx_pixel_put(data, screen_x, screen_y, &color);
	}
	else
	    break;
	dist += 0.05;
	}
}

/**
* @brief allow to set value needs for the main function of drawing rays 
* @param data contain all information about the program
* @param map_x index to access in the map in order to check if we are on a wall or not
* @param map_y index to access in the map in order to check if we are on a wall or not
* @return
*/
static void    t_set_value(t_data* data, int* map_x, int* map_y, int* screen_x, int* screen_y, int test_x, int test_y)
{
        *map_x = test_x;
        *map_y = test_y;
        
        *screen_x = test_x * data->tile_size + data->tile_size / 2;
	*screen_y = test_y * data->tile_size + data->tile_size / 2;
}

static void	fill_color(t_map map, int x, int y, t_pixel* color);
static void convert_and_draw_map(t_data* data, int x, int y, int tile_size);

/**
* @brief allow to draw the map
* @param data all information about the program
* @param tile_size size of the pixel to draw
* @return true if success false if not
*/
bool	t_draw_map(t_data* data, int tile_size)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < data->map.height)
	{
		while (x < data->map.width)
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
void	t_draw_hero(t_data* data, int tile_size)
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
		color->value = BLUE;
	else
		color->value = RED;
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
