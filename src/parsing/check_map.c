/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:38:45 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/22 16:50:02 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_error	check_map(t_data *data)
{
	t_error	error;

	error = check_save_hero(data);
	if (error.code != ERR_OK)
		return (error);
	error = check_map_structure(data);
	if (error.code != ERR_OK)
		return (error);
	return (error_ok());
}
