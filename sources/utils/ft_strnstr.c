/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:33:41 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/06 10:26:11 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	unsigned long	i;
	unsigned long	j;
	char			*ptr;

	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0' && i < len)
	{
		j = 0;
		ptr = (char *)&(s1[i]);
		while (s2[j] != '\0' && (i + j) < len)
		{
			if (s1[i + j] == s2[j])
			{
				j++;
				if (s2[j] == '\0')
					return (ptr);
			}
			else
				break ;
		}
		i++;
	}
	return (NULL);
}
