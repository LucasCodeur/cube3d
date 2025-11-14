/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:06:38 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/14 16:49:05 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "display.h"
#include "mlx.h"

#include <stdio.h>

int main(void)
{
	t_data	data;
	t_mlx	mlx;
	int rows = 5;
	int cols = 5;

	mlx.max_height = HEIGHT;
	mlx.max_width = WIDTH;
	data.mlx = mlx;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == 0 || i == rows - 1)
				data.map[i][j] = '1';
			else if (j == 0 || j == cols - 1)
				data.map[i][j] = '1';
			else if (j == 2 && i == 3)
				data.map[i][j] = 'P';
			else
				data.map[i][j] = '0';
		}
		data.map[i][cols] = '\0';
	}
	for (int i = 0; i < rows; i++)
		printf("%s\n", data.map[i]);
	launcher(&data);
}
