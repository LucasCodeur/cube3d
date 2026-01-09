/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:35:12 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/09 17:25:18 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	free_malloc(char **split, int j)
{
	int	i;

	i = j - 1;
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
}

static t_error	extract(t_parsing *config_data, char const *s, int start,
		int end, char *extracted_str)
{
	t_error	error;
	int		i;

	error = ft_malloc(&config_data->garbage, sizeof(char) * (end - start + 2),
			extracted_str);
	if (error.code != ERR_OK)
		return (error);
	i = 0;
	while (i + start <= end)
	{
		extracted_str[i] = s[start + i];
		i++;
	}
	extracted_str[i] = '\0';
	return (ERROR_OK);
}

static int	char_count(char const *s, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			counter++;
		}
		i++;
	}
	return (counter);
}

static t_error	test_str(char **split, int j)
{
	t_error	error;

	if (split[j] == NULL)
	{
		free_malloc(split, j);
		error.code = ERR_FAIL;
		error.message = "split failed";
		return (error);
	}
	return (ERROR_OK);
}

t_error	ft_split(t_parsing *cd, char const *s, char c, char **split)
{
	t_error	error;
	int		start;
	int		i;
	int		j;

	error = ft_malloc(&cd->garbage, sizeof(char *) * (char_count(s, c) + 1),
			split);
	if (error.code != ERR_OK)
		return (error);
	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i + 1] != c && s[i + 1] != '\0')
				i++;
			error = extract(cd, s, start, i, split[j]);
			if (error.code != ERR_OK)
				return (error);
			error = test_str(split, j++);
			if (error.code != ERR_OK)
				return (error);
		}
		i++;
	}
	split[j] = NULL;
	return (ERROR_OK);
}
