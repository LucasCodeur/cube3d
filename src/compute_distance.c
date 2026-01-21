/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:33:24 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/21 15:25:38 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vector.h"
#include <float.h>
#include <math.h>

static t_vec	compute_gradient(t_vec ray_dir);
static void		define_first_step(t_data *data, t_vec ray_dir, t_vec *ray_len,
					t_vec delta_dist);
static int		size_ray(t_data *data, t_vec *ray_len, t_vec delta_dist);

/**
 * @brief allow to compute the distance when we encounter a wall
 * @param data contain all information about the program
 * @param ray_dir vector that describe a ray
 * @return the distance of the a ray hitting a wall
 */
double	compute_dist(t_data *data, t_vec ray_dir)
{
	t_vec	ray_len;
	t_vec	delta_dist;
	double	perp_wall_dist;

	ray_len.elements[0] = INFINITY;
	ray_len.elements[1] = INFINITY;
	delta_dist = compute_gradient(ray_dir);
	if (isinf(delta_dist.elements[0]))
		delta_dist.elements[0] = 1e6;
	if (isinf(delta_dist.elements[1]))
		delta_dist.elements[1] = 1e6;
	data->map.x = (int)data->map.player.pos.elements[0];
	data->map.y = (int)data->map.player.pos.elements[1];
	define_first_step(data, ray_dir, &ray_len, delta_dist);
	if (size_ray(data, &ray_len, delta_dist) == 0)
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
static t_vec	compute_gradient(t_vec ray_dir)
{
	t_vec	ret;

	if (ray_dir.elements[0] == 0)
		ret.elements[0] = INFINITY;
	else
		ret.elements[0] = fabs(1 / ray_dir.elements[0]);
	if (ray_dir.elements[1] == 0)
		ret.elements[1] = INFINITY;
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
static void	define_first_step(t_data *data, t_vec ray_dir, t_vec *ray_len,
		t_vec delta_dist)
{
	if (ray_dir.elements[0] <= 0 && ray_dir.elements[0] != INFINITY)
	{
		data->raycasting.step_x = -1;
		ray_len->elements[0] = (data->map.player.pos.elements[0]
				- (double)data->map.x) * delta_dist.elements[0];
	}
	else if (ray_dir.elements[0] != INFINITY)
	{
		data->raycasting.step_x = 1;
		ray_len->elements[0] = ((double)data->map.x + 1.0
				- data->map.player.pos.elements[0]) * delta_dist.elements[0];
	}
	if (ray_dir.elements[1] <= 0 && ray_dir.elements[1] != INFINITY)
	{
		data->raycasting.step_y = -1;
		ray_len->elements[1] = (data->map.player.pos.elements[1]
				- (double)data->map.y) * delta_dist.elements[1];
	}
	else if (ray_dir.elements[1] != INFINITY)
	{
		data->raycasting.step_y = 1;
		ray_len->elements[1] = ((double)data->map.y + 1.0
				- data->map.player.pos.elements[1]) * delta_dist.elements[1];
	}
}

/**
 * @brief allow to have the size total of the ray
 * @param data all information about the program
 * @param *ray_len pointer of the length of the ray to fill
 * @param step unit of advancement of the ray
 * @return side to know which side of delta we have to subtract at ray_len
 */
static int	size_ray(t_data *data, t_vec *ray_len, t_vec delta_dist)
{
	int	max_step;

<<<<<<< HEAD
	while (data->map.grid[data->map.y][data->map.x] == '0')
	{
		if (ray_len->elements[0] <= ray_len->elements[1])
		{
			data->map.x += data->raycasting.step_x;
			ray_len->elements[0] += delta_dist.elements[0];
			data->raycasting.side = 0;
		}
		else
		{
			data->map.y += data->raycasting.step_y;
			ray_len->elements[1] += delta_dist.elements[1];
			data->raycasting.side = 1;
		}
	}
	return (data->raycasting.side);
=======
	max_step = 0;
	while (data->map.grid[data->map.y][data->map.x] == '0' && max_step < 50)
	{
		if (ray_len->elements[0] <= ray_len->elements[1])
		{
			data->map.x += data->raycasting.step_x;
			ray_len->elements[0] += delta_dist.elements[0];
			data->raycasting.side = 0;
		}
		else
		{
			data->map.y += data->raycasting.step_y;
			ray_len->elements[1] += delta_dist.elements[1];
			data->raycasting.side = 1;
		}
		max_step++;
	}
	return (data->raycasting.side);
>>>>>>> minimap
}
