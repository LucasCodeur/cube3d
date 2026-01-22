/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:42:09 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/21 15:08:18 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmath.h"

#include <math.h>

/**
 * @brief allow to rotate the vector
 * @param v the vector to rotate
 * @param rad radian the degre of rotate of the vector
 * @return new vec vector rotate
 */
t_vec	rotate_vect(t_vec v, double rad)
{
	t_vec			new_vec;
	const double	c = cos(rad);
	const double	s = sin(rad);

	new_vec = new_vector_2d(0.0f, 0.0f);
	new_vec.elements[0] = v.elements[0] * c + v.elements[1] * -s;
	new_vec.elements[1] = v.elements[0] * s + v.elements[1] * c;
	return (new_vec);
}

/**
 * @brief allow to rotate the vector
 * @param v the vector to rotate
 * @param rad radian the degre of rotate of the vector
 * @return new vec vector rotate
 */
void	rotate_vect_by_p(t_vec *v, double rad)
{
	double	c;
	double	s;
	double	temp;

	temp = v->elements[0];
	c = cos(rad);
	s = sin(rad);
	v->elements[0] = v->elements[0] * c + v->elements[1] * -s;
	v->elements[1] = temp * s + v->elements[1] * c;
}
