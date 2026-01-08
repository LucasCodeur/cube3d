/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_save_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:22:08 by prigaudi          #+#    #+#             */
/*   Updated: 2025/12/16 10:41:55 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h" 

static int	extract_map_line(char *line, t_parsing *data)
{
	int	i;

	if (!ft_strncmp(line, "\n", 1) && data->map->height)
	{
		data->map->map_finished = 1;
		return (0);
	}
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (data->map->map_finished)
		{
			printf("Error\nEmpty line in map structure\n");
			return (1);
		}
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ' && line[i] != 'D'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W')
		{
			printf("Error\nBad character in map structure\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	loop_new_map(char **new_map_lines, char *line, t_parsing *data)
{
	int	i;

	i = 0;
	while (data->map->grid && data->map->grid[i])
	{
		new_map_lines[i] = ft_strdup(data, data->map->grid[i]);
		if (!new_map_lines[i])
		{
			printf("Error\nProblem with ft_strdup in save_map_line\n");
			return (1);
		}
		i++;
	}
	new_map_lines[i] = ft_strdup(data, line);
	if (!new_map_lines[i])
	{
		printf("Error\nProblem with ft_strdup in save_map_line\n");
		return (1);
	}
	new_map_lines[++i] = NULL;
	return (0);
}

static int	save_map_line(char *line, t_parsing *data)
{
	char	**new_map_lines;

	new_map_lines = ft_malloc(&data->garbage, sizeof(char *)
			* (data->map->height + 2));
	if (!new_map_lines)
	{
		printf("Error\nMalloc of new_map_lines failed\n");
		return (1);
	}
	if (loop_new_map(new_map_lines, line, data))
		return (1);
	data->map->grid = new_map_lines;
	if ((int)ft_strlen(line) - 1 > data->map->width)
		data->map->width = ft_strlen(line) - 1;
	data->map->height++;
	return (0);
}

int	extract_save_map(char *line, t_parsing *data)
{
	if (extract_map_line(line, data))
		return (1);
	if (ft_strncmp(line, "\n", 1) && save_map_line(line, data))
		return (1);
	return (0);
}
