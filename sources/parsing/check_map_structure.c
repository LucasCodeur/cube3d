/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:23 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/18 15:18:38 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_map_opened(char **map_test, int i, int j)
{
	char	array[3];
	int		k;

	array[0] = ' ';
	array[1] = '\n';
	array[2] = '\0';
	k = 0;
	while (k < 3)
	{
		if (map_test[i - 1][j - 1] == array[k] || map_test[i - 1][j] == array[k]
			|| map_test[i - 1][j + 1] == array[k] || map_test[i][j
			- 1] == array[k] || map_test[i][j + 1] == array[k] || map_test[i
			+ 1][j - 1] == array[k] || map_test[i + 1][j] == array[k]
			|| map_test[i + 1][j + 1] == array[k])
		{
			printf("Error\nMap open\n");
			return (1);
		}
		k++;
	}
	return (0);
}

static char	**map_copy(t_config_data *config_data)
{
	char	**map_copy;
	int		i;

	map_copy = ft_malloc(&config_data->garbage, sizeof(char *)
			* (config_data->map->height + 1));
	if (!map_copy)
	{
		printf("Error\nMalloc of map_copy\n");
		return (NULL);
	}
	i = 0;
	while (config_data->map->map_lines[i])
	{
		map_copy[i] = ft_strdup(config_data, config_data->map->map_lines[i]);
		if (!map_copy[i])
		{
			printf("Error\nProblem with ft_strdup in map_copy\n");
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static int	recursive(char **map_test, int i, int j, t_config_data *config_data)
{
	if (i == 0 || j == 0 || i == config_data->map->height - 1
		|| j == config_data->map->width - 1)
	{
		printf("Error\nMap open\n");
		return (1);
	}
	if (check_map_opened(map_test, i, j))
		return (1);
	if (j != config_data->map->width - 1 && (map_test[i][j + 1] == '0'
			|| map_test[i][j + 1] == config_data->hero->orientation))
	{
		map_test[i][j + 1] = '1';
		if (recursive(map_test, i, j + 1, config_data))
			return (1);
	}
	if (i != config_data->map->height - 1 && map_test[i + 1][j] == '0')
	{
		map_test[i + 1][j] = '1';
		if (recursive(map_test, i + 1, j, config_data))
			return (1);
	}
	return (0);
}

static int	check_hero_on_map(char **map_test)
{
	int	i;
	int	j;

	i = 0;
	while (map_test[i])
	{
		j = 0;
		while (map_test[i][j])
		{
			if (map_test[i][j] != ' ' && map_test[i][j] != '1'
				&& map_test[i][j] != '\n' && map_test[i][j] != '\0')
			{
				printf("Error\nHero outside the map\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_structure(t_config_data *config_data)
{
	char	**map_test;
	int		i;
	int		j;

	map_test = map_copy(config_data);
	if (!map_test)
		return (1);
	i = -1;
	while (map_test[++i])
	{
		j = 0;
		while (map_test[i][j])
		{
			if (map_test[i][j] == '0')
			{
				map_test[i][j] = '1';
				if (recursive(map_test, i, j, config_data))
					return (1);
			}
			j++;
		}
	}
	if (check_hero_on_map(map_test))
		return (1);
	return (0);
}
