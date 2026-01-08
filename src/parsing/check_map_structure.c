/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:23 by prigaudi          #+#    #+#             */
/*   Updated: 2025/12/16 10:41:13 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h" 

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

static char	**map_copy(t_parsing *data)
{
	char	**map_copy;
	int		i;

	map_copy = ft_malloc(&data->garbage, sizeof(char *) * (data->map->height
				+ 1));
	if (!map_copy)
	{
		printf("Error\nMalloc of map_copy\n");
		return (NULL);
	}
	i = 0;
	while (data->map->map_lines[i])
	{
		map_copy[i] = ft_strdup(data, data->map->map_lines[i]);
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

static int	recursive(char **map_test, int i, int j, t_parsing *data)
{
	if (i == 0 || j == 0 || i == data->map->height - 1 || j == data->map->width
		- 1)
	{
		printf("Error\nMap open\n");
		return (1);
	}
	if (check_map_opened(map_test, i, j))
		return (1);
	if (j != data->map->width - 1 && (map_test[i][j + 1] == '0' || map_test[i][j
			+ 1] == data->map->player.orientation))
	{
		map_test[i][j + 1] = '1';
		if (recursive(map_test, i, j + 1, data))
			return (1);
	}
	if (i != data->map->height - 1 && map_test[i + 1][j] == '0')
	{
		map_test[i + 1][j] = '1';
		if (recursive(map_test, i + 1, j, data))
			return (1);
	}
	return (0);
}

int	check_map_structure(t_parsing *data)
{
	char	**map_test;
	int		i;
	int		j;

	map_test = map_copy(data);
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
				if (recursive(map_test, i, j, data))
					return (1);
			}
			j++;
		}
	}
	return (0);
}
