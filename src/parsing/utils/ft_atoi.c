/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:27:56 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/27 09:14:19 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_error	check_limit(const char *str, int result, int i, int c)
{
	t_error	error;

	if (c == 1)
	{
		if (result > (INT_MAX - str[i] + 48) / 10)
		{
			error.code = ERR_INVALID_ARG;
			error.message = "Overflow detected in RGB color\n";
			return (error);
		}
	}
	else
	{
		if (-result < (INT_MIN + str[i] - 48) / 10)
		{
			error.code = ERR_INVALID_ARG;
			error.message = "Overflow detected in RGB color\n";
			return (error);
		}
	}
	return (error_ok());
}

t_error	test_sign(const char *str, int *c, int *i)
{
	t_error	error;

	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i + 1] == '-' || str[*i + 1] == '+')
		{
			error.code = ERR_INVALID_ARG;
			error.message = "RGB format invalid\n";
			return (error);
		}
		if (str[*i] == '-')
			*c = -1;
		(*i)++;
	}
	return (error_ok());
}

t_error	ft_atoi(const char *str, int *result)
{
	int		c;
	t_error	error;
	int		i;

	*result = 0;
	i = 0;
	c = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	error = test_sign(str, &c, &i);
	if (error.code != ERR_OK)
		return (error);
	while (str[i] >= '0' && str[i] <= '9')
	{
		error = check_limit(str, *result, i, c);
		if (error.code != ERR_OK)
			return (error);
		*result = *result * 10 + str[i] - 48;
		i++;
	}
	*result = c * (*result);
	return (error_ok());
}
