/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:10:20 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/12 17:26:28 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>

t_img	fill_image(t_data* data, char *path_to_asset)
{
	t_img	img;
	int		x;
	int		y;

	img.img = mlx_xpm_file_to_image(data->mlx.mlx, path_to_asset, &x, &y);
	if (!img.img)
	{
		perror("Error: Image not create\n");
		exit(1);
	}
	return (img);
}
