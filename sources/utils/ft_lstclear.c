/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:29:44 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/17 10:42:07 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_lstclear(t_garbage **lst, void (*del)(void *))
{
	t_garbage	*tamp;

	while (*lst)
	{
		(*del)((*lst)->ptr);
		tamp = *lst;
		*lst = (*lst)->next;
		free(tamp);
	}
	lst = NULL;
}
