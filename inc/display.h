/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:02:15 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/08 12:10:51 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H 
# define DISPLAY_H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#include "vector.h"

# define WIN_WIDTH 2000
# define WIN_HEIGHT 1600
# define SIZE_X	20
# define SIZE_Y	20

# define ASSET_PLAYER "/home/lud-adam/Documents/cube3d/assets/basic/player.xpm"
# define ASSET_W_EAST "/home/lud-adam/Documents/cube3d/assets/textures/east.xpm"
# define ASSET_W_NORTH "/home/lud-adam/Documents/cube3d/assets/textures/north.xpm"
# define ASSET_W_WEST "/home/lud-adam/Documents/cube3d/assets/textures/west.xpm"
# define ASSET_W_SOUTH "/home/lud-adam/Documents/cube3d/assets/textures/south.xpm"

# define BLACK 0x2c2c2c
# define RED   0xFF0000FF
# define ORANGE 0xFF6347
# define GREEN 0xFF00FF00
# define BLUE  0x0000FF
# define YELLOW 0xFFFF000
# define WHITE 0xFFFFFF00

# define ADD_SPEED 5.0 * (M_PI / 180)
# define SUBT_SPEED -5.0 * (M_PI / 180)

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
	void	*img;
	char*	addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
	t_pixel	color;
}			t_img;

typedef struct s_sprite
{
	t_img	ground;
	t_img	wall_east;
	t_img	wall_north;
	t_img	wall_west;
	t_img	wall_south;
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
	char	orientation;
	t_vec	dir;
	t_vec	pos;
	t_vec	plane;
	t_vec	camera;
	double	time;
	double	old_time;
	int		x;
	int		y;
}				t_hero;

typedef	struct	s_map
{
	char	**map_lines;
	int		width;
	int		height;
	char	grid[SIZE_Y][SIZE_X + 1];
	int		rows;
	int		cols;
	int		map_finished;
	int		x;
	int		y;
	t_hero	player;
}				t_map;

typedef struct s_data
{
	int			side;
	int			tile_size;
	double		wall_x;
	double		wall_y;
	t_mlx		mlx;
	t_img		img;
	t_sprite	imgs;
	t_map		map;
	t_vec		ray_dir;
}				t_data;

void	launcher(t_data *data);
double	compute_dist(t_data* data, t_vec ray_dir);
t_vec	define_ray(t_data* data);
t_vec	define_percentage_of_fov(int x);
void	compute_height_of_line(t_data* data, int* draw_start, int* draw_end);
bool	draw_map(t_data* data);
void	load_imgs(t_data *data);

//MLX
void	init_mlx(t_mlx *t_mlx);
void	init_screen_mlx(t_data *data);
void	free_img(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, t_pixel *color);

//HOOKS
int		key_press(int keycode, void *param);
int		close_win(void *param);
int		move_hero(int keycode, t_data *data);

//IMAGE
t_img	fill_frame(t_data* data, char *path_to_asset, int* x, int* y);
void	update_maps(t_data* data);
bool	draw_map(t_data* data);
void	draw_hero(t_data* data, int tile_size);
void	clear_img(t_img *img);
t_img	choose_texture(t_data *data);

//UTILS
void	ft_bzero(void *s, size_t n);

#endif
