/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:10:45 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/09 13:46:20 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_error	parsing(int argc, char **argv, t_parsing *data)
{
	t_error	error;

	error = check_argument(argc, argv, data);
	if (error.code != ERR_OK)
		return (error);
	error = config(argv[1], data);
	if (error.code != ERR_OK)
		return (error);
	return (ERROR_OK);
}
