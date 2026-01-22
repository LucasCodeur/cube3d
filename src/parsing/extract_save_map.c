/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_save_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:22:08 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/22 10:51:29 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_error	extract_map_line_loop(char *line, t_data *data)
{
	t_error	error;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (data->map.map_finished)
		{
			error.code = ERR_INVALID_ARG;
			error.message = "Empty line in map structure\n";
			return (error);
		}
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ' && line[i] != 'D'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W')
		{
			error.code = ERR_INVALID_ARG;
			error.message = "Bad character in map structure\n";
			return (error);
		}
		i++;
	}
	return (ERROR_OK);
}

static t_error	extract_map_line(char *line, t_data *data)
{
	t_error	error;

	if ((!ft_strncmp(line, "\n", 1) || !ft_strncmp(line, "\n", 1))
		&& data->map.height)
	{
		data->map.map_finished = 1;
		return (ERROR_OK);
	}
	error = extract_map_line_loop(line, data);
	if (error.code != ERR_OK)
		return (error);
	return (ERROR_OK);
}

static t_error	loop_new_map(char ***new_map_lines, char *line, t_data *data)
{
	t_error	error;
	int		i;

	i = 0;
	while (data->map.grid && data->map.grid[i])
	{
		error = ft_strdup(data, data->map.grid[i], &(*new_map_lines)[i]);
		if (error.code != ERR_OK)
			return (error);
		i++;
	}
	error = ft_strdup(data, line, &(*new_map_lines)[i]);
	if (error.code != ERR_OK)
		return (error);
	(*new_map_lines)[++i] = NULL;
	return (ERROR_OK);
}

static t_error	save_map_line(char *line, t_data *data)
{
	t_error	error;
	char	**new_map_lines;

	new_map_lines = NULL;
	error = ft_malloc(&data->garbage, sizeof(char *) * (data->map.height + 2),
			(void **)&new_map_lines);
	if (error.code != ERR_OK)
		return (error);
	error = loop_new_map(&new_map_lines, line, data);
	if (error.code != ERR_OK)
		return (error);
	data->map.grid = new_map_lines;
	if ((int)ft_strlen(line) - 1 > data->map.width)
		data->map.width = ft_strlen(line) - 1;
	data->map.height++;
	return (ERROR_OK);
}

t_error	extract_save_map(char *line, t_data *data)
{
	t_error	error;

	error = extract_map_line(line, data);
	if (error.code != ERR_OK)
		return (error);
	if (ft_strncmp(line, "\n", 1))
	{
		error = save_map_line(line, data);
		if (error.code != ERR_OK)
			return (error);
	}
	return (ERROR_OK);
}
