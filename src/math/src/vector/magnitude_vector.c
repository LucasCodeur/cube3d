/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:10:48 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/21 15:11:01 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

/**

 * @brief allow us to multiply each elements of a
	vector by itself and sum the result
 * @param v the vector to multiply by itself
 * @return the sum of the multiplication of each element
 */
double	magnitude_squared(t_vec v)
{
	double			ret;
	unsigned int	i;

	ret = 0.0f;
	i = 0;
	while (i < v.dim)
	{
		ret += v.elements[i] * v.elements[i];
		i++;
	}
	return (ret);
}

/**
 * @brief allow us to square the result get by magnitude squared
 * @param v the vector to compute the magnitude
 * @return the sum of the multiplication of each element squared
 */
double	magnitude(t_vec v)
{
	return (sqrt(magnitude_squared(v)));
}
