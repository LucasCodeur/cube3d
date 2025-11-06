/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:06:01 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/06 16:25:51 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_config_data *config_data;

	config_data = init_config_data();
	if (!config_data)
		return (1);
	if (parsing(argc, argv, config_data))
		return (1);
	return (0);
}