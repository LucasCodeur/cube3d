/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_custom.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:02:15 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/11 20:17:01 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CUSTOM_H 
# define MLX_CUSTOM_H
# define WIDTH 1250
# define HEIGHT 1250

#include "mlx.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	int		max_width;
	int		max_height;
}				t_mlx;

void		init_mlx(t_mlx *t_mlx);
void		init_screen_mlx(t_mlx *data);
void		free_img(t_mlx *t_mlx);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);

//HOOKS
int			key_press(int keycode, void *param);
int			close_win(void *param);

#endif
