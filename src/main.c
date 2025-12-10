/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:06:38 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/10 13:00:40 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "display.h"

#include <stdio.h>


#include "debug.h"
#include "vector.h"

int main(void)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data))	;
	data.mlx.max_height = WIN_HEIGHT;
	data.mlx.max_width = WIN_WIDTH;
	data.map.cols = SIZE_X;
	data.map.rows = SIZE_Y;
	data.map.player.pos = new_vector(2, 1.0f, 1.0f);
	data.map.player.dir = new_vector(2, 1.0f, 1.0f);
	print(data.map.player.dir);
	d_generate_map(&data);
	d_print_grid(data.map);
	launcher(&data);
}
