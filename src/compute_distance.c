/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:33:24 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/27 16:57:11 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

/**
* @brief allow to compute the distance when we encounter a wall
* @param data contain all information about the program
* @param ray_dir vector that describe a ray
* @return the distance of the a ray hitting a wall
*/
double compute_dist(t_data* data, t_vec ray_dir)
{
    double	dist;
    int		map_x; 
    int		map_y;
    
    dist = 0;
    while (dist < 300.0)
    { 
        data->ray.test_x = data->map.player.pos.elements[0] + ray_dir.elements[0] * dist;
        data->ray.test_y = data->map.player.pos.elements[1] + ray_dir.elements[1] * dist;
		map_x = (int)data->ray.test_x;
		map_y = (int)data->ray.test_y;
        if ((map_x >= 0 && map_x <= data->map.rows) && (map_y >= 0 && map_y <= data->map.cols) && (data->map.grid[map_y][map_x] == '1'))
            break;
        dist += 0.05;
    }
	return (dist);
}
