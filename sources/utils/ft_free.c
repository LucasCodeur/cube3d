/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:09:35 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/17 14:35:10 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_all(t_config_data *config_data)
{
	t_garbage	*tamp;

	if (config_data)
	{
		while (config_data->garbage)
		{
			free(config_data->garbage->ptr);
			tamp = config_data->garbage;
			config_data->garbage = config_data->garbage->next;
			free(tamp);
		}
		config_data->garbage = NULL;
		free(config_data);
	}
	return ;
}
