/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:52:59 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/21 15:01:34 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, t_pixel *color)
{
	t_pixel	*dst;

	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return ;
	if (!data->img.addr)
		return ;
	dst = (t_pixel *)(data->img.addr + (y * data->img.line_length + x * 4));
	*dst = *color;
}
