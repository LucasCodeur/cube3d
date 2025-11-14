/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:28:43 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/14 15:24:10 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

#include <mlx.h>

/*
* * @brief allows to launch the main program.
* * @param data structure contain all information about the program.
* * @return 
* */
void	launcher(t_data *data)
{
	init_screen_mlx(data);
	// key_hook_movements(data, keycode);
	display_minimap(data);
	mlx_loop(data->mlx.mlx);
}
