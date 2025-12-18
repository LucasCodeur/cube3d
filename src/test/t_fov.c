/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fov.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:15:24 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/18 16:59:56 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "display.h"
#include "vector.h"

void t_draw_fov_vec(t_data *data, int tile_size)
{
    t_pixel color; color.value = 0x00FF00;    
    double px = data->map.player.ray.pos.elements[0];
    double py = data->map.player.ray.pos.elements[1];
    double dx = data->map.player.ray.dir.elements[0];
    double dy = data->map.player.ray.dir.elements[1];
    double px_plane = data->map.player.plane.elements[0];
    double py_plane = data->map.player.plane.elements[1];
    
    double len = 4.0; int steps = 80;
    for(int i = 0; i < steps; i++) {
        double t = (len * i) / steps;
        double x_left = px + (dx - px_plane) * t;
        double y_left = py + (dy - py_plane) * t;
        int c_x = x_left * tile_size + tile_size / 2;
        int c_y = y_left * tile_size + tile_size / 2;
        my_mlx_pixel_put(data, c_x, c_y, &color);
    }
    
    for(int i = 0; i < steps; i++) {
        double t = (len * i) / steps;
        double x_right = px + (dx + px_plane) * t;
        double y_right = py + (dy + py_plane) * t;
        int c_x = x_right * tile_size + tile_size / 2;
        int c_y = y_right * tile_size + tile_size / 2;
        my_mlx_pixel_put(data, c_x, c_y, &color);
    }
}

void t_cast_dir_vec(t_data *data, int tile_size)
{
    t_pixel color;
    color.value = WHITE;

    double px = data->map.player.ray.pos.elements[0];
    double py = data->map.player.ray.pos.elements[1];

    double dx = data->map.player.ray.dir.elements[0];
    double dy = data->map.player.ray.dir.elements[1];

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

void draw_ray(t_data* data, double pos_x, double pos_y, 
              double ray_dir_x, double ray_dir_y, int hex_color)
{
    t_pixel color;
    double dist = 0;
    int map_x, map_y;
    
    color.value = hex_color;
    while (dist < 10.0)
    {
        double test_x = pos_x + ray_dir_x * dist;
        double test_y = pos_y + ray_dir_y * dist;
        
        map_x = (int)test_x;
        map_y = (int)test_y;
        
        int screen_x = (int)(test_x * data->tile_size + data->tile_size / 2);
        int screen_y = (int)(test_y * data->tile_size + data->tile_size / 2);
        
        if (screen_x >= 0 && screen_x < WIDTH &&
            screen_y >= 0 && screen_y < HEIGHT &&
            map_x >= 0 && map_x < WIDTH &&
            map_y >= 0 && map_y < HEIGHT)
        {
            my_mlx_pixel_put(data, screen_x, screen_y, &color);
        }
        else
            break;
        dist += 0.05;
    }
}

void    t_display_fov(t_data *data)
{
        t_vec   ray_dir_left = new_vector_2D(data->map.player.ray.dir.elements[0] + data->map.player.plane.elements[0] * (-1), data->map.player.ray.dir.elements[1] + data->map.player.plane.elements[1] * (-1));
        t_vec   ray_dir_right = new_vector_2D(data->map.player.ray.dir.elements[0] + data->map.player.plane.elements[0] * (1), data->map.player.ray.dir.elements[1] + data->map.player.plane.elements[1] * (1));

        printf("BEFORE NORMALIZE\n");
        printf("ray_dir_left_x : %lf, ray_dir_left_y : %lf\nray_dir_right_x : %lf, ray_dir_right_y : %lf\n", ray_dir_left.elements[0], ray_dir_left.elements[1], ray_dir_right.elements[0], ray_dir_right.elements[1]);
        normalize(&ray_dir_left);
        normalize(&ray_dir_right);
        printf("AFTER NORMALIZE\n");
        printf("ray_dir_left_x : %lf, ray_dir_left_y : %lf\nray_dir_right_x : %lf, ray_dir_right_y : %lf\n", ray_dir_left.elements[0], ray_dir_left.elements[1], ray_dir_right.elements[0], ray_dir_right.elements[1]);
        d_print_values(data);
        draw_ray(data, data->map.player.ray.pos.elements[0], data->map.player.ray.pos.elements[1], ray_dir_left.elements[0], ray_dir_left.elements[1], WHITE); 
        draw_ray(data, data->map.player.ray.pos.elements[0], data->map.player.ray.pos.elements[1], ray_dir_right.elements[0], ray_dir_right.elements[1], YELLOW);
}

void    t_ray_casting_2D(t_data *data)
{
        t_vec   ray_dir_left = new_vector_2D(data->map.player.ray.dir.elements[0] + data->map.player.plane.elements[0] * (-1), data->map.player.ray.dir.elements[1] + data->map.player.plane.elements[1] * (-1));
        t_vec   ray_dir_right = new_vector_2D(data->map.player.ray.dir.elements[0] + data->map.player.plane.elements[0] * (1), data->map.player.ray.dir.elements[1] + data->map.player.plane.elements[1] * (1));

        normalize(&ray_dir_left);
        normalize(&ray_dir_right);
        printf("BEFORE NORMALIZE\n");
        printf("ray_dir_left_x : %lf, ray_dir_left_y : %lf\nray_dir_right_x : %lf, ray_dir_right_y : %lf\n", ray_dir_left.elements[0], ray_dir_left.elements[1], ray_dir_right.elements[0], ray_dir_right.elements[1]);

        t_vec ray = new_vector_2D(data->map.player.ray.dir.elements[0] + data->map.player.plane.elements[0] * (-1), data->map.player.ray.dir.elements[1] + data->map.player.plane.elements[1] * (-1));
        normalize(&ray);
        while (ray.elements[0] != ray_dir_right.elements[0] && ray.elements[1] != ray_dir_right.elements[1])
        {
            draw_ray(data, data->map.player.ray.pos.elements[0], data->map.player.ray.pos.elements[1], ray.elements[0], ray.elements[1], WHITE); 
            ray.elements[0]++;
            ray.elements[1]++;
        }
}
