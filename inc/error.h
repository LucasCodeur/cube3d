/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:44:19 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/22 16:51:01 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include <stdlib.h>

typedef enum e_error_code
{
	ERR_OK,
	ERR_FAIL,
	ERR_MEMORY,
	ERR_INVALID_ARG,
	ERR_IO,
	ERR_MLX
}						t_error_code;

typedef struct s_error
{
	t_error_code		code;
	const char			*message;
}						t_error;

static inline t_error	error_ok(void)
{
	return ((t_error){.code = ERR_OK, .message = NULL});
}

#endif
