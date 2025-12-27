/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:08:50 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/27 11:18:53 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include <math.h>

/**
* @brief apply a k power on the vector
* @param v the vector to apply the power
* @param k the power to apply on the vector
* @return a new vector where we apply power to the vector, on the heap
*/
t_vec	power(t_vec v, float k)
{
	t_vec			ret;
	unsigned int	i;

	i = 0;
	ret.dim = 2;
	while (i < ret.dim)
	{
		ret.elements[i] = powf(v.elements[i], k);
		i++; 
	}
	return (ret);
}

/**
* @brief apply a k power to a vector 
* @param *v the pointer vector to apply the power
* @param k the power to apply on the vector
* @return a modify vector where we apply power.
*/
void	power_of(t_vec *v, float k)
{
	unsigned int	i;

	i = 0;
	while (i < v->dim)
	{
		v->elements[i] = powf(v->elements[i], k);
		i++;
	}
}
