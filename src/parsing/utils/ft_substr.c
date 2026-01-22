/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:57:57 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/22 16:49:22 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_error	ft_substr(t_data *data, t_substr_io *substr_io, unsigned int start,
		size_t len)
{
	size_t	i;
	t_error	error;

	if (start >= ft_strlen(substr_io->in))
	{
		error = ft_calloc(1, 1, &substr_io->out);
		if (error.code != ERR_OK)
			return (error);
		return (error_ok());
	}
	if (len > ft_strlen(substr_io->in) - start)
		len = ft_strlen(substr_io->in) - start;
	error = ft_malloc(&data->garbage, sizeof(char) * len + 1,
			(void **)&substr_io->out);
	if (error.code != ERR_OK)
		return (error);
	i = 0;
	while (substr_io->in[start + i] != '\0' && i < len)
	{
		(substr_io->out)[i] = substr_io->in[start + i];
		i++;
	}
	(substr_io->out)[i] = '\0';
	return (error_ok());
}
