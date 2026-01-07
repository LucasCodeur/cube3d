/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extract_rgb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:54:18 by prigaudi          #+#    #+#             */
/*   Updated: 2025/12/16 10:40:55 by prigaudi         ###   ########.fr       */
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

static int	rgb_loop(char **rgb_str, int *rgb_int)
{
	int	i;

	i = 0;
	while (rgb_str[i])
	{
		if (i > 3)
		{
			printf("Error\nRGB format invalid\n");
			return (1);
		}
		rgb_int[i] = ft_atoi(rgb_str[i]);
		if (test_rgb_value(rgb_int[i]))
			return (1);
		i++;
	}
	if (i < 3)
	{
		printf("Error\nRGB format invalid\n");
		return (1);
	}
	rgb_int[i] = 0;
	return (0);
}

static int	loop_digit_or_space(char **rgb_str, int i, int *one_digit)
{
	int	j;

	j = 0;
	while (rgb_str[i][j])
	{
		if ((rgb_str[i][j] < '0' || rgb_str[i][j] > '9')
			&& rgb_str[i][j] != ' ')
		{
			printf("Error\nRGB format invalid. You must have only digits\n");
			return (1);
		}
		else if (rgb_str[i][j] >= '0' && rgb_str[i][j] <= '9')
			*one_digit = 1;
		j++;
	}
	return (0);
}

static int	is_digit_or_space(char **rgb_str)
{
	int	i;
	int	one_digit;

	i = 0;
	while (rgb_str[i])
	{
		one_digit = 0;
		if (loop_digit_or_space(rgb_str, i, &one_digit))
			return (1);
		if (!one_digit)
		{
			printf("Error\nRGB format invalid\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	*check_extract_rgb(t_data *data, char *info)
{
	char	**rgb_str;
	int		*rgb_int;

	rgb_str = ft_split(data, info, ',');
	if (!rgb_str)
	{
		printf("Error\nProblem with split in check_extract_rgb\n");
		return (NULL);
	}
	if (is_digit_or_space(rgb_str))
		return (NULL);
	rgb_int = ft_malloc(&data->garbage, sizeof(int) * (3 + 1));
	if (!rgb_int)
	{
		printf("Error\nProblem with malloc in check_extract_rgb\n");
		return (NULL);
	}
	if (rgb_loop(rgb_str, rgb_int))
		return (NULL);
	return (rgb_int);
}
