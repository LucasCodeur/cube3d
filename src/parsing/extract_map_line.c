/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:10:11 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/22 14:16:26 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_error	is_good_char(char *line, int i)
{
	t_error	error;

	if (line[i] != '1' && line[i] != '0' && line[i] != ' ' && line[i] != 'D'
		&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
	{
		error.code = ERR_INVALID_ARG;
		error.message = "Bad character in map structure\n";
		return (error);
	}
	return (ERROR_OK);
}

static t_error	extract_map_line_loop(char *line, t_data *data)
{
	t_error	error;
	int		i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == '\0')
		{
			data->map.map_finished = 1;
			return (ERROR_OK);
		}
		if (data->map.map_finished)
		{
			error.code = ERR_INVALID_ARG;
			error.message = "Empty line in map structure\n";
			return (error);
		}
		error = is_good_char(line, i);
		if (error.code != ERR_OK)
			return (error);
		i++;
	}
	return (ERROR_OK);
}

t_error	extract_map_line(char *line, t_data *data)
{
	t_error error;

	if (!ft_strncmp(line, "\n", 1) && data->map.height)
	{
		data->map.map_finished = 1;
		return (ERROR_OK);
	}
	error = extract_map_line_loop(line, data);
	if (error.code != ERR_OK)
		return (error);
	return (ERROR_OK);
}