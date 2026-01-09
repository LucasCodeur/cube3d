/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:01:49 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/09 17:17:57 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include "display.h"
# include "error.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// enum						ERROR
// {
// 	MALLOC,
// 	NO_ERROR,
// 	PARSING,
// }

typedef struct s_garbage	t_garbage;

typedef struct s_garbage
{
	void					*ptr;
	t_garbage				*next;
}							t_garbage;

/*
is_valid = 1 if all elements are present and no superflux
=> Each element are tested after
*/
typedef struct s_parsing
{
	void					*mlx_ptr;
	void					*win_ptr;
	t_map					*map;
	char					*north_texture;
	char					*south_texture;
	char					*east_texture;
	char					*west_texture;
	int						*floor_rgb_color;
	int						*ceiling_rgb_color;
	int						nb_valid_elements;
	int						config_is_valid;
	t_garbage				*garbage;
}							t_parsing;

//========== INIT ===========
t_parsing					*init_parsing(void);
void						mlx_hook_loop(t_parsing *parsing);
int							mlx_init_window(t_parsing *parsing);

//========== MAP ===========
int							display_map(t_parsing *parsing);

//========== MINIMAP ===========
int							display_minimap(t_data *data);

//========== PARSING ===========
t_error						parsing(int argc, char **argv, t_parsing *data);
t_error						check_argument(int argc, char **argv,
								t_parsing *data);
t_error						config(char *path, t_parsing *data);
t_error						check_element_line(char *line, t_parsing *data);
t_error						extract_save_map(char *line, t_parsing *data);
t_error						save_element(char *id, char *info, t_parsing *data);
t_error						check_extract_rgb(t_parsing *data, char *info,
								int *rgb_int);
t_error						check_map(t_parsing *data);
t_error						check_map_structure(t_parsing *data);

//========== UTILS ===========
void						free_all(t_parsing *data);
int							ft_atoi(const char *str);
t_error						ft_calloc(size_t elementCount, size_t elementSize,
								char *str);
void						ft_lstadd_front(t_garbage **lst, t_garbage *new);
void						ft_lstclear(t_garbage **lst, void (*del)(void *));
t_error						ft_lstnew(void *ptr, t_garbage *new);
int							ft_lstsize(t_garbage *lst);
t_error						ft_malloc(t_garbage **garbage, int size, void *str);
void						*ft_memmove(void *dest, const void *src, size_t c);
t_error						ft_split(t_parsing *cd, char const *s, char c,
								char **split);
t_error						ft_strdup(t_parsing *data, const char *str,
								char *result);
size_t						ft_strlen(const char *str);
int							ft_strncmp(const char *first, const char *second,
								size_t length);
t_error						ft_strnjoin(t_parsing *data, char *s1, char *s2,
								int byte_nbr);
char						*ft_strnstr(const char *s1, const char *s2,
								size_t len);
t_error						ft_strtrim(t_parsing *data, char const *s1,
								char const *set, char *str);
t_error						ft_substr(t_parsing *data, char const *s,
								unsigned int start, size_t len, char *str);
t_error						get_next_line(t_parsing *data, int fd, char *line);

#endif
