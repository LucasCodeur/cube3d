/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:42:00 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/09 16:43:46 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICE_H 
# define MATRICE_H

#include "vector.h"

t_vec rotate_vect(t_vec v, double rad);
void rotate_vect_by_p(t_vec *v, double rad);

#endif
