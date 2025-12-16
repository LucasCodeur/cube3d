/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:58:08 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/16 16:52:03 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/**
* @brief copy a vector
* @param v the vector to copy
* @return a copy of v on the stack
*/
t_vec	copy(t_vec v)
{
	return (v);
}

/**
* @brief copy the value of the a pointer of vector
* @param *v the pointer of vector
* @return a vector on the stack copy of *v
*/
t_vec	copy_ptr(t_vec *v)
{
	t_vec ret;
	ft_memcpy(&ret, v, sizeof(t_vec));
	return (ret);
}

/**
* @brief display the value of a vector
* @param the vector to display 
* @return
*/
void	print(t_vec v)
{
	printf("[ ");
	for (unsigned int i = 0; i < v.dim; i++)
	{
		printf("%f", v.elements[i]);

		if (i < v.dim - 1)
			printf(", ");
		else
			printf(" ");
	}
	printf("]\n");
}

/**
* @brief check if two vectors are equals
* @param v1 the first vector to compare
* @param v2 the second vector to compare
* @return a boolean to know if equal or not
*/
bool	equals(t_vec v1, t_vec v2)
{
	unsigned int i; 

	i = 0;
	if (v1.dim == v2.dim)
	{
		while (i < v1.dim)
		{
			if (v1.elements[i] != v2.elements[i])
				return (false);
			i++;
		}
		return (true);
	}
	return (false);
}

/**
* @brief to know if a two vectors are perpendicular 
* @param v1 the first vector to check 
* @param v2 the second vector to compare with the first 
* @return true if perpendicular false if not
*/
bool	orthogonal(t_vec v1, t_vec v2)
{
	if (v1.dim == v2.dim)
	{
		if (dot(v1, v2) == 0.0f)
			return (true);
	}
	return (false);
}
