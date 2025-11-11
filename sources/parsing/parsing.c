/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:10:45 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/11 13:02:51 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parsing(int argc, char **argv, t_config_data *config_data)
{
	if (check_argument(argc, argv))
		return (1);
	if (config(argv[1], config_data))
		return (1);
	return (0);
}