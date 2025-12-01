/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:48:48 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/01 13:40:29 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H 
# define VECTOR_H

#include <stdio.h>
#include <stdbool.h>

//WARN: have to take off
#include <stdarg.h>

typedef struct s_vec
{
	unsigned int dim;
	float	*elements;

} t_vec;

t_vec	allocate(unsigned int dim);
t_vec	construct_default_vector(unsigned int dim, float val);
t_vec	construct_empty_vector(unsigned int dim);
t_vec	copy(t_vec v);
bool	equals(t_vec v1, t_vec v2);
t_vec	scalar_multiplication(t_vec v, float k);
void	scalar_multiplication_by(t_vec *v, float k);
t_vec	scalar_division(t_vec v, float k);
void	scalar_division_by(t_vec *v, float k);

//WARN: have to take off
t_vec	new_vector(unsigned int dim, ...);
t_vec	copy_ptr(t_vec *v);
void	print(t_vec v);
#define NUMARGS(type, ...) (sizeof((type[]){0.0f, ##__VA_ARGS__}) / sizeof(type) - 1)
#define vector(...) new_vector(NUMARGS(float, __VA_ARGS__), ##__VA_ARGS__)


#endif
