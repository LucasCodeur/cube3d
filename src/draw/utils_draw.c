/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:52:59 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/22 16:26:07 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	fill_color(t_pixel *color, int *rgb)
{
	color->channels[0] = rgb[2];
	color->channels[1] = rgb[1];
	color->channels[2] = rgb[0];
	color->channels[3] = 255;
}
