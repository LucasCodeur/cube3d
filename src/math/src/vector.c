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

const t_vec	VEC_UNDEFINED = {0, NULL};

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

t_vec	add(t_vec v1, t_vec v2)
{
	if (v1.dim != v2.dim)
		return (VEC_UNDEFINED);

	t_vec			ret;
	unsigned int	i;

	ret = allocate(v1.dim);
	i = 0;
	while (i < ret.dim)
	{
		ret.elements[i] = v1.elements[i] + v2.elements[i];	
		i++;
	}
	return (ret);
}

bool	add_to(t_vec *v1, t_vec v2)
{
	if (!v1 || v1->dim != v2.dim)
		return (false);

	unsigned int	i;

	i = 0;
	while (i < v1->dim)
	{
		v1->elements[i] += v2.elements[i];	
		i++;
	}
	return (true);
}

t_vec	subtract(t_vec v1, t_vec v2)
{
	if (v1.dim != v2.dim)
		return (VEC_UNDEFINED);

	t_vec			ret;
	unsigned int	i;

	ret = allocate(v1.dim);
	i = 0;
	while (i < ret.dim)
	{
		ret.elements[i] = v1.elements[i] - v2.elements[i];	
		i++;
	}
	return (ret);
}

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

t_vec	multiply(t_vec v1, t_vec v2)
{
	if (v1.dim != v2.dim)
		return (VEC_UNDEFINED);

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

t_vec	divide(t_vec v1, t_vec v2)
{
	if (v1.dim != v2.dim)
		return (VEC_UNDEFINED);

	t_vec			ret;
	unsigned int	i;

	ret = allocate(v1.dim);
	i = 0;
	while (i < ret.dim)
	{
		ret.elements[i] = v1.elements[i] / v2.elements[i];	
		i++;
	}
	return (ret);
}

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

bool	orthogonal(t_vec v1, t_vec v2)
{
	if (v1.dim == v2.dim)
		if (dot(v1, v2) == 0.0f)
			return (true);
	return (false);
}

t_vec	cross_product(t_vec v1, t_vec v2)
{
	if (v1.dim != 3 || v2.dim != 3)
		return (VEC_UNDEFINED);

	t_vec	ret;
	ret.elements[0] = (v1.elements[1] * v2.elements[2] - (v1.elements[2] * v2.elements[1]));
	ret.elements[1] = -1 * ((v1.elements[0] * v2.elements[2]) - (v1.elements[1] * v2.elements[0]));
	ret.elements[2] = (v1.elements[0] * v2.elements[1] - (v1.elements[1] * v2.elements[0]));
	return (ret);
}
