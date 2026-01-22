/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:09:23 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/27 11:21:22 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmath.h"

/**
* @brief allow to compute the magnitude of the vector 
* and divide each elements of this one by the magnitude
* @param v the vector to normalize
* @return a vector normalized on the heap
*/
t_vec	normalized(t_vec v)
{
	t_vec			ret;
	float			mag;
	unsigned int	i;

	i = 0;
	mag = magnitude(v);
	while (i < ret.dim)
	{
		ret.elements[i] = v.elements[i] / mag;
		i++;
	}
	return (ret);
}

/**
* @brief allow to compute the magnitude of the vector 
* and divide each elements of this one by the magnitude
* @param *v the pointer of the vector to normalize
* @return a vector normalized
*/
void	normalize(t_vec *v)
{
	float			mag;
	unsigned int	i;

	mag = magnitude(*v);
	i = 0;
	while (i < v->dim)
	{
		v->elements[i] /= mag;
		i++;
	}
}
