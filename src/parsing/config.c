/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:51:37 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/16 14:02:08 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_error	check_line(char *line, t_data *data)
{
	t_error	error;

	if (data->parsing->nb_valid_elements < 6 && *line != '\n')
	{
		error = check_element_line(line, data);
		if (error.code != ERR_OK)
			return (error);
	}
	else if (data->parsing->nb_valid_elements >= 6)
	{
		error = extract_save_map(line, data);
		if (error.code != ERR_OK)
			return (error);
	}
	return (ERROR_OK);
}

static t_error	check_file_opening(char *path, int *fd)
{
	t_error	error;

	*fd = open(path, O_RDONLY);
	if (*fd == -1)
	{
		error.code = ERR_IO;
		error.message = "Config file cant be opened";
		return (error);
	}
	return (ERROR_OK);
}

t_error	config(char *path, t_data *data)
{
	int		fd;
	char	*line;
	t_error	error;

	line = NULL;
	fd = -1;
	error = check_file_opening(path, &fd);
	if (error.code != ERR_OK)
		return (error);
	error = get_next_line(data, fd, &line);
	if (error.code != ERR_OK)
		return (error);
	while (line)
	{
		error = check_line(line, data);
		if (error.code != ERR_OK)
			return (error);
		error = get_next_line(data, fd, &line);
		if (error.code != ERR_OK)
			return (error);
	}
	error = check_map(data);
	if (error.code != ERR_OK)
		return (error);
	return (ERROR_OK);
}
