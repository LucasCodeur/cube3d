/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:02:15 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/21 13:03:43 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "error.h"
# include "vector.h"
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>

# define WIN_WIDTH 2560
# define WIN_HEIGHT 1440

# define SIZE_X 20
# define SIZE_Y 20

# define BLACK 0x2c2c2c
# define RED 0xFF0000FF
# define ORANGE 0xFF6347
# define GREEN 0xFF00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF000
# define WHITE 0xFFFFFF00

# define ADD_SPEED 4.0 * (M_PI / 180)
# define SUBT_SPEED -4.0 * (M_PI / 180)
# define MIDDLE_SCREEN_X WIN_WIDTH / 2
# define MIDDLE_SCREEN_Y WIN_HEIGHT / 2
# define SPEED 0.25
# define ROTATE_FORWARD 90.0 * (M_PI / 180)
# define ROTATE_BACKWARD -90.0 * (M_PI / 180)
# define FPS 60
# define FRAME_DURATION 1.0 / FPS

# define MINI_OFFSET_X 10
# define MINI_OFFSET_Y 10
# define MINI_TILE 20
# define PLAYER_SIZE 4
# define MINI_RADIUS 6 

typedef struct s_parsing	t_parsing;

typedef struct s_garbage	t_garbage;

typedef struct s_garbage
{
	void					*ptr;
	t_garbage				*next;
}							t_garbage;

typedef struct s_rgb
{
	uint8_t					r;
	uint8_t					g;
	uint8_t					b;
	uint8_t					a;
}							t_rgb;

typedef union s_pixel
{
	unsigned int			value;
	t_rgb					rgb;
	uint8_t					channels[4];
}							t_pixel;

typedef struct s_minimap_variables
{
	t_pixel					color;
	int						x;
	int						y;
	int						start_x;
	int						start_y;
	int						end_x;
	int						end_y;
	int						player_screen_x;
	int						player_screen_y;
}							t_minimap_variables;

typedef struct s_img
{
	int						bits_per_pixel;
	int						line_length;
	int						endian;
	int						height;
	int						width;
	int						pixels_per_line;
	int						top_strip;
	int						bottom_strip;
	int						x;
	double					y;
	double					step;
	double					double_height;
	t_pixel					*addr;
	t_pixel					color;
	void					*img;
}							t_img;

typedef struct s_sprite
{
	t_img					wall_east;
	t_img					wall_north;
	t_img					wall_west;
	t_img					wall_south;
}							t_sprite;

typedef struct s_mlx
{
	char					*buf;
	void					*ptr;
	void					*win;
	int						max_width;
	int						max_height;
}							t_mlx;

typedef struct s_hero
{
	t_vec					dir;
	t_vec					pos;
	t_vec					plane;
	t_vec					camera;
	double					time;
	double					old_time;
	int						x;
	int						y;
	char					orientation;
}							t_hero;

typedef struct s_map
{
	char					**grid;
	int						width;
	int						height;
	int						rows;
	int						cols;
	int						map_finished;
	int						x;
	int						y;
	t_hero					player;
}							t_map;

typedef struct s_keycode
{
	bool					up;
	bool					down;
	bool					right;
	bool					left;
	bool					rotate_left;
	bool					rotate_right;
	bool					escape;
	bool					cross;
}							t_keycode;

typedef struct s_fps
{
	double					current_time;
	double					last_time;
	double					delta_time;
	int						count_frame;
	int						count;
}							t_fps;

typedef struct s_raycasting
{
	int						side;
	// WARN: have to take off
	int						tile_size;

	int						step_x;
	int						step_y;
	int						z;
	double					wall_x;
	double					wall_y;
	t_vec					ray_dir;
}							t_raycasting;

typedef struct s_data
{
	t_raycasting			raycasting;
	t_mlx					mlx;
	t_img					img;
	t_sprite				imgs;
	t_map					map;
	t_keycode				keycode;
	t_fps					fps;
	t_parsing				*parsing;
	t_garbage				*garbage;
}							t_data;

t_error						launcher(t_data *data);

// RAYCASTING
double						compute_dist(t_data *data, t_vec ray_dir);
t_vec						define_ray(t_data *data);
t_vec						define_percentage_of_fov(int x);
void						compute_height_of_line(t_data *data,
								int *draw_start, int *draw_end);
bool						draw_map(t_data *data);

// MLX
void						init_mlx(t_mlx *t_mlx);
t_error						init_screen_mlx(t_data *data);
void						free_img(t_data *data);
void						my_mlx_pixel_put(t_data *data, int x, int y,
								t_pixel *color);

// HOOKS
int							mouse_hook(int x, int y, t_data *data);
int							press_move(int keycode, t_data *data);
int							release_move(int keycode, t_data *data);
int							execute(t_data *data);
void						move_hero(t_data *data);
void						rotate_hero(t_data *data);

// IMAGE
t_error						load_imgs(t_data *data);
void						update_maps(t_data *data);
void						draw_hero(t_data *data, int tile_size);
void						clear_img(t_img *img);
void						choose_texture(t_data *data, t_img **text);
bool						draw_map(t_data *data);

// FPS
void						count_fps(t_data *data);
double						get_time(void);

// UTILS
void						ft_bzero(void *s, size_t n);
int							destroy_free_exit(t_data *data);

// MINIMAP
void						draw_minimap(t_data *data);

// MINIMAP UTILS
void						draw_square(t_data *data, int x, int y, int size,
								t_pixel color);

// OTHERS
double						get_time(void);

#endif
