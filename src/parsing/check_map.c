/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:38:45 by prigaudi          #+#    #+#             */
/*   Updated: 2025/12/16 10:41:29 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h" 

static int	hero_on_limit(t_parsing *data, int i, int *j)
{
	if (i == 0 || i == data->map->height - 1 || *j == 0
		|| *j == data->map->width - 1)
	{
		printf("Error\nMap open, hero out of the map\n");
		return (1);
	}
	return (0);
}

static int	hero_on_map(t_parsing *data, int i, int *j)
{
	int	k;
	int	l;

	k = -1;
	while (k < 1)
	{
		l = -1;
		while (l < 1)
		{
			if (data->map->map_lines[i + k][*j + l] != '0'
				&& data->map->map_lines[i + k][*j + l] != '1')
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

static int	loop_tests(t_parsing *data, int i, int *j)
{
	while (data->map->map_lines[i][*j])
	{
		if (data->map->map_lines[i][*j] == 'N'
			|| data->map->map_lines[i][*j] == 'S'
			|| data->map->map_lines[i][*j] == 'E'
			|| data->map->map_lines[i][*j] == 'W')
		{
			if (data->map->player.orientation != '\0')
			{
				printf("Error\nYou must have just one hero on the map\n");
				return (1);
			}
			if (hero_on_limit(data, i, j))
				return (1);
			if (hero_on_map(data, i, j))
				return (1);
			data->map->player.x = *j;
			data->map->player.y = i;
			data->map->player.orientation = data->map->map_lines[i][*j];
		}
		(*j)++;
	}
	return (0);
}

static int	check_save_hero(t_parsing *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map_lines[i])
	{
		j = 0;
		while (data->map->map_lines[i][j])
		{
			if (loop_tests(data, i, &j))
				return (1);
		}
		i++;
	}
	if (data->map->player.orientation == '\0')
	{
		printf("Error\nNo hero on your map\n");
		return (1);
	}
	return (0);
}

int	check_map(t_parsing *data)
{
	if (check_save_hero(data))
		return (1);
	if (check_map_structure(data))
		return (1);
	return (0);
}
