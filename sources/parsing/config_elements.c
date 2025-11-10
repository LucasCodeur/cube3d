/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:52:57 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/10 12:01:02 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*extract_id(char *line, int *i)
{
	char	*id;
	char	*test;

	id = NULL;
	test = ft_substr(line, 0, 3);
	if (!ft_strncmp(test, "NO ", 3) || !ft_strncmp(test, "SO ", 3)
		|| !ft_strncmp(test, "WE ", 3) || !ft_strncmp(test, "EA ", 3))
	{
		id = ft_substr(test, 0, 2);
		*i = 3;
	}
	else if (!ft_strncmp(test, "F ", 2) || !ft_strncmp(test, "C ", 2))
	{
		id = ft_substr(test, 0, 1);
		*i = 2;
	}
	return (id);
}

static char	*extract_infos(char *line, int *i)
{
	char	*info;
	int		index_start;

	index_start = *i;
	while (line[*i] != ' ' && line[*i + 1] != '\0')
		*i = *i + 1;
	info = ft_substr(line, index_start, *i - index_start);
	(*i)++;
	while (line[*i] != '\0')
	{
		if (line[*i != ' '])
		{
			info = NULL;
			return (info);
		}
		i++;
	}
	return (info);
}

int	check_element_line(char *line, t_config_data *config_data)
{
	char	*id;
	char	*info;
	int		i;

	i = 0;
	while (line[i] == ' ')
		i++;
	id = extract_id(line, &i);
	if (!id)
		return (1);
	while (line[i] == ' ')
		i++;
	info = extract_infos(line, &i);
	if (!info)
		return (1);
	printf("id=<%s>\n", id);
	printf("info=<%s>\n", info);
	if (!save_element(id, info, config_data))
		return (1);
	return (0);
}
