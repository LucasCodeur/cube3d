/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:51:37 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/10 17:25:36 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_line(char *line, t_config_data *config_data)
{
	if (config_data->nb_valid_elements < 6)
	{
		if (check_element_line(line, config_data))
			return (1);
	}
	else
	{
		if (check_map_line(line, config_data))
			return (1);
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
	printf("STRUCTURE:\n");
	printf("north_texture=%s\n", config_data->north_texture);
	printf("south_texture=%s\n", config_data->south_texture);
	printf("east_texture=%s\n", config_data->east_texture);
	printf("west_texture=%s\n", config_data->west_texture);
	printf("floor_rgb_color1=%d\n", config_data->floor_rgb_color[0]);
	printf("floor_rgb_color2=%d\n", config_data->floor_rgb_color[1]);
	printf("floor_rgb_color3=%d\n", config_data->floor_rgb_color[2]);
	printf("ceiling_rgb_color1=%d\n", config_data->ceiling_rgb_color[0]);
	printf("ceiling_rgb_color2=%d\n", config_data->ceiling_rgb_color[1]);
	printf("ceiling_rgb_color3=%d\n", config_data->ceiling_rgb_color[2]);
	printf("Nbre elements=%d\n", config_data->nb_valid_elements);
	return (0);
}

int	config(char *path, t_config_data *config_data)
{
	read_config(path, config_data);
	return (0);
}