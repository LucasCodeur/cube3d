/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:10:16 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/10 17:11:06 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	save_compass_element(char *id, char *info,
		t_config_data *config_data)
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
	else if (!ft_strncmp(id, "WE", 2) && !config_data->west_texture)
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

static int	*check_extract_rgb(char *info)
{
	char	**rgb_str;
	int		*rgb_int;
	int		i;

	i = 0;
	rgb_str = ft_split(info, ',');
	if (!rgb_str)
		return (NULL);
	rgb_int = malloc(sizeof(int) * 3 + 1);
	if (!rgb_int)
		return (NULL);
	while (*rgb_str)
	{
		if (i > 3)
		{
			printf("Err000or\nRGB Format Invalid\n");
			return (NULL);
		}
		rgb_int[i] = ft_atoi(*rgb_str);
		if (rgb_int[i] < 0 || rgb_int[i] > 255)
		{
			printf("Error\nRGB Format Invalid\n");
			return (NULL);
		}
		i++;
		rgb_str++;
	}
	return (rgb_int);
}

static int	save_ceiling_floor(char *id, char *info, t_config_data *config_data)
{
	if (!ft_strncmp(id, "F", 1) && !config_data->floor_rgb_color)
	{
		config_data->floor_rgb_color = check_extract_rgb(info);
		if (!config_data->floor_rgb_color)
			return (1);
		config_data->nb_valid_elements++;
		return (0);
	}
	else if (!ft_strncmp(id, "C", 1) && !config_data->ceiling_rgb_color)
	{
		config_data->ceiling_rgb_color = check_extract_rgb(info);
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
