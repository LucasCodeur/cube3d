/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:51:37 by prigaudi          #+#    #+#             */
/*   Updated: 2025/12/16 10:41:43 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_line(char *line, t_data *data)
{
	if (data->nb_valid_elements < 6 && *line != '\n')
	{
		if (check_element_line(line, data))
			return (1);
	}
	else if (data->nb_valid_elements >= 6)
	{
		if (extract_save_map(line, data))
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

int	config(char *path, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = -1;
	if (check_file_opening(path, &fd))
		return (1);
	line = get_next_line(data, fd);
	if (!line)
	{
		printf("Error\nLine cannot be read\n");
		return (1);
	}
	while (line)
	{
		if (check_line(line, data))
			return (1);
		line = get_next_line(data, fd);
	}
	if (check_map(data))
		return (1);
	/*A SUPPRIMER*/
	printf("STRUCTURE:\n");
	printf("north_texture=%s\n", data->north_texture);
	printf("south_texture=%s\n", data->south_texture);
	printf("east_texture=%s\n", data->east_texture);
	printf("west_texture=%s\n", data->west_texture);
	printf("floor_rgb_color1=%d\n", data->floor_rgb_color[0]);
	printf("floor_rgb_color2=%d\n", data->floor_rgb_color[1]);
	printf("floor_rgb_color3=%d\n", data->floor_rgb_color[2]);
	printf("ceiling_rgb_color1=%d\n", data->ceiling_rgb_color[0]);
	printf("ceiling_rgb_color2=%d\n", data->ceiling_rgb_color[1]);
	printf("ceiling_rgb_color3=%d\n", data->ceiling_rgb_color[2]);
	printf("Nbre elements=%d\n", data->nb_valid_elements);
	printf("MAP:\n");
	printf("width=%d\n", data->map->width);
	printf("height=%d\n", data->map->height);
	i = 0;
	while (data->map->map_lines[i])
	{
		printf("%s", data->map->map_lines[i]);
		i++;
	}
	printf("HERO:\n");
	printf("pos x=%d\n", data->hero->x);
	printf("pos y=%d\n", data->hero->y);
	printf("orientation=%c\n", data->hero->orientation);
	/*A SUPPRIMER*/
	return (0);
}
