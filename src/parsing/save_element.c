/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:10:16 by prigaudi          #+#    #+#             */
/*   Updated: 2025/12/16 10:42:17 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	save_west_east(char *id, char *info, t_data *data)
{
	if (!ft_strncmp(id, "WE", 2) && !data->west_texture)
	{
		data->west_texture = info;
		data->nb_valid_elements++;
		return (0);
	}
	else if (!ft_strncmp(id, "EA", 2) && !data->east_texture)
	{
		data->east_texture = info;
		data->nb_valid_elements++;
		return (0);
	}
	return (1);
}

static int	save_north_south(char *id, char *info, t_data *data)
{
	if (!ft_strncmp(id, "NO", 2) && !data->north_texture)
	{
		data->north_texture = info;
		data->nb_valid_elements++;
		return (0);
	}
	else if (!ft_strncmp(id, "SO", 2) && !data->south_texture)
	{
		data->south_texture = info;
		data->nb_valid_elements++;
		return (0);
	}
	return (1);
}

static int	save_compass_element(char *id, char *info, t_data *data)
{
	if (!save_north_south(id, info, data))
		return (0);
	else if (!save_west_east(id, info, data))
		return (0);
	printf("Error\nDouble definition of a config element\n");
	return (1);
}

static int	save_ceiling_floor(char *id, char *info, t_data *data)
{
	if (!ft_strncmp(id, "F", 1) && !data->floor_rgb_color)
	{
		data->floor_rgb_color = check_extract_rgb(data, info);
		if (!data->floor_rgb_color)
			return (1);
		data->nb_valid_elements++;
		return (0);
	}
	else if (!ft_strncmp(id, "C", 1) && !data->ceiling_rgb_color)
	{
		data->ceiling_rgb_color = check_extract_rgb(data, info);
		if (!data->ceiling_rgb_color)
			return (1);
		data->nb_valid_elements++;
		return (0);
	}
	return (0);
}

int	save_element(char *id, char *info, t_data *data)
{
	if (!ft_strncmp(id, "NO", 2) || !ft_strncmp(id, "SO", 2) || !ft_strncmp(id,
			"WE", 2) || !ft_strncmp(id, "EA", 2))
	{
		if (save_compass_element(id, info, data))
			return (1);
	}
	else if (!ft_strncmp(id, "F", 1) || !ft_strncmp(id, "C", 1))
	{
		if (save_ceiling_floor(id, info, data))
			return (1);
	}
	return (0);
}
