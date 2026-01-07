/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:10:45 by prigaudi          #+#    #+#             */
/*   Updated: 2025/12/16 10:42:04 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parsing(int argc, char **argv, t_data *data)
{
	if (check_argument(argc, argv, data))
		return (1);
	if (config(argv[1], data))
		return (1);
	return (0);
}
