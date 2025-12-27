/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:23:51 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/26 18:18:11 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static void    set_value(t_data* data, int* map_x, int* map_y);

/**
* @brief allow to draw any ray on the screen
* @param data contain all information about the program
* @param ray_dir_x abscisse of direction ray
* @param ray_dir_x ordinate of direction ray
* @param hex_color color of the ray 
* @return
*/
void draw_ray(t_data* data, t_vec ray_dir, int hex_color)
{
    t_pixel     color;
    double	dist;
    int		map_x; 
    int		map_y;
    
    color.value = hex_color;
    dist = 0;
    while (dist < 300.0)
    { 
        data->ray.test_x = data->map.player.pos.elements[0] + ray_dir.elements[0] * dist;
        data->ray.test_y = data->map.player.pos.elements[1] + ray_dir.elements[1] * dist;
        set_value(data, &map_x, &map_y);
        if ((data->ray.screen_x >= 0 && data->ray.screen_x < WIN_WIDTH &&
            data->ray.screen_y >= 0 && data->ray.screen_y < WIN_HEIGHT &&
            (int)data->ray.test_x >= 0 && (int)data->ray.test_x < WIN_WIDTH &&
            (int)data->ray.test_y >= 0 && (int)data->ray.test_y < WIN_HEIGHT) && (data->map.grid[map_y][map_x] == '0'))
        {
            my_mlx_pixel_put(data, data->ray.screen_x, data->ray.screen_y, &color);
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
static void    set_value(t_data* data, int* map_x, int* map_y)
{
        
        *map_x = (int)data->ray.test_x;
        *map_y = (int)data->ray.test_y;
        
        data->ray.screen_x = (int)(data->ray.test_x * data->tile_size + data->tile_size / 2);
        data->ray.screen_y = (int)(data->ray.test_y * data->tile_size + data->tile_size / 2);


}
