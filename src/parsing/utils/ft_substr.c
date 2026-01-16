/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:57:57 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/16 09:14:19 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_error	ft_substr(t_data *data, char const *s, unsigned int start, size_t len,
		char **str)
{
	size_t	i;
	t_error	error;

	if (start >= ft_strlen(s))
	{
		error = ft_calloc(1, 1, str);
		if (error.code != ERR_OK)
			return (error);
		return (ERROR_OK);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	error = ft_malloc(&data->garbage, sizeof(char) * len + 1, (void **)str);
	if (error.code != ERR_OK)
		return (error);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		(*str)[i] = s[start + i];
		i++;
	}
	(*str)[i] = '\0';
	return (ERROR_OK);
}
