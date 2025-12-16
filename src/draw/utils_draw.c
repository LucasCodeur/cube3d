/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:52:59 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/11 11:53:25 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void my_mlx_pixel_put_minimap(t_data *data, int x, int y, t_pixel *color)
{
    t_pixel *dst;

    if (x < 0 || x > WIDTH_MINIMAP || y < 0 || y > HEIGHT_MINIMAP) 
	return ;
    if (!data->img.addr) 
	return ;
    dst = (t_pixel*)(data->img.addr + (y * data->img.line_length + x * 4));
    *dst = *color;
}
