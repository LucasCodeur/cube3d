/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_save_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:22:08 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/22 16:49:22 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	return (error_ok());
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
	return (error_ok());
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
	return (error_ok());
}
