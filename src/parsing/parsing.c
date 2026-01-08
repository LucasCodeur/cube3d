/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:10:45 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/08 12:07:14 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h" 

int	parsing(int argc, char **argv, t_parsing *data)
{
	if (check_argument(argc, argv, data))
		return (1);
	if (config(argv[1], data))
		return (1);
	return (0);
}
