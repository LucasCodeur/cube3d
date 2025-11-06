/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:26:50 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/06 16:25:33 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_config_data	*init_config_data(void)
{
	t_config_data	*config_data;

	config_data = malloc(sizeof(t_config_data));
	if (!config_data)
	{
		printf("Error\nMalloc of config_data failed\n");
		return (NULL);
	}
	config_data->nb_valid_elements = 0;
	config_data->config_is_valid = 0;
	return (config_data);
}
