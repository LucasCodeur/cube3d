/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:52:57 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/17 15:07:07 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*extract_id(t_config_data *config_data, char *line, int *i)
{
	char	*id;
	char	*substr;

	id = NULL;
	substr = ft_substr(config_data, line, 0, 3);
	if (!substr)
	{
		printf("Error\nProblem with ft_substr in extract_id\n");
		return (NULL);
	}
	if (!ft_strncmp(substr, "NO ", 3) || !ft_strncmp(substr, "SO ", 3)
		|| !ft_strncmp(substr, "WE ", 3) || !ft_strncmp(substr, "EA ", 3))
	{
		id = ft_substr(config_data, substr, 0, 2);
		*i = 3;
	}
	else if (!ft_strncmp(substr, "F ", 2) || !ft_strncmp(substr, "C ", 2))
	{
		id = ft_substr(config_data, substr, 0, 1);
		*i = 2;
	}
	if (!id)
	{
		printf("Error\nProblem with config elements0000\n");
		return (NULL);
	}
	return (id);
}

static char	*extract_infos(t_config_data *config_data, char *line, int *i)
{
	char	*info_brut;
	char	*info_clean;
	int		index_start;

	index_start = *i;
	while (line[*i] != '\n')
		*i = *i + 1;
	info_brut = ft_substr(config_data, line, index_start, *i - index_start);
	if (!info_brut)
	{
		printf("Error\nProblem with ft_substr in extract_infos\n");
		return (NULL);
	}
	info_clean = ft_strtrim(config_data, info_brut, " ");
	if (!info_clean)
	{
		printf("Error\nProblem with ft_strtrim in extract_infos\n");
		return (NULL);
	}
	return (info_clean);
}

int	check_element_line(char *line, t_config_data *config_data)
{
	char	*id;
	char	*info;
	int		i;

	i = 0;
	while (line[i] == ' ')
		i++;
	id = extract_id(config_data, line, &i);
	if (!id)
		return (1);
	info = extract_infos(config_data, line, &i);
	if (!info)
		return (1);
	if (save_element(id, info, config_data))
		return (1);
	return (0);
}
