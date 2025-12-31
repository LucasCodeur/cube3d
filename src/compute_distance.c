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
#include "vector.h"
#include <math.h>

/**
* @brief allow to compute the distance when we encounter a wall
* @param data contain all information about the program
* @param ray_dir vector that describe a ray
* @return the distance of the a ray hitting a wall
*/
// double compute_dist(t_data* data, t_vec ray_dir)
// {
//     t_vec   side_dist;
//     t_vec   delta_dist; 
//     bool    hit;
//     int	    map_x; 
//     int	    map_y;
//     int     step_x;
//     int     step_y;
//     int     side;
//
//
//     hit = false;
//     map_x = (int)data->map.player.pos.elements[0];
//     map_y = (int)data->map.player.pos.elements[1];
//     side = 0;
//     if (ray_dir.elements[0] == 0)
//         delta_dist.elements[0] = 1e30;
//     else
//         delta_dist.elements[0] = fabs(1 / ray_dir.elements[0]);
//     if (ray_dir.elements[1] == 0)
//         delta_dist.elements[1] = 1e30;
//     else
//         delta_dist.elements[1] = fabs(1 / ray_dir.elements[1]);
//     if (ray_dir.elements[0] < 0)
//     {
//         step_x = -1;
//         side_dist.elements[0] = (data->map.player.pos.elements[0] - (double)map_x) * delta_dist.elements[0];
//     }
//     else
//     {
//         step_x = 1;
//         side_dist.elements[0] = ((double)map_x + 1.0 - data->map.player.pos.elements[0]) * delta_dist.elements[0];
//     }
//     if (ray_dir.elements[1] < 0)
//     {
//         step_y = -1;
//         side_dist.elements[1] = (data->map.player.pos.elements[1] - (double)map_y) * delta_dist.elements[1];
//     }
//     else
//     {
//         step_y = 1;
//         side_dist.elements[1] = ((double)map_y + 1.0 - data->map.player.pos.elements[1]) * delta_dist.elements[1];
//     }
//     while (hit == false)
//     {
//         if (side_dist.elements[0] < side_dist.elements[1])
//         {
//             side_dist.elements[0] += delta_dist.elements[0];
//             map_x += step_x;
//             side = 0;
//         }
//         else
//         {
//             side_dist.elements[1] += delta_dist.elements[1];
//             map_y += step_y;
//             side = 1;
//         }
//         if (data->map.grid[map_y][map_x] != '0')
//             hit = true;
//     }
//     double perp_wall_dist;
//     if (side == 0)
//         perp_wall_dist = side_dist.elements[0] - delta_dist.elements[0];
//     else
//         perp_wall_dist = side_dist.elements[1] - delta_dist.elements[1];
//     return (perp_wall_dist);
// }

double compute_dist(t_data* data, t_vec ray_dir)
{
    t_vec   ray_len;
    t_vec   delta_dist;
    t_vec   step;
    int     map_x;
    int     map_y;
    bool    wall_found;
    double  distance;
    double  max_distance;

    delta_dist.elements[0] = sqrt(1 + powf(ray_dir.elements[1] / ray_dir.elements[0], 2));
    delta_dist.elements[1] = sqrt(1 + powf(ray_dir.elements[0] / ray_dir.elements[1], 2));
    map_x = (int)data->map.player.pos.elements[0];
    map_y = (int)data->map.player.pos.elements[1];
    wall_found = false;
    distance = 0.0f;
    max_distance = 100.0f;
    if (ray_dir.elements[0] < 0)
    {
        step.elements[0] = -1;
        ray_len.elements[0] =  (data->map.player.pos.elements[0] - (double)map_x) * delta_dist.elements[0];
    }
    else
    {
        step.elements[0] = 1;
        ray_len.elements[0] =  ((double)map_x + 1 - data->map.player.pos.elements[0]) * delta_dist.elements[0];
    }
    if (ray_dir.elements[1] < 0)
    {
        ray_len.elements[1] =  (data->map.player.pos.elements[1] - (double)map_y) * delta_dist.elements[1];
        step.elements[1] = -1;
    }
    else
    {
        ray_len.elements[1] =  ((double)map_y + 1.0 - data->map.player.pos.elements[1] ) * delta_dist.elements[1];
        step.elements[1] = 1;
    }

    int side;
    while (wall_found == false && distance < max_distance)
    {
        if (ray_len.elements[0] < ray_len.elements[1])
        {
            map_x += (int)step.elements[0];
            distance += ray_len.elements[0];
            ray_len.elements[0] += delta_dist.elements[0];
            side = 0;
        }
        else
        {
            map_y += (int)step.elements[1];
            distance += ray_len.elements[1];
            ray_len.elements[1] += delta_dist.elements[1];
            side = 1;
        }
        if (data->map.grid[map_y][map_x] != '0')
            wall_found = true;
    }
    t_vec temp;

    temp.elements[0] = data->map.player.pos.elements[0] + ray_dir.elements[0];
    temp.elements[1] = data->map.player.pos.elements[1] + ray_dir.elements[1];
    double  perp_wall_dist;
    if (side == 0)
        perp_wall_dist = (ray_len.elements[0] - delta_dist.elements[0]);
    else
        perp_wall_dist = (ray_len.elements[1] - delta_dist.elements[1]);

    return (magnitude_squared(temp) * distance);
    // return (perp_wall_dist);
}
