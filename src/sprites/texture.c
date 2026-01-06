/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:55:13 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/06 19:56:53 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

/**
* @brief allow to choose which texture according side and the direction of the ray
* @param all informatio about the program
* @return the texture to display
*/
t_img choose_texture(t_data *data)
{
	if (data->side == 0)
	{
		if (data->ray_dir.elements[0] >= 0)
			return (data->imgs.wall_east);
		else
			return (data->imgs.wall_west);
	}
	else
	{
		if (data->ray_dir.elements[1] >= 0)
			return (data->imgs.wall_south);
		else
			return (data->imgs.wall_north);
	}
}
