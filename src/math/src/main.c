/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:16:18 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/01 13:30:52 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "vector.h"

void 	num_args_test(void)
{
	printf("%ld\n", NUMARGS(float, 1.0f, 2.0f, 3.0f));
}

void	vector_test(void)
{
	// t_vec	v = vector(2.0f, -3.0f, 1.0f);
	// t_vec	v = construct_empty_vector(5);
	t_vec	v = construct_default_vector(5, 6.9f);
	t_vec	v2 = copy(v);
	print(v);
	print(v2);
}

void	equals_vector_test(void)
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

int	main(void)
{
	equals_vector_test();
	return (0);
}
