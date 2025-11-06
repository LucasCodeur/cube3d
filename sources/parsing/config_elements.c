/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:52:57 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/06 16:57:01 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_id(char *id)
{
	if (!ft_strncmp(id, "NO", 2))
		return (0);
	if (!ft_strncmp(id, "SO", 2))
		return (0);
	if (!ft_strncmp(id, "WE", 2))
		return (0);
	if (!ft_strncmp(id, "F ", 2))
		return (0);
	if (!ft_strncmp(id, "C ", 2))
		return (0);
	return (1);
}

static int	extract_infos(char *line)
{
	return (0);
}

int	check_element_line(char *line, t_config_data *config_data)
{
	char	*id;

	printf("line=%s\n", line);
	while (*line == ' ')
		line++;
	id = ft_substr(line, 0, 2);
	if (check_id(id))
		return (1);
	while (*line == ' ')
		line++;
	if (extract_infos(line))
		return (1);
	printf("id valide=%s\n", id);
	config_data->config_is_valid = 0; // A SUPPRIMER
	return (0);
}
