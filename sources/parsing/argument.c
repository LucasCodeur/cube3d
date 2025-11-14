/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:09:51 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/14 13:22:44 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_argument_number(int argc)
{
	if (argc != 2)
	{
		printf("Error\nYou have to enter one and only one argument (path of the map)\n");
		// free
		return (1);
	}
	return (0);
}

static int	check_file_extension(char *path)
{
	char	*extension;
	size_t	len;

	len = ft_strlen(path);
	if (len >= 5)
	{
		extension = ft_substr(path, len - 4, len);
		if (ft_strncmp(extension, ".cub", 4))
		{
			printf("Error\nFilename must have .cub extension\n");
			// free
			return (1);
		}
	}
	else
	{
		printf("Error\nFilename must have .cub extension\n");
		// free
		return (1);
	}
	return (0);
}

int	check_argument(int argc, char **argv)
{
	if (check_argument_number(argc))
		return (1);
	if (check_file_extension(argv[1]))
		return (1);
	return (0);
}