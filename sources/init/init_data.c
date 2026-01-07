/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:26:50 by prigaudi          #+#    #+#             */
/*   Updated: 2025/12/16 09:26:59 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	init_map(t_data *data)
{
	data->map = ft_malloc(&data->garbage, sizeof(t_map));
	if (!data->map)
	{
		printf("Error\nMalloc of data->map failed\n");
		return (1);
	}
	data->map->map_lines = NULL;
	data->map->height = 0;
	data->map->width = 0;
	data->map->map_finished = 0;
	return (0);
}

static int	init_hero(t_data *data)
{
	data->hero = ft_malloc(&data->garbage, sizeof(t_hero));
	if (!data->hero)
	{
		printf("Error\nMalloc of data->hero failed\n");
		return (1);
	}
	data->hero->x = -1;
	data->hero->y = -1;
	data->hero->orientation = '\0';
	return (0);
}

static void	init_simple_values(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->east_texture = NULL;
	data->west_texture = NULL;
	data->floor_rgb_color = NULL;
	data->ceiling_rgb_color = NULL;
	data->nb_valid_elements = 0;
	data->config_is_valid = 0;
	return ;
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	if (!data)
	{
		printf("Error\nMalloc of data failed\n");
		return (NULL);
	}
	data->garbage = NULL;
	init_simple_values(data);
	if (init_map(data))
		return (NULL);
	if (init_hero(data))
		return (NULL);
	return (data);
}
