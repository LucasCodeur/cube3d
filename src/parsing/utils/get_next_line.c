/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:18:04 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/22 13:53:03 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	find_index(char *buffer, int *stop_read)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			i++;
			*stop_read = 1;
			break ;
		}
		i++;
	}
	return (i);
}

static t_error	get_buffer(t_gnl_variables gnl_var, char *buffer, int *check)
{
	int		i;
	int		stop_read;
	t_error	error;

	i = 0;
	stop_read = 0;
	if (buffer[0])
	{
		i = find_index(buffer, &stop_read);
		if (stop_read == 1)
		{
			error = ft_strnjoin(gnl_var.data, gnl_var.line, buffer, i);
			if (error.code != ERR_OK)
				return (error);
			ft_memmove(buffer, buffer + i, BUFFER_SIZE + 1 - i);
			*check = 1;
			return (ERROR_OK);
		}
		error = ft_strnjoin(gnl_var.data, gnl_var.line, buffer, i);
		if (error.code != ERR_OK)
			return (error);
	}
	*check = 2;
	return (ERROR_OK);
}

static t_error	read_buffer(t_gnl_variables gnl_var, ssize_t *byte_read,
		char *buffer, int *check)
{
	t_error	error;

	*byte_read = read(gnl_var.fd, buffer, BUFFER_SIZE);
	if (*byte_read == -1)
	{
		buffer[0] = '\0';
		free(*(gnl_var.line));
		error.code = ERR_IO;
		error.message = "Line can't be read in function read in read_buffer";
		return (error);
	}
	if (*byte_read == 0)
	{
		if (*(gnl_var.line))
		{
			buffer[0] = '\0';
			*check = 1;
			return (ERROR_OK);
		}
		*check = 0;
		return (ERROR_OK);
	}
	buffer[*byte_read] = '\0';
	*check = 2;
	return (ERROR_OK);
}

static t_error	get_line(t_gnl_variables gnl_var, char *buffer)
{
	int		check;
	ssize_t	byte_read;
	t_error	error;

	byte_read = 1;
	error = get_buffer(gnl_var, buffer, &check);
	if (error.code != ERR_OK)
		return (error);
	if (check == 1)
		return (ERROR_OK);
	while (byte_read)
	{
		error = read_buffer(gnl_var, &byte_read, buffer, &check);
		if (error.code != ERR_OK)
			return (error);
		if (check == 1 || check == 0)
			return (ERROR_OK);
		error = get_buffer(gnl_var, buffer, &check);
		if (error.code != ERR_OK)
			return (error);
		if (check == 1)
			return (ERROR_OK);
	}
	return (ERROR_OK);
}

t_error	get_next_line(t_data *data, int fd, char **line)
{
	static char		buffer[BUFFER_SIZE + 1];
	t_error			error;
	t_gnl_variables	gnl_var;

	gnl_var.data = data;
	gnl_var.fd = fd;
	gnl_var.line = line;
	*line = NULL;
	if (fd == -1 || BUFFER_SIZE <= 0)
	{
		error.code = ERR_IO;
		error.message = "Line can't be read\n";
		return (error);
	}
	error = get_line(gnl_var, buffer);
	if (error.code != ERR_OK)
		return (error);
	return (ERROR_OK);
}
