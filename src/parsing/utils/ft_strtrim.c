/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:57:02 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/16 09:16:54 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	index_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (set[j] == s1[i])
			{
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
		{
			return (i);
		}
		i++;
	}
	return (i);
}

static int	index_end(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (set[j] == s1[i])
			{
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
		{
			return (i);
		}
		i--;
	}
	return (i);
}

// Remove characters stored in set at the beginning and the end of s1
t_error	ft_strtrim(t_data *data, char const *s1, char const *set, char **str)
{
	t_error	error;
	int		start;
	int		end;
	int		i;

	start = index_start(s1, set);
	end = index_end(s1, set);
	if (start > end)
	{
		error = ft_calloc(1, 1, str);
		if (error.code != ERR_OK)
			return (error);
	}
	error = ft_malloc(&data->garbage, sizeof(char) * end - start + 2,
			(void **)str);
	if (error.code != ERR_OK)
		return (error);
	i = 0;
	while (i < end - start + 1)
	{
		(*str)[i] = s1[start + i];
		i++;
	}
	(*str)[i] = '\0';
	return (ERROR_OK);
}
