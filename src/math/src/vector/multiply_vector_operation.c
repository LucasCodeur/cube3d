/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_vector_operation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:07:03 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/27 11:17:54 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/**
* @brief allow to multiply two vectors together and produce a new one
* @param v1 the first vector to multiply to the second
* @param v2 the second vector to multiply to the first
* @return a new vector which is the multiplication of two vectors on the heap
*/
t_vec	multiply(t_vec v1, t_vec v2)
{
	t_vec			ret;
	unsigned int	i;

	i = 0;
	ret.dim = 2;
	while (i < ret.dim)
	{
		ret.elements[i] = v1.elements[i] * v2.elements[i];	
		i++;
	}
	return (ret);
}

/**
* @brief allow to multiply the second vector with the a pointer of vector 
* @param v1 the pointer of vector to receive the content of the second vector 
* and multiply them together 
* @param v2 the second vector to multiply to the first
* @return a true if the vector was multiplied or false if not
*/
bool	multiply_by(t_vec *v1, t_vec v2)
{
	if (!v1 || v1->dim != v2.dim)
		return (false);

	unsigned int	i;

	i = 0;
	while (i < v1->dim)
	{
		v1->elements[i] *= v2.elements[i];	
		i++;
	}
	return (true);
}

/**
* @brief multiply each component of two vectors together and sum the result into a float 
* @param v1 the first vector to multiply each component 
* to the component of the second vector
* @param v2 the second vector to multiply each component 
* to the component of the first vector
* @return the sum of the multiplication of each component of each vectors
*/
float	dot(t_vec v1, t_vec v2)
{
	float	ret;	
	unsigned int i;

	i = 0;
	ret = 0.0f;
	if (v1.dim == v2.dim)
	{
		while (i < v1.dim)
		{
			ret += v1.elements[i] * v2.elements[i];
			i++;
		}
	}
	return (ret);
}
