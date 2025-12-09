/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:06:38 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/17 14:39:00 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "display.h"

#include <stdio.h>


#include "debug.h"

int main(void)
{
	t_data	data;

	data.mlx.max_height = WIN_HEIGHT;
	data.mlx.max_width = WIN_WIDTH;
	data.map.cols = SIZE_X;
	data.map.rows = SIZE_Y;
	d_generate_map(&data);
	d_print_grid(data.map);
	launcher(&data);
}
