/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:52:59 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/18 14:44:51 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void my_mlx_pixel_put(t_data *data, int x, int y, t_pixel *color)
{
    t_pixel *dst;

    if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT) 
	return ;
    if (!data->img.addr) 
	return ;
    dst = (t_pixel*)(data->img.addr + (y * data->img.line_length + x * 4));
    *dst = *color;
}

void clear_img(t_img *img)
{
    int i;

    i = 0;
    while (i < WIN_WIDTH * WIN_HEIGHT)
    {
        img->addr[i++] = 0x000000;
        img->addr[i++] = 0x000000;
        img->addr[i++] = 0x000000;
        img->addr[i++] = 0;
    }
}

