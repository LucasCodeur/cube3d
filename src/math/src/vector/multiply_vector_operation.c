/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_vector_operation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:07:03 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/03 15:33:31 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static const t_vec	g_VEC_UNDEFINED = {0, NULL};

/**
* @brief allow to multiply two vectors together and produce a new one
* @param v1 the first vector to multiply to the second
* @param v2 the second vector to multiply to the first
* @return a new vector which is the multiplication of two vectors on the heap
*/
t_vec	multiply(t_vec v1, t_vec v2)
{
	if (v1.dim != v2.dim)
		return (g_VEC_UNDEFINED);

	t_vec			ret;
	unsigned int	i;

	ret = allocate(v1.dim);
	i = 0;
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

/**
* @brief allows you to do a vectorial product
* @param v1 the first vector
* @param v2 the second vector
* @return a new vector perpendicular of the twos vectors
*/
t_vec	cross_product(t_vec v1, t_vec v2)
{
	if (v1.dim != 3 || v2.dim != 3)
		return (g_VEC_UNDEFINED);
	t_vec	ret;

	ret = allocate(3);
	ret.elements[0] = (v1.elements[1] * v2.elements[2] - (v1.elements[2] * v2.elements[1]));
	ret.elements[1] = -1 * ((v1.elements[0] * v2.elements[2]) - (v1.elements[2] * v2.elements[0]));
	ret.elements[2] = (v1.elements[0] * v2.elements[1] - (v1.elements[1] * v2.elements[0]));
	return (ret);
}
