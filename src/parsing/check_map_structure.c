/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:23 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/16 09:09:11 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_error	check_map_opened(char **map_test, int i, int j)
{
	t_error	error;
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
			error.code = ERR_INVALID_ARG;
			error.message = "Map open\n";
			return (error);
		}
		k++;
	}
	return (ERROR_OK);
}

static t_error	map_copy(t_data *data, char ***map_copy)
{
	t_error	error;
	int		i;

	error = ft_malloc(&data->garbage, sizeof(char *) * (data->map.height + 1),
			(void **)map_copy);
	if (error.code != ERR_OK)
		return (error);
	i = 0;
	while (data->map.grid[i])
	{
		error = ft_strdup(data, data->map.grid[i], &(*map_copy)[i]);
		if (error.code != ERR_OK)
			return (error);
		i++;
	}
	(*map_copy)[i] = NULL;
	return (ERROR_OK);
}

static t_error	recursive(char **map_test, int i, int j, t_data *data)
{
	t_error	error;

	if (i == 0 || j == 0 || i == data->map.height - 1 || j == data->map.width
		- 1)
	{
		error.code = ERR_INVALID_ARG;
		error.message = "Map open\n";
		return (error);
	}
	error = check_map_opened(map_test, i, j);
	if (error.code != ERR_OK)
		return (error);
	if (j != data->map.width - 1 && (map_test[i][j + 1] == '0' || map_test[i][j
			+ 1] == data->map.player.orientation))
	{
		map_test[i][j + 1] = '1';
		error = recursive(map_test, i, j + 1, data);
		if (error.code != ERR_OK)
			return (error);
	}
	if (i != data->map.height - 1 && map_test[i + 1][j] == '0')
	{
		map_test[i + 1][j] = '1';
		error = recursive(map_test, i + 1, j, data);
		if (error.code != ERR_OK)
			return (error);
	}
	return (ERROR_OK);
}

t_error	check_map_structure(t_data *data)
{
	t_error	error;
	char	**map_test;
	int		i;
	int		j;

	map_test = NULL;
	error = map_copy(data, &map_test);
	if (error.code != ERR_OK)
		return (error);
	i = -1;
	while (map_test[++i])
	{
		j = 0;
		while (map_test[i][j])
		{
			if (map_test[i][j] == '0')
			{
				map_test[i][j] = '1';
				error = recursive(map_test, i, j, data);
				if (error.code != ERR_OK)
					return (error);
			}
			j++;
		}
	}
	return (ERROR_OK);
}
