/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:02:15 by lud-adam          #+#    #+#             */
/*   Updated: 2025/11/26 18:02:30 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H 
# define DISPLAY_H

# define WIDTH 1024
# define HEIGHT 1024
# define HEIGHT_MINIMAP 200 
# define WIDTH_MINIMAP 200
# define MAX_WIDTH 1250
# define MAX_HEIGHT 1250
# define SCALE_TILE	20

# define ASSET_TILE "/home/lud-adam/Documents/cube3d/assets/basic/bg.xpm"
# define ASSET_BG "/home/lud-adam/Documents/cube3d/assets/basic/end_bg.xpm"
# define ASSET_PLAYER "/home/lud-adam/Documents/cube3d/assets/basic/player.xpm"
# define BLACK 0x000000
// # define GREEN 0x008000
// # define RED 0xFF0000
// # define BLUE 0x0000FF

#define RED   0xFF0000FF
#define GREEN 0xFF00FF00
#define BLUE  0xFFFF0000

#include <stdbool.h>
#include <stdint.h>

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
	void				*ptr;
	char*				addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}					t_img;

typedef struct s_sprite
{
	t_img	ground;
	t_img	wall;
}				t_sprite;

typedef struct s_mlx
{
	char* buf;
	void	*ptr;
	void	*win;
	int		max_width;
	int		max_height;
}				t_mlx;

typedef struct	s_hero
{
	int	x;
	int	y;
}				t_hero;

typedef struct s_minimap
{
	t_hero	hero;
	int		scale_tile;
}				t_minimap;

typedef	struct	s_map
{
	char	grid[5][6];
	t_hero	hero_pos;
	int		rows;
	int		cols;
}				t_map;

typedef struct s_data
{
	t_mlx	mlx;
	t_img	img;
	t_map	map;
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
t_img	fill_frame(t_data* data, char *path_to_asset, int* x, int* y);
bool	display_minimap(t_data* data);
int		move_hero(int keycode, t_data *data);
void	update_maps(t_data* data);
void	draw_scaled_asset(t_pixel *dest_pixels, int dest_w, int dest_h, t_pixel *src_pixels, int src_size);

#endif
