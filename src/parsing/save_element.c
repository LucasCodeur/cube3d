/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:10:16 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/26 13:28:18 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	save_west_east(char *id, char *info, t_parsing *data)
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

static int	save_north_south(char *id, char *info, t_parsing *data)
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

static t_error	save_compass_element(char *id, char *info, t_parsing *data)
{
	t_error	error;

	if (!save_north_south(id, info, data))
		return (error_ok());
	else if (!save_west_east(id, info, data))
		return (error_ok());
	error.code = ERR_INVALID_ARG;
	error.message = "Double definition of a config element\n";
	return (error);
}

static t_error	save_ceiling_floor(char *id, char *info, t_data *data)
{
	t_error	error;

	if (!ft_strncmp(id, "F", 1) && !data->parsing->floor_rgb_color)
	{
		error = check_extract_rgb(data, info,
				&(data->parsing->floor_rgb_color));
		if (error.code != ERR_OK)
			return (error);
		data->parsing->nb_valid_elements++;
		return (error_ok());
	}
	else if (!ft_strncmp(id, "C", 1) && !data->parsing->ceiling_rgb_color)
	{
		error = check_extract_rgb(data, info,
				&(data->parsing->ceiling_rgb_color));
		if (error.code != ERR_OK)
			return (error);
		data->parsing->nb_valid_elements++;
		return (error_ok());
	}
	error.code = ERR_INVALID_ARG;
	error.message = "Double definition of a config element\n";
	return (error);
}

t_error	save_element(char *id, char *info, t_data *data)
{
	t_error	error;

	if (!ft_strncmp(id, "NO", 2) || !ft_strncmp(id, "SO", 2) || !ft_strncmp(id,
			"WE", 2) || !ft_strncmp(id, "EA", 2))
	{
		error = save_compass_element(id, info, data->parsing);
		if (error.code != ERR_OK)
			return (error);
	}
	else if (!ft_strncmp(id, "F", 1) || !ft_strncmp(id, "C", 1))
	{
		error = save_ceiling_floor(id, info, data);
		if (error.code != ERR_OK)
			return (error);
	}
	return (error_ok());
}
