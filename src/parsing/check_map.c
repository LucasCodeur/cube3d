/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:38:45 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/15 16:10:09 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_error	hero_on_limit(t_data *data, int i, int *j)
{
	t_error	error;

	if (i == 0 || i == data->map.height - 1 || *j == 0 || *j == data->map.width
		- 1)
	{
		error.code = ERR_INVALID_ARG;
		error.message = "Map open,hero out of the map\n ";
		return (error);
	}
	return (ERROR_OK);
}

static t_error	hero_on_map(t_data *data, int i, int *j)
{
	t_error	error;
	int		k;
	int		l;

	k = -1;
	while (k < 1)
	{
		l = -1;
		while (l < 1)
		{
			if (data->map.grid[i + k][*j + l] != '0' && data->map.grid[i + k][*j
				+ l] != '1')
			{
				error.code = ERR_INVALID_ARG;
				error.message = "Hero out of the map\n";
				return (error);
			}
			l = l + 2;
		}
		k = k + 2;
	}
	return (ERROR_OK);
}

static t_error	loop_tests(t_data *data, int i, int *j)
{
	t_error	error;

	while (data->map.grid[i][*j])
	{
		if (data->map.grid[i][*j] == 'N' || data->map.grid[i][*j] == 'S'
			|| data->map.grid[i][*j] == 'E' || data->map.grid[i][*j] == 'W')
		{
			if (data->map.player.orientation != '\0')
			{
				error.code = ERR_INVALID_ARG;
				error.message = "You must have just one hero on the map\n";
				return (error);
			}
			error = hero_on_limit(data, i, j);
			if (error.code != ERR_OK)
				return (error);
			error = hero_on_map(data, i, j);
			if (error.code != ERR_OK)
				return (error);
			data->map.player.x = *j;
			data->map.player.y = i;
			data->map.player.orientation = data->map.grid[i][*j];
		}
		(*j)++;
	}
	return (ERROR_OK);
}

static t_error	check_save_hero(t_data *data)
{
	t_error	error;
	int		i;
	int		j;

	i = 0;
	while (data->map.grid[i])
	{
		j = 0;
		while (data->map.grid[i][j])
		{
			error = loop_tests(data, i, &j);
			if (error.code != ERR_OK)
				return (error);
		}
		i++;
	}
	if (data->map.player.orientation == '\0')
	{
		error.code = ERR_INVALID_ARG;
		error.message = "No hero on your map\n";
		return (error);
	}
	return (ERROR_OK);
}

t_error	check_map(t_data *data)
{
	t_error	error;

	error = check_save_hero(data);
	if (error.code != ERR_OK)
		return (error);
	error = check_map_structure(data);
	if (error.code != ERR_OK)
		return (error);
	return (ERROR_OK);
}
