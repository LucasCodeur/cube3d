/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:08:18 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/26 11:00:26 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

#include <sys/time.h>

/**
 * @brief allow to get the time
 * @return time in second
 */
double	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}

/**
* @brief allow to count fps
* @param data all information about the program
* @return
*/
void	count_fps(t_data *data)
{
	if (data->fps.delta_time >= 1.0)
	{
		data->fps.last_time = data->fps.current_time;
		data->fps.count = data->fps.count_frame / data->fps.delta_time;
		printf("fps : %d\n", data->fps.count);
		data->fps.count_frame = 0;
	}
}
