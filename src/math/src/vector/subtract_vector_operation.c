/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtract_vector_operation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:06:25 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/27 11:17:23 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/**
* @brief allow to subtract two vectors together and produce a new one
* @param v1 the first vector to subtract to the second
* @param v2 the second vector to subtract to the first
* @return a new vector which is the subtraction of two vectors on the heap
*/
t_vec	subtract(t_vec v1, t_vec v2)
{
	t_vec			ret;
	unsigned int	i;

	i = 0;
	ret.dim = 2;
	while (i < ret.dim)
	{
		ret.elements[i] = v1.elements[i] - v2.elements[i];	
		i++;
	}
	return (ret);
}

/**
* @brief allow to subtract the second vector with the a pointer of vector 
* @param v1 the pointer of vector to receive the content of the second vector 
* and subtract them together 
* @param v2 the second vector to subtract to the first
* @return a true if the vector was subtracted or false if not
*/
bool	subtract_from(t_vec *v1, t_vec v2)
{
	if (!v1 || v1->dim != v2.dim)
		return (false);

	unsigned int	i;

	i = 0;
	while (i < v1->dim)
	{
		v1->elements[i] -= v2.elements[i];	
		i++;
	}
	return (true);

}
