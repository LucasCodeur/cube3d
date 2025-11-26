/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:04:45 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/26 17:36:52 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H 
# define DEBUG_H

#include "display.h"

#include <stdio.h>

void	d_print_grid(t_map map);
void	d_print_frame(t_img img, int* x, int* y);
void	d_generate_map(t_data* data);

#endif
