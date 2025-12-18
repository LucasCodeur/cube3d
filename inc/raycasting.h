/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 08:54:09 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/17 08:56:26 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H 
# define RAYCASTING_H

#include "vector.h"

typedef struct s_ray
{
	t_vec	dir;
	t_vec	pos;
}	t_ray;

#endif
