/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:52:57 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/10 17:12:10 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*extract_id(char *line, int *i)
{
	char	*id;
	char	*substr;

	id = NULL;
	substr = ft_substr(line, 0, 3);
	if (!substr)
		return (NULL);
	if (!ft_strncmp(substr, "NO ", 3) || !ft_strncmp(substr, "SO ", 3)
		|| !ft_strncmp(substr, "WE ", 3) || !ft_strncmp(substr, "EA ", 3))
	{
		id = ft_substr(substr, 0, 2);
		*i = 3;
	}
	else if (!ft_strncmp(substr, "F ", 2) || !ft_strncmp(substr, "C ", 2))
	{
		id = ft_substr(substr, 0, 1);
		*i = 2;
	}
	return (id);
}

static char	*extract_infos(char *line, int *i)
{
	char	*info_brut;
	char	*info_clean;
	int		index_start;

	index_start = *i;
	while (line[*i] != '\n')
		*i = *i + 1;
	info_brut = ft_substr(line, index_start, *i - index_start);
	if (!info_brut)
		return (NULL);
	info_clean = ft_strtrim(info_brut, " ");
	if (!info_clean)
		return (NULL);
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
	id = extract_id(line, &i);
	if (!id)
		return (1);
	info = extract_infos(line, &i);
	if (!info)
		return (1);
	if (save_element(id, info, config_data))
		return (1);
	return (0);
}
