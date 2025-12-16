/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:19:44 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/16 15:42:27 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H 
# define TEST_H

#include "display.h"

void t_cast_dir_vec(t_data *data, int tile_size);
void t_draw_fov_vec(t_data *data, int tile_size);
void t_plane_is_orthogonal_to_dir(t_vec v1, t_vec v2);

#endif
