/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:36:26 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/17 11:25:08 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_lstadd_front(t_garbage **lst, t_garbage *new)
{
	t_garbage	*tamp;

	tamp = *lst;
	*lst = new;
	(*lst)->next = tamp;
}
