/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:44:15 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/03 11:41:26 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../srcs/libft/libft.h"
// # include "../minilibx/MLX42/include/MLX42/MLX42_int.h"
// # include "../minilibx/mlx-linux/mlx.h"
# include "../minilibx/opengl/mlx.h"
# include "imgs.h"
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>
# include <pthread.h>

# define SCREENW 800
# define SCREENH 600
# define TILESIZE 256
# define MAPW 24
# define MAPH 24
# define BUFF_SIZE 6000
# define S_PIXEL 8
# define PRECISION 0.8

typedef unsigned char	t_byte;
typedef unsigned int	t_uint;

/* Control Key */

typedef struct s_pos{
	double			x;
	double			y;
}				t_pos;

typedef struct s_vector_2 {
	int				x;
	int				y;
}	t_vector2;

/* Counters */
typedef struct s_ct {
	int				map_size;
	int				last_y;
	int				error;
	int				error2;
	int				i;
	int				k;
}	t_ct;

/* Len */
typedef struct s_len {
	int				max_len_x;
	int				len_y;
}	t_len;

typedef struct s_ply {
	t_pos			pos;
	t_pos			dir;
	t_pos			plane;
	float			pa;
}	t_ply;

typedef struct s_ray {
	t_pos			pos;
	double			camerax;
	t_pos			raydir;
	t_pos			side_d;
	t_pos			delta_d;
	t_vector2		map;
	t_vector2		step;
	t_vector2		draw;
	int				side;

	t_pos			v;
	t_vector2		w;
	t_vector2		text;
	t_pos			t_step;
	t_pos			tpos;
	int				mouse_y;
}	t_ray;

/* General */
typedef struct s_game {
	void			*mlx;
	void			*win;

	t_imgs			imgs;
	t_ray			*ray;
	t_len			len;
	t_ct			ct;

	char			**world_map;
	char			**tmp;

	double			plane_x;
	double			plane_y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;

	int				endian;
	int				pixel;
	int				color;
	int				bpp;
	int				h;
	int				w;

	t_ply			*player;

	double			move_speed;
	double			rot_speed;

	int				move_w;
	int				move_a;
	int				move_s;
	int				move_d;
	int				move_ri;
	int				move_lft;
}	t_game;

/***************************** Check *****************************/

void	check_entry(t_game *game, int entry, char *name);
void	map_read(t_game *game, char *name);
void	check_boarder_01(t_game *game);
void	ft_check_double(t_game *game);
void	check_direction(t_game *game);
void	ft_change_nsew(t_game *game);
void	check_board(t_game *game);
void	check_char(t_game *game);
void	save_map(t_game *game);
void	map_size(t_game *game);

int		ft_check_set(int c, const char *set);
int		check_name(char *name);

/***************************** Utility *****************************/

int		ft_charcmp(unsigned char a, unsigned char b);
int		ft_convert_bits(t_byte *raw);

/**************************** Init game ****************************/

t_ply	*ft_init_player(t_game *game);

char	*ft_change_sygn2(t_xpm *xpm, char *buff);

void	ft_split_xpm_save_colors_suite(t_xpm *xpm, int i, int k);
void	ft_split_xpm_save_colors(t_xpm *xpm, int i);
void	ft_load_texture(t_game *game, char *temp);
void	ft_init_imgs(t_game *game);
void	ft_mount_tile(t_xpm *xpm);
void	init_vars(t_game *game);

int		ft_split_xpm_save_all_colors(t_xpm *xpm, int i);

/***************************** Control *****************************/

void	ft_move_lft(t_game *game);
void	ft_move_ri(t_game *game);
void	ft_move_w(t_game *game);
void	ft_move_a(t_game *game);
void	ft_move_s(t_game *game);
void	ft_move_d(t_game *game);

int		key_release(int key, t_game *game);
int		key_press(int key, t_game *game);

/**************************** RayCasting ****************************/

t_xpm	*ft_take_good_wall(t_game *game, t_ray *ray);

void	ft_draw_line(t_game *game, int line_height, t_ray *ray);
void	ft_ray_init(t_game *game, t_ray *ray, t_ply *player);
void	ft_raycast_suite(t_game *game, t_ray *ray);
void	ft_raycast(t_game *game);

int		ft_routine(t_game *game);

/******************************* Draw *******************************/

void	ft_print_sprite(t_game *game, t_xpm *img,
			t_vector2 start_pos, t_uint color);
void	ft_init_sprites(t_game *game, t_xpm *imgs, char *name, int ct);
void	draw_color(t_game *game, char *img, t_vector2 pos, int color);
void	ft_draw_line(t_game *game, int line_height, t_ray *ray);
void	ft_init_colors(t_xpm *xpm, int ct);
void	ft_load_xpm(t_xpm *img, int fd);
void	ft_read_xpm(t_xpm *xpm, int fd);
void	ft_init_floor_top(t_xpm *xpm);
void	ft_split_xpm(t_xpm *xpm);

int		get_img_color(t_xpm *img, int x, int y);
int		create_trgb(int t, int r, int g, int b);

t_uint	ft_return_rgb(char *str);
t_rgb	hex_to_rgb(int color);

/****************************** Update ******************************/

void	ft_update_imgs(t_game *game);

/******************************* Kill *******************************/

int		x_quit(t_game *game);

#endif