/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:23:36 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/22 16:49:22 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_error	ft_lstnew(void *ptr, t_garbage **new)
{
	t_error	error;

	*new = malloc(sizeof(t_garbage));
	if (!new)
	{
		error.code = ERR_MEMORY;
		error.message = "Malloc of new in ft_lstnew failed\n";
		return (error);
	}
	(*new)->ptr = ptr;
	(*new)->next = NULL;
	return (error_ok());
}
