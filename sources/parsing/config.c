/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:51:37 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/14 13:23:37 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_line(char *line, t_config_data *config_data)
{
	if (config_data->nb_valid_elements < 6 && *line != '\n')
	{
		if (check_element_line(line, config_data))
			return (1);
	}
	else if (config_data->nb_valid_elements >= 6)
	{
		if (extract_save_map(line, config_data))
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
		// free
		return (1);
	}
	return (0);
}

int	config(char *path, t_config_data *config_data)
{
	int		fd;
	char	*line;
	int		i;

	fd = -1;
	if (check_file_opening(path, &fd))
		return (1);
	line = get_next_line(fd);
	if (!line)
	{
		printf("Error\nLine cannot be read\n");
		// free
		return (1);
	}
	while (line)
	{
		if (check_line(line, config_data))
			return (1);
		free(line);
		line = get_next_line(fd);
	}
	if (check_map(config_data))
		return (1);
	/*A SUPPRIMER*/
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
	printf("MAP:\n");
	printf("width=%d\n", config_data->map->width);
	printf("height=%d\n", config_data->map->height);
	i = 0;
	while (config_data->map->map_lines[i])
	{
		printf("%s", config_data->map->map_lines[i]);
		i++;
	}
	printf("HERO:\n");
	printf("pos x=%d\n", config_data->hero->x);
	printf("pos y=%d\n", config_data->hero->y);
	printf("orientation=%c\n", config_data->hero->orientation);
	/*A SUPPRIMER*/
	return (0);
}
