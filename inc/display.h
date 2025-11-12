/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:02:15 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/12 17:30:11 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H 
# define DISPLAY_H
# define WIDTH 1250
# define HEIGHT 1250
# define MAX_WIDTH 1250
# define MAX_HEIGHT 1250

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_img;

typedef struct s_sprite
{
	t_img	ground;
	t_img	wall;
}				t_sprite;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	int		max_width;
	int		max_height;
}				t_mlx;

typedef struct s_data
{
	t_mlx	mlx;
	t_img	img;
}				t_data;

//MLX
void		init_mlx(t_mlx *t_mlx);
void		init_screen_mlx(t_data *data);
void		free_img(t_data *data);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);

//HOOKS
int			key_press(int keycode, void *param);
int			close_win(void *param);

//IMAGE
t_img	fill_image(t_data* data, char *path_to_asset);

#endif
