/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:43:04 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/13 16:21:21 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_error	ft_strdup(t_parsing *data, const char *str, char **result)
{
	int		len;
	t_error	error;
	int		i;

	len = ft_strlen(str);
	error = ft_malloc(&data->garbage, sizeof(char) * (len + 1),
			(void **)result);
	if (error.code != ERR_OK)
		return (error);
	i = 0;
	while (i < len)
	{
		*result[i] = (unsigned char)str[i];
		i++;
	}
	*result[i] = '\0';
	return (ERROR_OK);
}
