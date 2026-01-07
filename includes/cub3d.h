/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:01:49 by prigaudi          #+#    #+#             */
/*   Updated: 2026/01/07 14:57:32 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include "../minilibx/mlx.h"
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

typedef struct s_map
{
	char					**map_lines;
	int						width;
	int						height;
	int						map_finished;
}							t_map;

typedef struct s_img
{
	int						width;
	int						height;
	void					*img;
	char					*addr;
	int						bpp;
	int						line_len;
	int						endian;
}							t_img;

typedef struct s_hero
{
	int						x;
	int						y;
	char					orientation;
}							t_hero;

/*
is_valid = 1 if all elements are present and no superflux
=> Each element are tested after
*/
typedef struct s_data
{
	void					*mlx_ptr;
	void					*win_ptr;
	t_map					*map;
	t_hero					*hero;
	char					*north_texture;
	char					*south_texture;
	char					*east_texture;
	char					*west_texture;
	int						*floor_rgb_color;
	int						*ceiling_rgb_color;
	int						nb_valid_elements;
	int						config_is_valid;
	t_garbage				*garbage;
}							t_data;

//========== INIT ===========
t_data						*init_data(void);
void						mlx_hook_loop(t_data *data);
int							mlx_init_window(t_data *data);

//========== MAP ===========
int							display_map(t_data *data);

//========== MINIMAP ===========
int							display_minimap(t_data *data);

//========== PARSING ===========
int							parsing(int argc, char **argv, t_data *config_data);
int							check_argument(int argc, char **argv,
								t_data *config_data);
int							config(char *path, t_data *config_data);
int							check_element_line(char *line, t_data *onfig_data);
int							extract_save_map(char *line, t_data *onfig_data);
int							save_element(char *id, char *info,
								t_data *config_data);
int							*check_extract_rgb(t_data *config_data, char *info);
int							check_map(t_data *config_data);
int							check_map_structure(t_data *config_data);

//========== UTILS ===========
void						free_all(t_data *data);
int							ft_atoi(const char *str);
void						*ft_calloc(size_t elementCount, size_t elementSize);
void						ft_lstadd_front(t_garbage **lst, t_garbage *new);
void						ft_lstclear(t_garbage **lst, void (*del)(void *));
t_garbage					*ft_lstnew(void *content);
int							ft_lstsize(t_garbage *lst);
void						*ft_malloc(t_garbage **garbage, int size);
void						*ft_memmove(void *dest, const void *src, size_t c);
char						**ft_split(t_data *config_data, char const *s,
								char c);
char						*ft_strdup(t_data *config_data, const char *str);
size_t						ft_strlen(const char *str);
int							ft_strncmp(const char *first, const char *second,
								size_t length);
char						*ft_strnjoin(t_data *config_data, char *s1,
								char *s2, int byte_nbr);
char						*ft_strnstr(const char *s1, const char *s2,
								size_t len);
char						*ft_strtrim(t_data *config_data, char const *s1,
								char const *set);
char						*ft_substr(t_data *config_data, char const *s,
								unsigned int start, size_t len);
char						*get_next_line(t_data *config_data, int fd);

#endif