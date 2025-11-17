/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:43:04 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/17 13:03:44 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strdup(t_config_data *config_data, const char *str)
{
	char	*result;
	int		i;
	int		len;

	len = ft_strlen(str);
	result = ft_malloc(&config_data->garbage, sizeof(char) * (len + 1));
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
