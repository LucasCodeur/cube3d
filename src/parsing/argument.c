/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:09:51 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/20 16:46:17 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_error	check_argument_number(int argc)
{
	t_error	error;

	if (argc != 2)
	{
		error.code = ERR_INVALID_ARG;
		error.message = "You have to enter one and only one argument\n";
		return (error);
	}
	return (ERROR_OK);
}

static t_error	check_file_extension(char *path, t_data *data)
{
	size_t		len;
	t_error		error;
	t_substr_io	substr_io;

	len = ft_strlen(path);
	if (len >= 5)
	{
		substr_io.in = path;
		error = ft_substr(data, &substr_io, len - 4, len);
		if (error.code != ERR_OK)
			return (error);
		if (ft_strncmp(substr_io.out, ".cub", 4))
		{
			error.code = ERR_INVALID_ARG;
			error.message = "Filename must have .cub extension\n";
			return (error);
		}
	}
	else
	{
		error.code = ERR_INVALID_ARG;
		error.message = "Filename must have .cub extension\n";
		return (error);
	}
	return (ERROR_OK);
}

t_error	check_argument(int argc, char **argv, t_data *data)
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
