/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:32:09 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/17 14:08:16 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*ft_malloc(t_garbage **garbage, int size)
{
	void		*ptr;
	t_garbage	*new;

	ptr = malloc(size);
	if (!ptr)
	{
		printf("Error\nMalloc of ptr failed\n");
		return (NULL);
	}
	new = ft_lstnew(ptr);
	ft_lstadd_front(garbage, new);
	return (ptr);
}
