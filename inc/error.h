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
	ERR_OK,
	ERR_FAIL,
	ERR_MEMORY,
	ERR_INVALID_ARG,
	ERR_IO,
	ERR_MLX 
}					t_error_code;
//
// typedef enum
// {
// 	ERR_OK = "No problem",
// 	ERR_FAIL = "Generic problem",
// 	ERR_MEMORY = 2,
// 	ERR_INVALID_ARG = 3,
// 	ERR_IO = 4,
// 	ERR_MLX = 5
// }					t_error_message;
//
typedef struct s_error
{
	t_error_code	code;
	const char		*message;
}					t_error;

#endif
