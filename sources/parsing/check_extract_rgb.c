/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extract_rgb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:54:18 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/18 14:54:35 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	test_rgb_value(int value)
{
	if (value < 0 || value > 255)
	{
		printf("Error\nRGB Format Invalid\n");
		return (1);
	}
	return (0);
}

int	*check_extract_rgb(t_config_data *config_data, char *info)
{
	char	**rgb_str;
	int		*rgb_int;
	int		i;

	i = 0;
	rgb_str = ft_split(config_data, info, ',');
	if (!rgb_str)
	{
		printf("Error\nProblem with split in check_extract_rgb\n");
		return (NULL);
	}
	rgb_int = ft_malloc(&config_data->garbage, sizeof(int) * (3 + 1));
	if (!rgb_int)
	{
		printf("Error\nProblem with malloc in check_extract_rgb\n");
		return (NULL);
	}
	while (*rgb_str)
	{
		if (i > 3)
		{
			printf("Error\nRGB Format Invalid\n");
			return (NULL);
		}
		rgb_int[i] = ft_atoi(*rgb_str);
		if (test_rgb_value(rgb_int[i]))
			return (NULL);
		i++;
		rgb_str++;
	}
	rgb_int[i] = 0;
	return (rgb_int);
}
