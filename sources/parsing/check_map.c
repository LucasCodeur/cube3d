/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:38:45 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/21 14:03:58 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	hero_on_limit(t_config_data *config_data, int i, int *j)
{
	if (i == 0 || i == config_data->map->height - 1 || *j == 0
		|| *j == config_data->map->width - 1)
	{
		printf("Error\nMap open, hero out of the map\n");
		return (1);
	}
	return (0);
}

static int	hero_on_map(t_config_data *config_data, int i, int *j)
{
	int	k;
	int	l;

	k = -1;
	while (k < 1)
	{
		l = -1;
		while (l < 1)
		{
			if (config_data->map->map_lines[i + k][*j + l] != '0'
				&& config_data->map->map_lines[i + k][*j + l] != '1')
			{
				printf("Error\nHero out of the map\n");
				return (1);
			}
			l = l + 2;
		}
		k = k + 2;
	}
	return (0);
}

static int	loop_tests(t_config_data *config_data, int i, int *j)
{
	while (config_data->map->map_lines[i][*j])
	{
		if (config_data->map->map_lines[i][*j] == 'N'
			|| config_data->map->map_lines[i][*j] == 'S'
			|| config_data->map->map_lines[i][*j] == 'E'
			|| config_data->map->map_lines[i][*j] == 'W')
		{
			if (config_data->hero->orientation != '\0')
			{
				printf("Error\nYou must have just one hero on the map\n");
				return (1);
			}
			if (hero_on_limit(config_data, i, j))
				return (1);
			if (hero_on_map(config_data, i, j))
				return (1);
			config_data->hero->x = *j;
			config_data->hero->y = i;
			config_data->hero->orientation = config_data->map->map_lines[i][*j];
		}
		(*j)++;
	}
	return (0);
}

static int	check_save_hero(t_config_data *config_data)
{
	int	i;
	int	j;

	i = 0;
	while (config_data->map->map_lines[i])
	{
		j = 0;
		while (config_data->map->map_lines[i][j])
		{
			if (loop_tests(config_data, i, &j))
				return (1);
		}
		i++;
	}
	if (config_data->hero->orientation == '\0')
	{
		printf("Error\nNo hero on your map\n");
		return (1);
	}
	return (0);
}

int	check_map(t_config_data *config_data)
{
	if (check_save_hero(config_data))
		return (1);
	if (check_map_structure(config_data))
		return (1);
	return (0);
}
