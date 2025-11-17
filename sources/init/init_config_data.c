/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:26:50 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/17 14:34:26 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	init_map(t_config_data *config_data)
{
	config_data->map = ft_malloc(&config_data->garbage, sizeof(t_map));
	if (!config_data->map)
	{
		printf("Error\nMalloc of config_data->map failed\n");
		return (1);
	}
	config_data->map->map_lines = NULL;
	config_data->map->height = 0;
	config_data->map->width = 0;
	config_data->map->map_finished = 0;
	return (0);
}

static int	init_hero(t_config_data *config_data)
{
	config_data->hero = ft_malloc(&config_data->garbage, sizeof(t_hero));
	if (!config_data->hero)
	{
		printf("Error\nMalloc of config_data->hero failed\n");
		return (1);
	}
	config_data->hero->x = -1;
	config_data->hero->y = -1;
	config_data->hero->orientation = '\0';
	return (0);
}

static void	init_simple_values(t_config_data *config_data)
{
	config_data->north_texture = NULL;
	config_data->south_texture = NULL;
	config_data->east_texture = NULL;
	config_data->west_texture = NULL;
	config_data->floor_rgb_color = NULL;
	config_data->ceiling_rgb_color = NULL;
	config_data->nb_valid_elements = 0;
	config_data->config_is_valid = 0;
	return ;
}

t_config_data	*init_config_data(void)
{
	t_config_data	*config_data;

	config_data = malloc(sizeof(t_config_data) * 1);
	if (!config_data)
	{
		printf("Error\nMalloc of config_data failed\n");
		return (NULL);
	}
	config_data->garbage = NULL;
	init_simple_values(config_data);
	if (init_map(config_data))
		return (NULL);
	if (init_hero(config_data))
		return (NULL);
	return (config_data);
}
