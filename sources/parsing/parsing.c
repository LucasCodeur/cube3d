/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:10:45 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/18 13:46:08 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parsing(int argc, char **argv, t_config_data *config_data)
{
	if (check_argument(argc, argv, config_data))
		return (1);
	if (config(argv[1], config_data))
		return (1);
	return (0);
}
