/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:42:09 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/09 17:07:31 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include "vector.h"

/**
* @brief allow to rotate the vector
* @param v the vector to rotate
* @param rad radian the degre of rotate of the vector
* @return new vec vector rotate
*/
t_vec rotate_vect(t_vec v, double rad)
{
	printf("INSIDE\n");
	t_vec	new_vec; 
	const double c = cos(rad);
	const double s = sin(rad);

	new_vec = new_vector(2, 0.0f, 0.0f);
	printf("new_vector :\n");
	print(new_vec);
	printf("c : %lf, s : %lf \n", c, s);
	new_vec.elements[0] = v.elements[0] * c + v.elements[1] * -s;
	new_vec.elements[1] = v.elements[0] * s + v.elements[1] * c;
	printf("c : %lf, s : %lf \n", new_vec.elements[0], new_vec.elements[1]);
	free(v.elements);
	printf("new_vector after rotate :\n");
	print(new_vec);
	return (new_vec);
}
