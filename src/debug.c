/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:01:40 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/16 16:09:22 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h" 
#include "debug.h"

void	d_print_grid(t_map map)
{
	for (int i = 0; i < map.height; i++)
		printf("%s\n", map.grid[i]);
	printf("x: %lf\n", map.player.pos.elements[0]);	
	printf("y: %lf\n", map.player.pos.elements[1]);	
}

void	d_print_frame(t_img img, int* x, int* y)
{
	t_pixel* image = (t_pixel *)img.addr;
	printf("X :%u Y :%u Bpp : %u\n", *x, *y, img.bits_per_pixel);
	for (int i = 0; i < (*x * *y); i++)
	{
		printf("%d ", image[i].rgb.r);
	}
	printf("\n");
}

void	d_generate_map(t_data* data)
{
	for (int i = 0; i < data->map.rows; i++)
	{
		for (int j = 0; j < data->map.cols; j++)
		{
			if (i == 0 || i == data->map.rows - 1)
				data->map.grid[i][j] = '1';
			else if (j == 0 || j == data->map.cols - 1)
				data->map.grid[i][j] = '1';
			else
				data->map.grid[i][j] = '0';
		}
		data->map.grid[i][SIZE_X] = '\0';
	}
	data->map.grid[6][5] = '1';
	data->map.grid[7][5] = '1';
	data->map.grid[8][5] = '1';
	data->map.grid[9][5] = '1';
	data->map.player.pos.elements[0] = (SIZE_X + 2) * 0.5;
	data->map.player.pos.elements[1] = (SIZE_Y + 2) * 0.5;
}

void	d_print_values(t_data* data)
{
	printf("POS:%.2f,%.2f | DIR:%.2f,%.2f | PLANE:%.2f,%.2f\n", data->map.player.pos.elements[0], data->map.player.pos.elements[1], data->map.player.dir.elements[0], data->map.player.dir.elements[0], data->map.player.plane.elements[0], data->map.player.plane.elements[1]);
}
