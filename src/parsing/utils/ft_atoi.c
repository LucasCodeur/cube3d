/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:27:56 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/21 14:50:28 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	check_limit(const char *str, int result, int i, int c)
{
	if (c == 1)
	{
		if (result > (INT_MAX - str[i] + 48) / 10)
			return (0);
	}
	else
	{
		if (-result < (INT_MIN + str[i] - 48) / 10)
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	c;
	int	result;

	result = 0;
	i = 0;
	c = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		if (str[i] == '-')
			c = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (!check_limit(str, result, i, c))
			return (0);
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (c * result);
}
