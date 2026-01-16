/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:09:35 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/16 10:36:39 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_all(t_data *data)
{
	t_garbage	*tamp;

	if (data)
	{
		while (data->garbage)
		{
			free(data->garbage->ptr);
			tamp = data->garbage;
			data->garbage = data->garbage->next;
			free(tamp);
		}
		data->garbage = NULL;
	}
	return ;
}
