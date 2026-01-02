/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:33:24 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/02 16:29:52 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vector.h"
#include <math.h>

static t_vec compute_gradient(t_vec ray_dir);
static t_vec define_first_step(t_data* data, t_vec ray_dir, t_vec *ray_len, t_vec delta_dist);
static  int  size_ray(t_data* data, t_vec *ray_len, t_vec delta_dist, t_vec step);

/**
* @brief allow to compute the distance when we encounter a wall
* @param data contain all information about the program
* @param ray_dir vector that describe a ray
* @return the distance of the a ray hitting a wall
*/
double compute_dist(t_data* data, t_vec ray_dir)
{
    t_vec   ray_len;
    t_vec   delta_dist;
    t_vec   step;

    delta_dist = compute_gradient(ray_dir);
    data->map.x = (int)data->map.player.pos.elements[0];
    data->map.y = (int)data->map.player.pos.elements[1];
    step = define_first_step(data, ray_dir, &ray_len, delta_dist);
        double  perp_wall_dist;
    if (size_ray(data, &ray_len, delta_dist, step) == 0)
        perp_wall_dist = (ray_len.elements[0] - delta_dist.elements[0]);
    else
        perp_wall_dist = (ray_len.elements[1] - delta_dist.elements[1]);
    return (perp_wall_dist);
}

/**
* @brief compute gradient of ray_dir
* @param ray_dir direction of the ray
* @return ret the value of the compute of the gradient 
*/
static t_vec compute_gradient(t_vec ray_dir)
{
    t_vec   ret;
    if (ray_dir.elements[0] == 0)
        ret.elements[0] = 1e30;
    else
        ret.elements[0] = fabs(1 / ray_dir.elements[0]);
    if (ray_dir.elements[1] == 0)
        ret.elements[1] = 1e30;
    else
        ret.elements[1] = fabs(1 / ray_dir.elements[1]);
    return (ret);
}

/**
* @brief allow to define the first step of the ray
* @param data all information about the program
* @param ray_dir direction of the ray
* @param ray_len pointer of the length of the ray
* @param delta_dist gradient in order tu multiply the position of the player to 
* have the length of the ray advance by 1 unit
* @return
*/
static t_vec define_first_step(t_data* data, t_vec ray_dir, t_vec *ray_len, t_vec delta_dist)
{
    t_vec   ret;

    if (ray_dir.elements[0] < 0)
    {
        ret.elements[0] = -1;
        ray_len->elements[0] = (data->map.player.pos.elements[0] - (double)data->map.x) * delta_dist.elements[0];
    }
    else
    {
        ret.elements[0] = 1;
        ray_len->elements[0] = ((double)data->map.x + 1.0 - data->map.player.pos.elements[0]) * delta_dist.elements[0];
    }
    if (ray_dir.elements[1] < 0)
    {
        ret.elements[1] = -1;
        ray_len->elements[1] = (data->map.player.pos.elements[1] - (double)data->map.y) * delta_dist.elements[1];
    }
    else
    {
        ret.elements[1] = 1;
        ray_len->elements[1] = ((double)data->map.y + 1.0 - data->map.player.pos.elements[1] ) * delta_dist.elements[1];
    }
    return (ret);
}

/**
* @brief allow to have the size total of the ray
* @param data all information about the program
* @param *ray_len pointer of the length of the ray to fill
* @param step unit of advancement of the ray
* @return side to know which side of delta we have to subtract at ray_len
*/
static  int  size_ray(t_data* data, t_vec *ray_len, t_vec delta_dist, t_vec step)
{
    int     side;
    bool    wall_found;
    double  distance;
    double  max_distance;

    wall_found = false;
    distance = 0.0f;
    max_distance = 100.0f;
    side = 0;
    while (wall_found == false && distance < max_distance)
    {
        if (ray_len->elements[0] < ray_len->elements[1])
        {
            data->map.x += (int)step.elements[0];
            distance += ray_len->elements[0];
            ray_len->elements[0] += delta_dist.elements[0];
            side = 0;
        }
        else
        {
            data->map.y += (int)step.elements[1];
            distance += ray_len->elements[1];
            ray_len->elements[1] += delta_dist.elements[1];
            side = 1;
        }
        if (data->map.grid[data->map.y][data->map.x] != '0')
            wall_found = true;
    }
    return (side);
}
