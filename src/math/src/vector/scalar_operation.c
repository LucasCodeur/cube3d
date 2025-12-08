/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:02:57 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/03 15:28:27 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/**
* @brief apply a multiplicator to scaling the vector
* @param v the vector to scale
* @param k the multiplicator to scale the vector
* @return a new vector scale on the heap
*/
t_vec	scalar_multiplication(t_vec v, float k)
{
	t_vec	ret;
	unsigned int	i;

	ret = allocate(v.dim);
	i = 0;
	while (i < ret.dim)
	{
		ret.elements[i] = v.elements[i] * k;
		i++;
	}
	return (ret);
}

/**
* @brief apply a multiplicator to scaling the vector passing by a pointer
* @param *v the pointer of vector to scale
* @param k the multiplicator to scale the vector
* @return 
*/
void	scalar_multiplication_by(t_vec *v, float k)
{
	unsigned int	i;

	i = 0;
	while (i < v->dim)
	{
		v->elements[i] *= k;
		i++;
	}
}

/**
* @brief apply a divisor to scaling the vector
* @param v the vector to scale
* @param k the divisor to scale the vector
* @return a new vector scale on the heap
*/
t_vec	scalar_division(t_vec v, float k)
{
	t_vec	ret;
	unsigned int	i;

	ret = allocate(v.dim);
	i = 0;
	while (i < ret.dim)
	{
		ret.elements[i] = v.elements[i] / k;
		i++;
	}
	return (ret);
}

/**
* @brief apply a divisor to scaling the vector passing by a pointer
* @param *v the pointer of vector to scale
* @param k the divisor to scale the vector
* @return 
*/
void	scalar_division_by(t_vec *v, float k)
{
	unsigned int	i;

	i = 0;
	while (i < v->dim)
	{
		v->elements[i] /= k;
		i++;
	}
}
