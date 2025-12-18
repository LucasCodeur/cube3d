/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:01:55 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/18 10:27:51 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include <stdlib.h>

/**
* @brief allow to allocate a vector of n dimension
* @param unsigned int dimension of the vector
* @return a vector with an array of the heap
*/
t_vec	allocate(unsigned int dim)
{
	t_vec	ret;

	ret.dim = dim;
	ret.elements = malloc(dim * sizeof(float));
	return (ret);
}

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

	ret = allocate(dim);
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

//WARN: TAKE OFF
/**
* @brief create a vector on the heap with a given dimension and with n value
* @param dim dimension of the vector
* @param ... n value of the vector according the dim
* @return a vector on the heap
*/
t_vec	new_vector(unsigned int dim, ...)
{
	t_vec				ret;
	va_list				list;
	unsigned int		i;

	ret = allocate(dim);
	va_start(list, dim);
	i = 0;
	while (i < dim)
	{
		ret.elements[i] = va_arg(list, double);
		i++;
	}
	return (ret);
}

/**
* @brief create a 2D vector on the heap.
* @param x abcissa value of the vector
* @param y ordinate value of the vector
* @return a vector on the heap
*/
t_vec	new_vector_2D(double x, double y)
{
	t_vec	ret;

	ret = allocate(2);
	ret.elements[0] = x;
	ret.elements[1] = y;
	return (ret);
}
