/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fov.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:15:24 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/26 18:01:30 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "display.h"
#include "matrice.h"
#include "vector.h"

#include <math.h>

void t_cast_dir_vec(t_data *data, int tile_size)
{
    t_pixel color;
    color.value = BLACK; 

    double px = data->map.player.pos.elements[0];
    double py = data->map.player.pos.elements[1];

    double dx = data->map.player.dir.elements[0];
    double dy = data->map.player.dir.elements[1];

    double len = 3.0;
    int steps = 100;

    for (int i = 0; i < steps; i++)
    {
        double t = (len * i) / (double)steps;
        double x_map = px + dx * t;
        double y_map = py + dy * t;

        int c_x = x_map * tile_size + tile_size / 2;
        int c_y = y_map * tile_size + tile_size / 2;

        my_mlx_pixel_put(data, c_x, c_y, &color);
    }
}

void t_cast_plane_vec(t_data *data, int tile_size)
{
    t_pixel color;
    color.value = WHITE;

    double px = data->map.player.pos.elements[0];
    double py = data->map.player.pos.elements[1];

    double dx = data->map.player.plane.elements[0];
    double dy = data->map.player.plane.elements[1];

    double len = 3.0;
    int steps = 100;

    for (int i = 0; i < steps; i++)
    {
        double t = (len * i) / (double)steps;
        double x_map = px + dx * t;
        double y_map = py + dy * t;

        int c_x = x_map * tile_size + tile_size / 2;
        int c_y = y_map * tile_size + tile_size / 2;

        my_mlx_pixel_put(data, c_x, c_y, &color);
    }
}

void t_plane_is_orthogonal_to_dir(t_vec v1, t_vec v2)
{
	if (orthogonal(v1, v2) == true)
		printf("IS ORTHOGONAL\n");
}

void    t_display_fov(t_data *data)
{
        t_vec   ray_dir_left = new_vector_2D(data->map.player.dir.elements[0] + data->map.player.plane.elements[0] * (-1), data->map.player.dir.elements[1] + data->map.player.plane.elements[1] * (-1));
        t_vec   ray_dir_left_2 = new_vector_2D(data->map.player.dir.elements[0] + data->map.player.plane.elements[0] * -0.33, data->map.player.dir.elements[1] + data->map.player.plane.elements[1] * -0.33);
        t_vec   ray_dir_right = new_vector_2D(data->map.player.dir.elements[0] + data->map.player.plane.elements[0] * (1), data->map.player.dir.elements[1] + data->map.player.plane.elements[1] * (1));
        t_vec   ray_dir_right_2 = new_vector_2D(data->map.player.dir.elements[0] + data->map.player.plane.elements[0] * 0.33, data->map.player.dir.elements[1] + data->map.player.plane.elements[1] * 0.33);
        draw_ray(data, ray_dir_left, WHITE); 
        draw_ray(data, ray_dir_left_2, WHITE); 
        draw_ray(data, ray_dir_right, YELLOW);
        draw_ray(data, ray_dir_right_2, YELLOW);
}

void    t_ray_casting_2D(t_data *data)
{
        t_vec   ray = new_vector_2D(data->map.player.dir.elements[0] + data->map.player.plane.elements[0] * (-1), data->map.player.dir.elements[1] + data->map.player.plane.elements[1] * (-1));
        double i = -1.0f;
        while (i < 1.0f)
        {
            i += 0.005f;
            draw_ray(data, ray, WHITE); 
            ray = new_vector_2D(data->map.player.dir.elements[0] + data->map.player.plane.elements[0] * (i), data->map.player.dir.elements[1] + data->map.player.plane.elements[1] * (i));
        }
}
