/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extract_rgb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:34:01 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/10 12:42:22 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_extract_one_rgb(char *info, int *rgb, int *i)
{
	int	start;

	start = *i;
	if (info[*i] < '0' && info[*i] > '9')
	{
		printf("Error\nRGB Format Invalid\n");
		return (0);
	}
	printf("i=%d\n", *i);
	while (info[*i] >= '0' && info[*i] <= '9')
		(*i)++;
	rgb[0] = ft_atoi(ft_substr(info, start, *i - start));
	if (rgb[0] < 0 || rgb[0] > 255)
		return (1);
	// passer les char apres les nombre
	return (0);
}

int	*check_extract_rgb(char *info)
{
	int *rgb;
	int i;

	i = 0;
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
		return (NULL);
	if (check_extract_one_rgb(info, &rgb[0], &i))
		return (NULL);
	if (check_extract_one_rgb(info, &rgb[1], &i))
		return (NULL);
	if (check_extract_one_rgb(info, &rgb[2], &i))
		return (NULL);
	printf("rgb[0]=%d\n", rgb[0]);
	printf("rgb[1]=%d\n", rgb[1]);
	printf("rgb[2]=%d\n", rgb[2]);
	return (rgb);
}