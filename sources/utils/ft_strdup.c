/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:43:04 by prigaudi          #+#    #+#             */
/*   Updated: 2025/12/16 10:44:56 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strdup(t_data *data, const char *str)
{
	char	*result;
	int		i;
	int		len;

	len = ft_strlen(str);
	result = ft_malloc(&data->garbage, sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = (unsigned char)str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
