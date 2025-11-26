/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:01:40 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/26 17:36:43 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h" 
#include "debug.h"

void	d_print_grid(t_map map)
{
	for (int i = 0; i < map.rows; i++)
		printf("%s\n", map.grid[i]);
	printf("x: %d\n", map.hero_pos.x);	
	printf("y: %d\n", map.hero_pos.y);	
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
		data->map.grid[i][data->map.cols] = '\0';
	}
	data->map.hero_pos.x = 3;
	data->map.hero_pos.y = 2;
}
