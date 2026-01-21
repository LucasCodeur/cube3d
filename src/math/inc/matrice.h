/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:42:00 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/21 15:02:13 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICE_H
# define MATRICE_H

# include "vector.h"

t_vec	rotate_vect(t_vec v, double rad);
void	rotate_vect_by_p(t_vec *v, double rad);

#endif
