/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:47:55 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/08 12:52:33 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "vector.h"

void 	t_num_args(void)
{
	printf("%ld\n", NUMARGS(float, 1.0f, 2.0f, 3.0f));
}

void	t_vector(void)
{
	// t_vec	v = vector(2.0f, -3.0f, 1.0f);
	// t_vec	v = construct_empty_vector(5);
	t_vec	v = construct_default_vector(5, 6.9f);
	t_vec	v2 = copy(v);
	print(v);
	print(v2);
}

void	t_equals_vector(void)
{
	t_vec	v1 = construct_default_vector(5, 6.9f);
	t_vec	v2 = copy(v1);
	t_vec	v3 = construct_default_vector(5, 8.9f);
	print(v1);
	print(v2);
	print(v3);
	printf("%d\n", equals(v1, v2));
	printf("%d\n", equals(v1, v3));
}

void	t_scalar_multiplication(void)
{
	t_vec	v1 = construct_default_vector(5, 6.9f);
	print(v1);
	print(scalar_multiplication(v1, 1.2f));
	return ;
}

void	t_scalar_multiplication_by(void)
{
	t_vec	v1 = construct_default_vector(5, 6.9f);
	print(v1);
	scalar_multiplication_by(&v1, 1.2f);
	print(v1);
	return ;
}

void	t_scalar_division(void)
{
	t_vec	v1 = construct_default_vector(5, 6.9f);
	print(v1);
	print(scalar_division(v1, 1.2f));
	return ;
}

void	t_scalar_division_by(void)
{
	t_vec	v1 = construct_default_vector(5, 6.9f);
	print(v1);
	scalar_division_by(&v1, 1.2f);
	print(v1);
	return ;
}

void	t_subtract(void)
{
	t_vec	v1 = construct_default_vector(5, 6.9f);
	t_vec	v2 = construct_default_vector(5, 6.9f);
	print(v1);
	print(v2);
	print(subtract(v1, v2));
	return ;
}


void	t_subtract_from(void)
{
	t_vec	v1 = construct_default_vector(5, 6.9f);
	t_vec	v2 = construct_default_vector(5, 6.9f);
	print(v1);
	print(v2);
	subtract_from(&v1, v2);
	print(v1);
	return ;
}

void	t_add(void)
{
	t_vec	v1 = construct_default_vector(5, 6.9f);
	t_vec	v2 = construct_default_vector(5, 6.9f);
	print(v1);
	print(v2);
	print(add(v1, v2));
	return ;
}


void	t_add_from(void)
{
	t_vec	v1 = construct_default_vector(5, 6.9f);
	t_vec	v2 = construct_default_vector(5, 6.9f);
	print(v1);
	print(v2);
	add_to(&v1, v2);
	print(v1);
	return ;
}

void	t_multiply(void)
{
	t_vec	v1 = construct_default_vector(5, 6.9f);
	t_vec	v2 = construct_default_vector(5, 6.9f);
	print(v1);
	print(v2);
	print(multiply(v1, v2));
	return ;
}

void	t_multiply_by(void)
{
	t_vec	v1 = construct_default_vector(5, 6.9f);
	t_vec	v2 = construct_default_vector(5, 6.9f);
	print(v1);
	print(v2);
	multiply_by(&v1, v2);
	print(v1);
	return ;
}

void	t_divide(void)
{
	t_vec	v1 = construct_default_vector(5, 6.9f);
	t_vec	v2 = construct_default_vector(5, 6.9f);
	print(v1);
	print(v2);
	print(divide(v1, v2));
	return ;
}

void	t_divide_by(void)
{
	t_vec	v1 = construct_default_vector(5, 6.9f);
	t_vec	v2 = construct_default_vector(5, 6.9f);
	print(v1);
	print(v2);
	divide_by(&v1, v2);
	print(v1);
	return ;
}

void	t_orthogonal(void)
{
	t_vec	v1 = construct_default_vector(2, 1.0f);
	t_vec	v2 = construct_default_vector(2, 1.0f);
	v1.elements[0] = 4.0f;
	v2.elements[0] = -2.0f;
	v1.elements[1] = 1.0f;
	v2.elements[1] = 10.0f;
	print(v1);
	print(v2);
	printf("%d\n", orthogonal(v1, v2));
}

void	t_normalized(void)
{
	t_vec	v1 = vector(2, 2.0f, 3.0f);
	
	print(v1);
	t_vec	v2 = normalized(v1);
	print(v2);
	t_vec	v3 = power(v2, 2);
	float ret = 0.0f;
	for (unsigned int i = 0 ; i < 3; i++)
	{
		ret += v3.elements[i];
	}
	printf("%lf", ret);
}

void	t_normalize(void)
{
	t_vec	v1 = vector(2, 2.0f, 3.0f);
	
	print(v1);
	normalize(&v1);
	print(v1);
	t_vec	v2 = power(v1, 2);
	float ret = 0.0f;
	for (unsigned int i = 0 ; i < 3; i++)
	{
		ret += v2.elements[i];
	}
	printf("%lf", ret);
}

void	t_magnitude_squared(void)
{
	t_vec	v1 = vector(2, 2.0f, 3.0f);

	printf("%lf\n", magnitude_squared(v1));
}

void	t_magnitude(void)
{
	t_vec	v1 = vector(2, 2.0f, 3.0f);

	printf("%lf\n", magnitude(v1));
}

void	t_power(void)
{
	t_vec	v1 = vector(2, 2.0f, 3.0f);

	print(v1);
	print(power(v1, 2));
	print(power(v1, 3));
	print(power(v1, 4));

}

void	t_power_of(void)
{
	t_vec	v1 = vector(2, 2.0f, 3.0f);
	t_vec	v2 = vector(2, 2.0f, 3.0f);
	t_vec	v3 = vector(2, 2.0f, 3.0f);

	print(v1);
	power_of(&v1, 2);
	print(v1);
	print(v2);
	power_of(&v2, 3);
	print(v2);
	print(v3);
	power_of(&v3, 4);
	print(v3);
}

void	t_cross_product(void)
{
	t_vec	v1 = vector(3.0f, 4.0f, 5.0f);
	t_vec	v2 = vector(3.0f, 4.0f, 5.0f);
	t_vec	v3 = cross_product(v1, v2);
	print(v1);
	print(v2);
	print(v3);
}

void	t_dot(void)
{
	t_vec	v1 = vector(3.0f, 4.0f, 5.0f);
	t_vec	v2 = vector(3.0f, 4.0f, 5.0f);
	print(v1);
	print(v2);
	printf("%lf\n", dot(v1, v2));
}
