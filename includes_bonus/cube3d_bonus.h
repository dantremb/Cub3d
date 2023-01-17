/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:44:15 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/17 16:05:29 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_BONUS_H
# define CUBE3D_BONUS_H

//# include "../minilibx/MLX42/include/MLX42/MLX42_int.h"
//# include "../minilibx/mlx-linux/mlx.h"
# include "../srcs/libft/libft.h"
# include "../minilibx/opengl/mlx.h"
# include "imgs_bonus.h"
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>
# include <pthread.h>

# define SCREENW 1500
# define SCREENH 980
# define TILESIZE 256
# define MAPW 24
# define MAPH 24
# define BUFF_SIZE 12000
# define S_PIXEL 8
# define PRECISION 1

// parameters for scaling and moving the sprites
# define UDIV 1
# define VDIV 1
# define VMOVE 0.0

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

typedef struct s_vector_2f {
	float			x;
	float			y;
}	t_vector2f;

typedef struct s_vector3 {
	int				x;
	int				y;
	int				z;
}	t_vector3;

/* Counters */
typedef struct s_ct {
	int				music;
	int				start;
	int				choose;
	int				face;
	int				light00;
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
	t_pos			last_pos;
	t_pos			dir;
	t_pos			plane;
	float			pa;
	int				life;
	int				i;
	int				k;
	int				x;
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

typedef struct s_ray_enemy{
	t_vector2	draw_start;
	t_vector2	draw_end;
	t_vector2	pos;
	t_vector2	tex;
	t_pos		transform;
	t_pos		sprite;
	int			sprite_screen_x;
	int			v_move_screen;
	int			sprite_height;
	int			sprite_width;
	int			stripe;
}	t_ray_enemy;

typedef struct s_ray_topdown{
	t_vector2f	ray_dir0;
	t_vector2f	ray_dir1;
	t_vector2f	floor_step;
	t_vector2f	floor;
	t_vector2	xy;
	float		pos_z;
}	t_ray_topdown;

typedef struct s_music{
	pthread_t	mus_t[2];
	int			onoff;
	int			ct_mus;
	int			quit;
}	t_music;

/* General */
typedef struct s_game {
	void			*mlx;
	void			*win;

	t_imgs			imgs;
	t_ray			*ray;
	t_len			len;
	t_ct			ct;

	t_skull			skulls;
	t_music			music;

	char			**world_map;
	char			**tmp;

	double			wall_distance;
	double			plane_x;
	double			plane_y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;

	void			**textures;
	void			*vmenu;
	char			*cmenu;

	int				endian;
	int				pixel;
	int				color;
	int				bpp;
	int				h;
	int				w;

	t_ply			*player;
	t_enemy			enemy0;
	t_vector2		pos1;

	double			move_speed;
	double			rot_speed;

	t_ray_enemy		ray_enemy;
	double			*all_ray;
	t_ray_topdown	topdown;

	pthread_t		load_imgs[2];
	pthread_t		load_imgs2[2];
	pthread_t		load_imgs3[2];
	pthread_t		load_imgs4[2];
	pthread_t		load_imgs5[2];
	pthread_t		load_imgs6[2];

	int				zoom;
	int				gun;
	int				rotate_gun;
	t_xpm			tmp_face;
	t_xpm			tmp_gun;
	t_xpm			tmp_light00;
	int				gun_up;
	int				reload;
	int				fire;
	t_vector2		last;

	int				shoot;
	int				poskull_a;
	int				poskull_b;
	void			*menuskull;
	void			*bgv;
	void			*test2;
	void			*test;
	void			*shgun;
	char			*face;
	int				move_gun;
	int				mus_ct;
	int				door_ct;
	int				door_open_ct;
	int				see_door;
	int				see_enemy;
	int				door_mapx;
	int				door_mapy;
	int				enemy_mapx;
	int				enemy_mapy;
	t_ply			*save_ply;
	t_ray			*save_ray;
	t_enemy			*save_enemy;
	double			zoom_up;
	int				scale_floorx;
	int				ct_hit;

	int				move_w;
	int				move_a;
	int				move_s;
	int				move_d;
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

bool	ft_valid_map(char *line);
bool	ft_str_is_num(char *str);

/***************************** Utility *****************************/

void	ft_check_moves(t_game *game, int x);
void	ft_check_enemy_hit(t_game *game);
void	ft_open_door(t_game *game);
void	ft_replace_or_load(char **texture, char *temp);

int		ft_charcmp(unsigned char a, unsigned char b);
int		ft_convert_bits(t_byte *raw);

bool	ft_wait3(int delay);
bool	ft_wait2(int delay);
bool	ft_wait(int delay);

/**************************** Init game ****************************/

t_ply	*ft_init_player(t_game *game);

char	*ft_change_sygn2(t_xpm *xpm, char *buff);

void	ft_split_xpm_save_colors_suite(t_xpm *xpm, int i, int k);
void	ft_split_xpm_save_colors(t_xpm *xpm, int i);
void	ft_load_texture(t_game *game, char *temp);
void	ft_init_reload_handgun(t_game *game);
void	ft_init_logo(t_game *game, t_xpm *img, char *name);
void	ft_start_threads(t_game *game);
void	ft_init_shotgun(t_game *game);
void	ft_end_threads(t_game *game);
void	ft_init_skulls(t_game *game);
void	ft_init_bullet(t_game *game);
void	ft_init_face(t_game *game);
void	ft_init_imgs(t_game *game);
void	ft_mount_tile(t_xpm *xpm);
void	init_vars(t_game *game);

void	*ft_load_imgs1(void *arg);
void	*ft_load_imgs2(void *arg);
void	*ft_load_imgs3(void *arg);
void	*ft_load_imgs4(void *arg);
void	*ft_load_imgs5(void *arg);

int		ft_split_xpm_save_all_colors(t_xpm *xpm, int i);

/***************************** Control *****************************/

void	move_mouse_x(t_game *game, int x);
void	ft_ctrl_menu(int key, t_game *game);
void	ft_move_w(t_game *game);
void	ft_move_a(t_game *game);
void	ft_move_s(t_game *game);
void	ft_move_d(t_game *game);

int		ft_shoot(int button, int x, int y, t_game *game);
int		mouse_move(int x, int y, t_game *game);
int		key_release(int key, t_game *game);
int		key_press(int key, t_game *game);

/**************************** RayCasting ****************************/

t_xpm	*ft_take_good_wall(t_game *game, t_ray *ray);
t_xpm	*ft_take_good_wall_enemy(t_game *game);
t_xpm	*ft_take_good_wall_d(t_game *game);

void	ft_draw_line_d(t_game *game, int line_height, t_ray *ray);
void	ft_draw_line(t_game *game, int line_height, t_ray *ray);
void	ft_ray_init(t_game *game, t_ray *ray, t_ply *player);
void	ft_raycast_suite_enemy(t_game *game, t_ray *ray);
void	ft_raycast_suite_d(t_game *game, t_ray *ray);
void	ft_raycast_hit_d(t_game *game, t_ray *ray);
void	ft_raycast_suite(t_game *game, t_ray *ray);
void	ft_raycast_enemy(t_game *game, int ct);
void	ft_raycast_rooftop(t_game *game);
void	ft_raycast_d(t_game *game);
void	ft_raycast(t_game *game);

int		ft_routine(t_game *game);

/******************************* Draw *******************************/

void	ft_print_sprite(t_game *game, t_xpm *img,
			t_vector2 start_pos, t_uint color);
void	ft_init_sprites(t_game *game, t_xpm *imgs, char *name, int ct);
void	draw_color(t_game *game, char *img, t_vector2 pos, int color);
void	ft_put_handgun(t_game *game, t_vector2 pos, int *i, int *k);
void	ft_draw_line(t_game *game, int line_height, t_ray *ray);
void	ft_reload_sniper_suite(t_game *game, int *i, int *k);
void	ft_put_shotgun(t_game *game, t_vector2 pos, int *i);
void	ft_put_sniper(t_game *game, t_vector2 pos, int *i);
void	ft_put_knife(t_game *game, t_vector2 pos, int *i);
void	ft_sniper_zoom_out(t_game *game, int *i, int *k);
void	ft_sniper_anim_end(t_game *game, int *i, int *k);
void	ft_zoom_out_sniper2(t_game *game, int *k);
void	ft_zoom_out_sniper1(t_game *game, int *k);
void	ft_init_colors(t_game *game, t_xpm *xpm, int ct);
void	ft_put_weapon_logo(t_game *game);
void	ft_load_xpm(t_game *game, t_xpm *img, int fd);
void	ft_read_xpm(t_xpm *xpm, int fd);
void	ft_reload_sniper(t_game *game);
void	ft_init_floor_top(t_game *game, t_xpm *xpm);
void	ft_choose_ammo(t_game *game);
void	ft_put_lifebar(t_game *game);
void	ft_put_weapon(t_game *game);
void	ft_put_faces(t_game *game);
void	draw_minimap(t_game *game);
void	ft_put_menu(t_game *game);
void	draw_cursor(t_game *game);
void	ft_split_xpm(t_game *game, t_xpm *xpm);
void	ft_reload(t_game *game);
void	ft_skulls(t_game *game);

int		get_img_color(t_xpm *img, int x, int y);
int		create_trgb(int t, int r, int g, int b);

t_uint	ft_return_rgb(char *str);
t_rgb	hex_to_rgb(int color);

/****************************** Update ******************************/

void	ft_update_imgs(t_game *game);
void	ft_music(t_game *game);

/******************************* Kill *******************************/

void	ft_free_imgs1(t_game *game);
void	ft_free_imgs2(t_game *game);
void	ft_free_imgs3(t_game *game, int i);
void	ft_free_imgs4(t_game *game, int i);
void	ft_free_imgs5(t_game *game, int i);

bool	hit_box(t_game *game);

double	ft_pythagore(double x, double y);

int		x_quit(t_game *game);

#endif
