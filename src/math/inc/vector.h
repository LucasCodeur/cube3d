/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:48:48 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/27 10:58:08 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H 
# define VECTOR_H

#include <stdio.h>
#include <stdbool.h>

//WARN: have to take off
#include <stdarg.h>
#define	VEC

typedef struct s_vec
{
	unsigned int dim;
	double	elements[2];

} t_vec;

t_vec	allocate(unsigned int dim);
t_vec	new_vector_2D(double x, double y);
t_vec	construct_default_vector(unsigned int dim, float val);
t_vec	construct_empty_vector(unsigned int dim);
t_vec	copy(t_vec v);
bool	equals(t_vec v1, t_vec v2);
t_vec	scalar_multiplication(t_vec v, float k);
void	scalar_multiplication_by(t_vec *v, float k);
t_vec	scalar_division(t_vec v, float k);
void	scalar_division_by(t_vec *v, float k);
t_vec	add(t_vec v1, t_vec v2);
bool	add_to(t_vec *v1, t_vec v2);
t_vec	subtract(t_vec v1, t_vec v2);
bool	subtract_from(t_vec *v1, t_vec v2);
t_vec	multiply(t_vec v1, t_vec v2);
bool	multiply_by(t_vec *v1, t_vec v2);
t_vec	divide(t_vec v1, t_vec v2);
bool	divide_by(t_vec *v1, t_vec v2);
bool	orthogonal(t_vec v1, t_vec v2);
float	dot(t_vec v1, t_vec v2);
t_vec	cross_product(t_vec v1, t_vec v2);
double	magnitude_squared(t_vec v);
double	magnitude(t_vec v);
t_vec	normalized(t_vec v);
void	normalize(t_vec *v);
t_vec	power(t_vec v, float k);
void	power_of(t_vec *v, float k);

t_vec	copy_ptr(t_vec *v);
void	print(t_vec v);

/**
* @brief utils to the library
*/
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
