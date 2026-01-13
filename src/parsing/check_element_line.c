/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:52:57 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/13 14:42:20 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_error	choose_id(char *substr, t_parsing *data, int *i, char **id)
{
	t_error	error;

	if (!ft_strncmp(substr, "NO ", 3) || !ft_strncmp(substr, "SO ", 3)
		|| !ft_strncmp(substr, "WE ", 3) || !ft_strncmp(substr, "EA ", 3))
	{
		error = ft_substr(data, substr, 0, 2, id);
		*i = 3;
	}
	else if (!ft_strncmp(substr, "F ", 2) || !ft_strncmp(substr, "C ", 2))
	{
		error = ft_substr(data, substr, 0, 1, id);
		*i = 2;
	}
	if (error.code != ERR_OK)
		return (error);
	return (ERROR_OK);
}

static t_error	extract_id(t_parsing *data, char *line, int *i, char **id)
{
	t_error	error;
	char	*str;

	str = NULL;
	error = ft_substr(data, line, 0, 3, &str);
	if (error.code != ERR_OK)
		return (error);
	error = choose_id(str, data, i, id);
	if (error.code != ERR_OK)
		return (error);
	return (ERROR_OK);
}

static t_error	extract_infos(t_parsing *data, char *line, int *i,
		char **info_clean)
{
	t_error	error;
	char	*info_brut;
	int		index_start;

	info_brut = NULL;
	index_start = *i;
	while (line[*i] != '\n')
		*i = *i + 1;
	error = ft_substr(data, line, index_start, *i - index_start, &info_brut);
	if (error.code != ERR_OK)
		return (error);
	error = ft_strtrim(data, info_brut, " ", info_clean);
	if (error.code != ERR_OK)
		return (error);
	return (ERROR_OK);
}

t_error	check_element_line(char *line, t_parsing *data)
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
	return (ERROR_OK);
}
