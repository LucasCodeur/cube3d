/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:51:37 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/09 17:24:24 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_error	check_line(char *line, t_parsing *data)
{
	t_error	error;

	if (data->nb_valid_elements < 6 && *line != '\n')
	{
		error = check_element_line(line, data);
		if (error.code != ERR_OK)
			return (error);
	}
	else if (data->nb_valid_elements >= 6)
	{
		error = extract_save_map(line, data);
		if (error.code != ERR_OK)
			return (error);
	}
	return (ERROR_OK);
}

static t_error	check_file_opening(char *path, int *fd)
{
	t_error	error;

	*fd = open(path, O_RDONLY);
	if (*fd == -1)
	{
		error.code = ERR_IO;
		error.message = "Config file cant be opened";
		return (error);
	}
	return (ERROR_OK);
}

t_error	config(char *path, t_parsing *data)
{
	int		fd;
	char	*line;
	int		i;
	t_error	error;

	fd = -1;
	error = check_file_opening(path, &fd);
	if (error.code != ERR_OK)
		return (error);
	error = get_next_line(data, fd, line);
	if (error.code != ERR_OK)
		return (error);
	while (line)
	{
		error = check_line(line, data);
		if (error.code != ERR_OK)
			return (error);
		error = get_next_line(data, fd, line);
		if (error.code != ERR_OK)
			return (error);
	}
	error = check_map(data);
	if (error.code != ERR_OK)
		return (error);
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
	while (data->map->grid[i])
	{
		printf("%s", data->map->grid[i]);
		i++;
	}
	printf("HERO:\n");
	printf("pos x=%d\n", data->map->player.x);
	printf("pos y=%d\n", data->map->player.y);
	printf("orientation=%c\n", data->map->player.orientation);
	/*A SUPPRIMER*/
	return (ERROR_OK);
}
