/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:42:40 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/21 16:24:47 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static void	put_pixel(t_img *img, int x, int y, t_pixel color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	dst = (char *)img->addr + (y * img->line_length + x * (img->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color.value;
}

void	draw_square(t_data *data, t_drawing_infos drawing_infos, t_pixel color)
{
	int	i;
	int	j;

	j = 0;
	while (j < drawing_infos.size)
	{
		i = 0;
		while (i < drawing_infos.size)
		{
			put_pixel(&data->img, drawing_infos.x + i, drawing_infos.y + j,
				color);
			i++;
		}
		j++;
	}
}
