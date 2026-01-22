/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:46:38 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/20 13:47:33 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	loop(char **str, char **s1, char *s2, int byte_nbr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s1 && (*s1)[j])
		(*str)[i++] = (*s1)[j++];
	j = 0;
	while (s2 && s2[j] && j < byte_nbr)
		(*str)[i++] = s2[j++];
	(*str)[i] = '\0';
}

t_error	ft_strnjoin(t_data *data, char **s1, char *s2, int byte_nbr)
{
	char	*str;
	t_error	error;

	str = NULL;
	if (!(*s1) && byte_nbr == 0)
	{
		error.code = ERR_FAIL;
		error.message = "ft_strnjoin failed";
		return (error);
	}
	if (!(*s1))
		error = ft_malloc(&data->garbage, byte_nbr + 1, (void **)&str);
	else
		error = ft_malloc(&data->garbage, sizeof(char) * (ft_strlen(*s1)
					+ byte_nbr + 1), (void **)&str);
	if (error.code != ERR_OK)
		return (error);
	loop(&str, s1, s2, byte_nbr);
	(*s1) = str;
	return (ERROR_OK);
}
