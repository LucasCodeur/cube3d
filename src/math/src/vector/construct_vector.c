/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:01:55 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/21 15:07:54 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/**
 * @brief allow to give a vector with a value give by parameter
 * @param dim dimension of the vector
 * @param val value of the vector
 * @return a vector with a value
 */
t_vec	construct_default_vector(unsigned int dim, float val)
{
	t_vec			ret;
	unsigned int	i;

	i = 0;
	while (i < dim)
	{
		ret.elements[i] = val;
		i++;
	}
	return (ret);
}

/**
 * @brief give an empty vector
 * @param dim dimension of the vector
 * @return a vector with a value of 0.0f
 */
t_vec	construct_empty_vector(unsigned int dim)
{
	return (construct_default_vector(dim, 0.0f));
}

/**
 * @brief create a 2D vector on the heap.
 * @param x abcissa value of the vector
 * @param y ordinate value of the vector
 * @return a vector on the heap
 */
t_vec	new_vector_2d(double x, double y)
{
	t_vec	ret;

	ret.dim = 2;
	ret.elements[0] = x;
	ret.elements[1] = y;
	return (ret);
}
