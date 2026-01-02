/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:02:15 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/02 15:14:32 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H 
# define DISPLAY_H

# define WIN_WIDTH 1000
# define WIN_HEIGHT 800
# define SCALE_TILE	64
# define SIZE_X	20
# define SIZE_Y	20
# define FOV M_PI / 3.0
# define SCALE 48

# define ASSET_TILE "/home/lud-adam/Documents/cube3d/assets/basic/bg.xpm"
# define ASSET_BG "/home/lud-adam/Documents/cube3d/assets/basic/end_bg.xpm"
# define ASSET_PLAYER "/home/lud-adam/Documents/cube3d/assets/basic/player.xpm"

# define BLACK 0x000000
# define RED   0xFF0000FF
# define ORANGE 0xFF6347
# define GREEN 0xFF00FF00
# define BLUE  0x0000FF
# define YELLOW 0xFFFF000
# define WHITE 0xFFFFFF00

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "vector.h"

typedef struct s_rgb
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
}				t_rgb;

typedef union s_pixel
{
	unsigned int	value;
	t_rgb			rgb;
	uint8_t			channels[4];
}				t_pixel;

typedef struct s_img
{
	void	*ptr;
	char*	addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_sprite
{
	t_img	ground;
	t_img	wall;
}				t_sprite;

typedef struct s_mlx
{
	char	*buf;
	void	*ptr;
	void	*win;
	int		max_width;
	int		max_height;
}				t_mlx;

typedef struct	s_hero
{
	t_vec	dir;
	t_vec	pos;
	t_vec	plane;
	t_vec	camera;
	double	time;
	double	old_time;
}				t_hero;

typedef struct s_minimap
{
	t_hero	hero;
	int		scale_tile;
}				t_minimap;

typedef	struct	s_map
{
	int		witdh;
	int		height;
	char	grid[SIZE_Y][SIZE_X + 1];
	int		rows;
	int		cols;
	t_hero	player;
	int		x;
	int		y;
}				t_map;

typedef struct s_data
{
	int		tile_size;
	t_mlx	mlx;
	t_img	img;
	t_map	map;
	t_vec	ray_dir;
}				t_data;

void	launcher(t_data *data);
double	compute_dist(t_data* data, t_vec ray_dir);
t_vec	define_ray(t_data* data);
t_vec	define_percentage_of_fov(int x);
void	draw_line(t_data* data, int draw_start, int draw_end, int x);
void	compute_height_of_line(t_data* data, int* draw_start, int* draw_end);
bool	draw_map(t_data* data);

//MLX
void	init_mlx(t_mlx *t_mlx);
void	init_screen_mlx(t_data *data);
void	free_img(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, t_pixel *color);

//HOOKS
int		key_press(int keycode, void *param);
int		close_win(void *param);

//IMAGE
t_img	fill_frame(t_data* data, char *path_to_asset, int* x, int* y);
bool	display_map(t_data* data);
int		move_hero(int keycode, t_data *data);
void	update_maps(t_data* data);
bool	draw_map(t_data* data);
void	draw_hero(t_data* data, int tile_size);
void	clear_img(t_img *img);

//UTILS
void	ft_bzero(void *s, size_t n);

#endif
