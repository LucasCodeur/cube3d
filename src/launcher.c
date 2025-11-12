/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:28:43 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/12 17:34:39 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

#include  <mlx.h>

void	launcher(t_data *data)
{
	init_screen_mlx(data);
	data->img = fill_image(data, "/home/lud-adam/Documents/cube3d/assets/textures/basic/coin.xpm");
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->img.img, 10, 10);
	mlx_loop(data->mlx.mlx);
}
