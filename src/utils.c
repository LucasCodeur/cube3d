/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:00:17 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/09 15:01:49 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/**
* @brief allow to put a value of 0 in each case of memory of *s
* @param *s pointer of the memory case we have to reset
* @param n the size of *s
* @return
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	value;
	unsigned char	*p;

	value = 0;
	p = (unsigned char *)s;
	while (n >= 2)
	{
		*p++ = value;
		*p++ = value;
		n -= 2;
	}
	if (n-- == 1)
		*p++ = value;
}
