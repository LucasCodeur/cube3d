/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extract_rgb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:54:18 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/15 10:13:19 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_error	test_rgb_value(int value)
{
	t_error	error;

	if (value < 0 || value > 255)
	{
		error.code = ERR_FAIL;
		error.message = "RGB Format Invalid\n";
		return (error);
	}
	return (ERROR_OK);
}

static t_error	rgb_loop(char **rgb_str, int **rgb_int)
{
	t_error	error;
	int		i;

	i = 0;
	while (rgb_str[i])
	{
		if (i > 3)
		{
			error.code = ERR_FAIL;
			error.message = "RGB format invalid\n";
			return (error);
		}
		(*rgb_int)[i] = ft_atoi(rgb_str[i]);
		error = test_rgb_value((*rgb_int)[i]);
		if (error.code != ERR_OK)
			return (error);
		i++;
	}
	if (i < 3)
	{
		error.code = ERR_FAIL;
		error.message = "RGB format invalid\n";
		return (error);
	}
	(*rgb_int)[i] = 0;
	return (ERROR_OK);
}

static t_error	loop_digit_or_space(char **rgb_str, int i, int *one_digit)
{
	t_error	error;
	int		j;

	j = 0;
	while (rgb_str[i][j])
	{
		if ((rgb_str[i][j] < '0' || rgb_str[i][j] > '9')
			&& rgb_str[i][j] != ' ')
		{
			error.code = ERR_FAIL;
			error.message = "RGB format invalid. You must have only digits\n";
			return (error);
		}
		else if (rgb_str[i][j] >= '0' && rgb_str[i][j] <= '9')
			*one_digit = 1;
		j++;
	}
	return (ERROR_OK);
}

static t_error	is_digit_or_space(char **rgb_str)
{
	t_error	error;
	int		i;
	int		one_digit;

	i = 0;
	while (rgb_str[i])
	{
		one_digit = 0;
		error = loop_digit_or_space(rgb_str, i, &one_digit);
		if (error.code != ERR_OK)
			return (error);
		if (!one_digit)
		{
			error.code = ERR_FAIL;
			error.message = "RGB format invalid\n";
			return (error);
		}
		i++;
	}
	return (ERROR_OK);
}

t_error	check_extract_rgb(t_parsing *data, char *info, int **rgb_int)
{
	t_error	error;
	char	**rgb_str;

	rgb_str = NULL;
	error = ft_split(data, info, ',', &rgb_str);
	if (error.code != ERR_OK)
		return (error);
	error = is_digit_or_space(rgb_str);
	if (error.code != ERR_OK)
		return (error);
	error = ft_malloc(&data->garbage, sizeof(int) * (3 + 1),
			(void **)&(*rgb_int));
	if (error.code != ERR_OK)
		return (error);
	error = rgb_loop(rgb_str, rgb_int);
	if (error.code != ERR_OK)
		return (error);
	return (ERROR_OK);
}
