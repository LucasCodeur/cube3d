/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:58:08 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/01 13:38:32 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include <stdlib.h>

t_vec	allocate(unsigned int dim)
{
	t_vec	ret;

	ret.dim = dim;
	ret.elements = malloc(dim * sizeof(float));
	return (ret);
}
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

t_vec	construct_empty_vector(unsigned int dim)
{
	return (construct_default_vector(dim, 0.0f));
}

t_vec	copy(t_vec v)
{
	return (v);
}

//WARN: TAKE OFF
t_vec	new_vector(unsigned int dim, ...)
{
	t_vec	ret;
	va_list list;
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

//WARN: TAKE OFF
#include <string.h>
t_vec	copy_ptr(t_vec *v)
{
	t_vec ret;
	memcpy(&ret, v, sizeof(t_vec));
	return (ret);
}

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

bool	equals(t_vec v1, t_vec v2)
{
	unsigned int i = 0;
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
