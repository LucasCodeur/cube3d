/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:46:38 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/06 16:12:52 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strnjoin(char *s1, char *s2, int byte_nbr)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 && byte_nbr == 0)
		return (NULL);
	if (!s1)
		str = malloc(byte_nbr + 1);
	else
		str = malloc(sizeof(char) * (ft_strlen(s1) + byte_nbr + 1));
	if (str == NULL)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1 && s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j] && j < byte_nbr)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
