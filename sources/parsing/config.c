/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:51:37 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/06 16:45:28 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Check if the line can be a config line
// It checks the first letter of element lines (without space)
static int	check_line(char *line, t_config_data *config_data)
{
	if (config_data->nb_valid_elements < 6)
	{
		check_element_line(line, config_data);
	}
	return (0);
}

static int	check_file_opening(char *path, int *fd)
{
	*fd = open(path, O_RDONLY);
	if (*fd == -1)
	{
		printf("Error\n");
		perror("open");
		return (1);
	}
	return (0);
}

static int	read_config(char *path, t_config_data *config_data)
{
	int		fd;
	char	*line;

	fd = -1;
	if (check_file_opening(path, &fd))
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		if (check_line(line, config_data))
			return (1);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	config(char *path, t_config_data *config_data)
{
	read_config(path, config_data);
	return (0);
}