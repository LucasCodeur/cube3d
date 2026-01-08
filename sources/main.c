/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:06:01 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/08 09:42:15 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void	display_wall(t_data *data, int x, int y)
// {
// 	void	*wall_img;
// 	int		width;
// 	int		height;

// 	data->map->map_lines[y][x] = '1';
// 	wall_img = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/wall.xpm", &width,
// 			&height);
// 	// if (!wall_img)
// 	// 	error(data, "Problem with wall display");
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, wall_img, x * 32, y
// 		* 32);
// 	mlx_destroy_image(data->mlx_ptr, wall_img);
// }

// static void	display_one_line(t_data *data, int x, int y)
// {
// 	if (data->map->map_lines[y][x] == '1')
// 		display_wall(data, x, y);
// }

// static void	display_map(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < data->map->height)
// 	{
// 		x = 0;
// 		while (x < data->map->width)
// 		{
// 			display_one_line(data, x, y);
// 			x++;
// 		}
// 		y++;
// 	}
// }

int	main(int argc, char **argv)
{
	t_data	*data;

	data = init_data();
	if (!data)
	{
		free_all(data);
		return (1);
	}
	if (parsing(argc, argv, data))
	{
		free_all(data);
		return (1);
	}
	mlx_init_window(data);
	display_map(data);
	display_minimap(data);
	mlx_hook_loop(data);
	free_all(data);
	return (0);
}
