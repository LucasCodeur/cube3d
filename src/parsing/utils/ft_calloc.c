/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:34:41 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/06 11:07:55 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void			*ptr;
	unsigned char	*tamp;
	size_t			i;

	ptr = malloc(elementCount * elementSize);
	if (ptr == NULL)
		return (NULL);
	tamp = (unsigned char *)ptr;
	i = 0;
	while (i < elementCount * elementSize)
	{
		tamp[i] = '\0';
		i++;
	}
	return (ptr);
}
