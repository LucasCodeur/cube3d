/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:06:12 by prigaudi          #+#    #+#             */
/*   Updated: 2025/03/13 09:53:09 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_lines_cpy(t_data *data, char **lines_cpy)
{
	int	i;

	i = 0;
	while (i < data->map->height)
	{
		free(lines_cpy[i]);
		i++;
	}
	free(lines_cpy);
}

static void	recursive(char **lines_cpy, int x, int y)
{
	if (lines_cpy[y][x + 1] == '0' || lines_cpy[y][x + 1] == 'E'
		|| lines_cpy[y][x + 1] == 'P' || lines_cpy[y][x + 1] == 'C')
	{
		lines_cpy[y][x + 1] = '1';
		recursive(lines_cpy, x + 1, y);
	}
	if (lines_cpy[y][x - 1] == '0' || lines_cpy[y][x - 1] == 'E'
		|| lines_cpy[y][x - 1] == 'P' || lines_cpy[y][x - 1] == 'C')
	{
		lines_cpy[y][x - 1] = '1';
		recursive(lines_cpy, x - 1, y);
	}
	if (lines_cpy[y + 1][x] == '0' || lines_cpy[y + 1][x] == 'E' || lines_cpy[y
		+ 1][x] == 'P' || lines_cpy[y + 1][x] == 'C')
	{
		lines_cpy[y + 1][x] = '1';
		recursive(lines_cpy, x, y + 1);
	}
	if (lines_cpy[y - 1][x] == '0' || lines_cpy[y - 1][x] == 'E' || lines_cpy[y
		- 1][x] == 'P' || lines_cpy[y - 1][x] == 'C')
	{
		lines_cpy[y - 1][x] = '1';
		recursive(lines_cpy, x, y - 1);
	}
}

static void	map_copy(t_data *data, char **lines_cpy)
{
	int	i;

	i = 0;
	while (i < data->map->height)
	{
		lines_cpy[i] = ft_strdup(data->map->lines[i]);
		if (!lines_cpy[i])
		{
			while (i > 0)
			{
				free(lines_cpy[i]);
				i--;
			}
			error(data, "Problem with ft_strdup in check_way");
		}
		i++;
	}
}

void	check_way(t_data *data)
{
	char	**l_cpy;
	int		x;
	int		y;

	l_cpy = ft_calloc(data->map->height, sizeof(char *));
	if (!l_cpy)
		error(data, "Problem with malloc of line_cpy in check_way");
	x = data->hero->x;
	y = data->hero->y;
	map_copy(data, l_cpy);
	recursive(l_cpy, x, y);
	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->width)
		{
			if (l_cpy[y][x] == 'C' || l_cpy[y][x] == 'E' || l_cpy[y][x] == 'P')
			{
				free_lines_cpy(data, l_cpy);
				error(data, "No valid way found in check_way");
			}
		}
	}
	free_lines_cpy(data, l_cpy);
}
