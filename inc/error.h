/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:44:19 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/09 14:10:48 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_OK ((t_error){.code = ERR_OK})

typedef enum
{
	ERR_OK = 0,
	ERR_FAIL,
	ERR_MEMORY,
	ERR_INVALID_ARG,
	ERR_IO
}					t_error_code;

typedef struct s_error
{
	t_error_code	code;
	const char		*message;
}					t_error;

#endif
