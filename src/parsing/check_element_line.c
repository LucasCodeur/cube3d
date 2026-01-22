/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:52:57 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/22 16:51:41 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_error	choose_id(t_substr_io s_io, t_data *data, int *i, char **id)
{
	t_error	error;

	if (!ft_strncmp(s_io.in, "NO ", 3) || !ft_strncmp(s_io.in, "SO ", 3)
		|| !ft_strncmp(s_io.in, "WE ", 3) || !ft_strncmp(s_io.in, "EA ", 3))
	{
		error = ft_substr(data, &s_io, 0, 2);
		if (error.code != ERR_OK)
			return (error);
		*id = s_io.out;
		*i = 3;
		return (error_ok());
	}
	else if (!ft_strncmp(s_io.in, "F ", 2) || !ft_strncmp(s_io.in, "C ", 2))
	{
		error = ft_substr(data, &s_io, 0, 1);
		if (error.code != ERR_OK)
			return (error);
		*id = s_io.out;
		*i = 2;
		return (error_ok());
	}
	error.code = ERR_INVALID_ARG;
	error.message = "Config file is not valid\n";
	return (error);
}

static t_error	extract_id(t_data *data, char *line, int *i, char **id)
{
	t_error		error;
	t_substr_io	substr_io;

	substr_io.in = line;
	error = ft_substr(data, &substr_io, 0, 3);
	if (error.code != ERR_OK)
		return (error);
	substr_io.in = substr_io.out;
	error = choose_id(substr_io, data, i, id);
	if (error.code != ERR_OK)
		return (error);
	return (error_ok());
}

static t_error	extract_infos(t_data *data, char *line, int *i,
		char **info_clean)
{
	t_error		error;
	int			index_start;
	t_substr_io	substr_io;

	index_start = *i;
	while (line[*i] != '\n' && line[*i] != '\0')
		*i = *i + 1;
	substr_io.in = line;
	error = ft_substr(data, &substr_io, index_start, *i - index_start);
	if (error.code != ERR_OK)
		return (error);
	error = ft_strtrim(data, substr_io.out, " ", info_clean);
	if (error.code != ERR_OK)
		return (error);
	return (error_ok());
}

t_error	check_element_line(char *line, t_data *data)
{
	t_error	error;
	char	*info;
	int		i;
	char	*id;

	id = NULL;
	info = NULL;
	i = 0;
	while (line[i] == ' ')
		i++;
	error = extract_id(data, line, &i, &id);
	if (error.code != ERR_OK)
		return (error);
	error = extract_infos(data, line, &i, &info);
	if (error.code != ERR_OK)
		return (error);
	error = save_element(id, info, data);
	if (error.code != ERR_OK)
		return (error);
	return (error_ok());
}
