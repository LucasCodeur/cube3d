/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:19:44 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/26 18:06:02 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
#define TEST_H

#include "display.h"

void t_cast_dir_vec(t_data *data, int tile_size);
void t_draw_fov_vec(t_data *data, int tile_size);
void t_plane_is_orthogonal_to_dir(t_vec v1, t_vec v2);
void t_display_fov(t_data *data);
void t_ray_casting_2D(t_data *data);
void t_ray_casting_2D_pos(t_data *data);
void t_ray_casting_2D_neg(t_data *data);
void t_cast_plane_vec(t_data *data, int tile_size);
bool t_display_map_2D(t_data* data);

#endif
