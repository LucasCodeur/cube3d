/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:03:49 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/21 14:21:11 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "display.h"
#include "error.h"
#include "matrice.h"
#include "parsing.h"
#include "test.h"
#include "vector.h"

static t_error	ininitialize_values(t_data *data);
static void		print_message_error(t_error error);

int	main(int argc, char *argv[])
{
	t_data	data;
	t_error	error;

	error = ininitialize_values(&data);
	if (error.code != ERR_OK)
	{
		print_message_error(error);
		destroy_free_exit(&data);
		return (error.code);
	}
	error = parsing(argc, argv, &data);
	if (error.code != ERR_OK)
	{
		print_message_error(error);
		destroy_free_exit(&data);
		return (error.code);
	}
	error = launcher(&data);
	if (error.code != ERR_OK)
	{
		print_message_error(error);
		destroy_free_exit(&data);
		return (error.code);
	}
	return (error.code);
}

static t_error	ininitialize_values(t_data *data)
{
	t_error	error;

	ft_bzero(data, sizeof(t_data));
	error = ft_malloc(&data->garbage, sizeof(t_parsing),
			(void **)&data->parsing);
	if (error.code != ERR_OK)
		return (error);
	ft_bzero(data->parsing, sizeof(t_parsing));
	data->mlx.max_height = WIN_HEIGHT;
	data->mlx.max_width = WIN_WIDTH;
	return (ERROR_OK);
}

static void	print_message_error(t_error error)
{
	if (error.code == ERR_FAIL)
		printf("Generic problem\n");
	else if (error.code == ERR_MEMORY)
		printf("Memory problem\n");
	else if (error.code == ERR_INVALID_ARG)
		printf("Invalid argument problem\n");
	else if (error.code == ERR_IO)
		printf("Open/Read file problem\n");
	else if (error.code == ERR_MLX)
		printf("Mlx problem\n");
	else
		printf("No problem\n");
	if (error.message)
		printf("%s\n", error.message);
}
