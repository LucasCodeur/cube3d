/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fov.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:15:24 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/16 16:04:14 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vector.h"

void t_draw_fov_vec(t_data *data, int tile_size)
{
    t_pixel color; color.value = 0x00FF00;    
    double px = data->map.player.pos.elements[0];
    double py = data->map.player.pos.elements[1];
    double dx = data->map.player.dir.elements[0];
    double dy = data->map.player.dir.elements[1];
    double px_plane = data->map.player.plane.elements[0];
    double py_plane = data->map.player.plane.elements[1];
    
    double len = 4.0; int steps = 80;
    for(int i = 0; i < steps; i++) {
        double t = (len * i) / steps;
        double x_left = px + (dx - px_plane) * t;
        double y_left = py + (dy - py_plane) * t;
        int c_x = x_left * tile_size + tile_size / 2;
        int c_y = y_left * tile_size + tile_size / 2;
        my_mlx_pixel_put_minimap(data, c_x, c_y, &color);
    }
    
    for(int i = 0; i < steps; i++) {
        double t = (len * i) / steps;
        double x_right = px + (dx + px_plane) * t;
        double y_right = py + (dy + py_plane) * t;
        int c_x = x_right * tile_size + tile_size / 2;
        int c_y = y_right * tile_size + tile_size / 2;
        my_mlx_pixel_put_minimap(data, c_x, c_y, &color);
    }
}

void t_cast_dir_vec(t_data *data, int tile_size)
{
    t_pixel color;
    color.value = WHITE;

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

        my_mlx_pixel_put_minimap(data, c_x, c_y, &color);
    }
}

void t_plane_is_orthogonal_to_dir(t_vec v1, t_vec v2)
{
	if (orthogonal(v1, v2) == true)
		printf("IS ORTHOGONAL\n");
}
