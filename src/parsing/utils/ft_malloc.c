/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:32:09 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/13 17:43:23 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_error	ft_malloc(t_garbage **garbage, int size, void **str)
{
	t_garbage	*new;
	t_error		error;

	*str = malloc(size);
	if (!*str)
	{
		error.code = ERR_MEMORY;
		error.message = "Malloc of str in ft_malloc failed\n";
		return (error);
	}
	ft_lstnew(*str, &new);
	ft_lstadd_front(garbage, new);
	return (ERROR_OK);
}
