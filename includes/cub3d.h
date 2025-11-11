/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:01:49 by prigaudi          #+#    #+#             */
/*   Updated: 2025/11/11 15:08:33 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char		**map_lines;
	int			width;
	int			height;
	int			map_finished;
}				t_map;

/*
is_valid = 1 if all elements are present and no superflux
=> Each element are tested after
*/
typedef struct s_config_data
{
	char		*north_texture;
	char		*south_texture;
	char		*east_texture;
	char		*west_texture;
	int			*floor_rgb_color;
	int			*ceiling_rgb_color;
	t_map		*map;
	int			nb_valid_elements;
	int			config_is_valid;
}				t_config_data;

//========== INIT ===========
t_config_data	*init_config_data(void);

//========== PARSING ===========
int				parsing(int argc, char **argv, t_config_data *config_data);
int				check_argument(int argc, char **argv);
int				config(char *path, t_config_data *config_data);
int				check_element_line(char *line, t_config_data *onfig_data);
int				check_map(char *line, t_config_data *onfig_data);
int				save_element(char *id, char *info, t_config_data *config_data);

//========== UTILS ===========
int				ft_atoi(const char *str);
void			*ft_calloc(size_t elementCount, size_t elementSize);
void			*ft_memmove(void *dest, const void *src, size_t c);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *str);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *first, const char *second,
					size_t length);
char			*ft_strnjoin(char *s1, char *s2, int byte_nbr);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*get_next_line(int fd);

#endif