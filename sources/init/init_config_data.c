/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:26:50 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/11 14:26:48 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_config_data	*init_config_data(void)
{
	t_config_data	*config_data;

	config_data = malloc(sizeof(t_config_data));
	if (!config_data)
	{
		printf("Error\nMalloc of config_data failed\n");
		return (NULL);
	}
	config_data->north_texture = NULL;
	config_data->south_texture = NULL;
	config_data->east_texture = NULL;
	config_data->west_texture = NULL;
	config_data->floor_rgb_color = NULL;
	config_data->ceiling_rgb_color = NULL;
	config_data->map = malloc(sizeof(t_map));
	if (!config_data->map)
	{
		printf("Error\nMalloc of config_data->map failed\n");
		return (NULL);
	}
	config_data->map->map_lines = NULL;
	config_data->map->height = 0;
	config_data->map->width = 0;
	config_data->map->map_finished = 0;
	config_data->nb_valid_elements = 0;
	config_data->config_is_valid = 0;
	return (config_data);
}
