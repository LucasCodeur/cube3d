/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_vector_operation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:10:01 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/27 11:16:47 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/** @brief allow to divide two vectors together and produce a new one
* @param v1 the first vector to divide to the second
* @param v2 the second vector to divide to the first
* @return a new vector which is the division of two vectors on the heap
*/
t_vec	divide(t_vec v1, t_vec v2)
{
	t_vec			ret;
	unsigned int	i;

	i = 0;
	ret.dim = 2;
	while (i < ret.dim)
	{
		ret.elements[i] = v1.elements[i] / v2.elements[i];	
		i++;
	}
	return (ret);
}

/**
* @brief allow to divide the second vector with the a pointer of vector 
* @param v1 the pointer of vector to receive the content of the second vector 
* and divide them together 
* @param v2 the second vector to divide to the first
* @return a true if the vector was divided or false if not
*/
bool	divide_by(t_vec *v1, t_vec v2)
{
	if (!v1 || v1->dim != v2.dim)
		return (false);

	unsigned int	i;

	i = 0;
	while (i < v1->dim)
	{
		v1->elements[i] /= v2.elements[i];	
		i++;
	}
	return (true);
}
