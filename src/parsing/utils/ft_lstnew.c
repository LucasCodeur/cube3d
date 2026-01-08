/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:23:36 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/17 10:42:56 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_garbage	*ft_lstnew(void *ptr)
{
	t_garbage	*new;

	new = malloc(sizeof(t_garbage));
	if (new == NULL)
		return (NULL);
	new->ptr = ptr;
	new->next = NULL;
	return (new);
}
