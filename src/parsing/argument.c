/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:09:51 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/13 14:52:47 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_error	check_argument_number(int argc)
{
	t_error	error;

	if (argc != 2)
	{
		error.code = ERR_INVALID_ARG;
		error.message = "Error\nYou have to enter one and only one argument (path of the map)\n";
		return (error);
	}
	return (ERROR_OK);
}

static t_error	check_file_extension(char *path, t_parsing *data)
{
	char	*extension;
	size_t	len;
	t_error	error;

	extension = NULL;
	len = ft_strlen(path);
	if (len >= 5)
	{
		error = ft_substr(data, path, len - 4, len, &extension);
		if (error.code != ERR_OK)
			return (error);
		if (ft_strncmp(extension, ".cub", 4))
		{
			error.code = ERR_INVALID_ARG;
			error.message = "Error\nFilename must have .cub extension\n";
			return (error);
		}
	}
	else
	{
		error.code = ERR_INVALID_ARG;
		error.message = "Error\nFilename must have .cub extension\n";
		return (error);
	}
	return (ERROR_OK);
}

t_error	check_argument(int argc, char **argv, t_parsing *data)
{
	t_error	error;

	error = check_argument_number(argc);
	if (error.code != ERR_OK)
		return (error);
	error = check_file_extension(argv[1], data);
	if (error.code != ERR_OK)
		return (error);
	return (ERROR_OK);
}
