/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:34:41 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/09 15:36:15 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_error	ft_calloc(size_t elementCount, size_t elementSize, char *str)
{
	t_error			error;
	unsigned char	*tamp;
	size_t			i;

	str = malloc(elementCount * elementSize);
	if (!str)
	{
		error.code = ERR_MEMORY;
		error.message = "Malloc of str in ft_calloc failed\n";
		return (error);
	}
	tamp = (unsigned char *)str;
	i = 0;
	while (i < elementCount * elementSize)
	{
		tamp[i] = '\0';
		i++;
	}
	return (ERROR_OK);
}
