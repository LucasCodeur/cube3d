/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:10:16 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/21 11:29:53 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	save_west_east(char *id, char *info, t_config_data *config_data)
{
	if (!ft_strncmp(id, "WE", 2) && !config_data->west_texture)
	{
		config_data->west_texture = info;
		config_data->nb_valid_elements++;
		return (0);
	}
	else if (!ft_strncmp(id, "EA", 2) && !config_data->east_texture)
	{
		config_data->east_texture = info;
		config_data->nb_valid_elements++;
		return (0);
	}
	return (1);
}

static int	save_north_south(char *id, char *info, t_config_data *config_data)
{
	if (!ft_strncmp(id, "NO", 2) && !config_data->north_texture)
	{
		config_data->north_texture = info;
		config_data->nb_valid_elements++;
		return (0);
	}
	else if (!ft_strncmp(id, "SO", 2) && !config_data->south_texture)
	{
		config_data->south_texture = info;
		config_data->nb_valid_elements++;
		return (0);
	}
	return (1);
}

static int	save_compass_element(char *id, char *info,
		t_config_data *config_data)
{
	if (!save_north_south(id, info, config_data))
		return (0);
	else if (!save_west_east(id, info, config_data))
		return (0);
	printf("Error\nDouble definition of a config element\n");
	return (1);
}

static int	save_ceiling_floor(char *id, char *info, t_config_data *config_data)
{
	if (!ft_strncmp(id, "F", 1) && !config_data->floor_rgb_color)
	{
		config_data->floor_rgb_color = check_extract_rgb(config_data, info);
		if (!config_data->floor_rgb_color)
			return (1);
		config_data->nb_valid_elements++;
		return (0);
	}
	else if (!ft_strncmp(id, "C", 1) && !config_data->ceiling_rgb_color)
	{
		config_data->ceiling_rgb_color = check_extract_rgb(config_data, info);
		if (!config_data->ceiling_rgb_color)
			return (1);
		config_data->nb_valid_elements++;
		return (0);
	}
	return (0);
}

int	save_element(char *id, char *info, t_config_data *config_data)
{
	if (!ft_strncmp(id, "NO", 2) || !ft_strncmp(id, "SO", 2) || !ft_strncmp(id,
			"WE", 2) || !ft_strncmp(id, "EA", 2))
	{
		if (save_compass_element(id, info, config_data))
			return (1);
	}
	else if (!ft_strncmp(id, "F", 1) || !ft_strncmp(id, "C", 1))
	{
		if (save_ceiling_floor(id, info, config_data))
			return (1);
	}
	return (0);
}
