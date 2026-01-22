/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:35:12 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/22 16:49:22 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_error	extract(t_data *config_data, char const *s,
		t_split_variable var, char **extracted_str)
{
	t_error	error;
	int		j;

	error = ft_malloc(&config_data->garbage, sizeof(char) * (var.i - var.start
				+ 2), (void **)extracted_str);
	if (error.code != ERR_OK)
		return (error);
	j = 0;
	while (j + var.start <= var.i)
	{
		(*extracted_str)[j] = s[var.start + j];
		j++;
	}
	(*extracted_str)[j] = '\0';
	return (error_ok());
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

t_error	ft_split(t_data *cd, char const *s, char c, char ***split)
{
	t_error				error;
	t_split_variable	split_var;

	error = ft_malloc(&cd->garbage, sizeof(char *) * (char_count(s, c) + 1),
			(void **)split);
	if (error.code != ERR_OK)
		return (error);
	split_var.j = 0;
	split_var.i = -1;
	while (s[++split_var.i] != '\0')
	{
		if (s[split_var.i] != c)
		{
			split_var.start = split_var.i;
			while (s[split_var.i + 1] != c && s[split_var.i + 1] != '\0')
				split_var.i++;
			error = extract(cd, s, split_var, &(*split)[split_var.j++]);
			if (error.code != ERR_OK)
				return (error);
		}
	}
	(*split)[split_var.j] = NULL;
	return (error_ok());
}
