/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:13:43 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/07 01:05:39 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMGS_BONUS_H
# define IMGS_BONUS_H

# include "cube3d_bonus.h"

typedef unsigned int	t_uint;

typedef struct s_rgb
{
	int			t;
	int			r;
	int			g;
	int			b;
}	t_rgb;

typedef struct s_dvec2{
	double			x;
	double			y;
}				t_dvec2;

typedef struct s_walls {
	void	*eaglev;
	char	*eaglec;
	void	*redbrickv;
	char	*redbrickc;
	void	*purplestonev;
	char	*purplestonec;
	void	*greystonev;
	char	*greystonec;
	void	*bluestonev;
	char	*bluestonec;
	void	*mossyv;
	char	*mossyc;
	void	*woodv;
	char	*woodc;
	void	*colorstonev;
	char	*colorstonec;
}	t_walls;

typedef struct s_props {
	void	*barrelv;
	char	*barrelc;
	void	*pillarv;
	char	*pillarc;
	void	*greenlightv;
	char	*greenlightc;
}	t_props;

typedef struct s_xpm {
	t_uint			**tile;
	int				endian;
	int				pixel;
	int				bpp;
	int				len_x;
	int				len_y;
	int				coll;
	int				pos_x;
	int				pos_y;
	void			*img;
	char			*c_nbr;
	char			**cpy_fd;
	char			**colors;
	char			**all_colors;
	char			**tab;
	char			*name;
	t_rgb			rgb;
}	t_xpm;

typedef struct s_skull {
	void		*skulla;
	void		*skullb;
	void		*skullc;
	void		*skulld;

	int			posx;
	int			posy;
}	t_skull;

typedef struct s_enemy {
	t_xpm		death[10];
	t_xpm		face[4];
	t_xpm		back[4];
	t_xpm		right[4];
	t_xpm		lft[4];

	t_dvec2		pos;
	t_dvec2		dir;
}	t_enemy;

typedef struct s_door {
	t_xpm		door0[15];

	int			posx;
	int			posy;
}	t_door;

typedef struct s_faces {
	t_xpm		faces[15];

	int			posx;
	int			posy;
}	t_faces;

typedef struct s_shotgun {
	t_xpm		logo;
	t_xpm		bullet;
	t_xpm		fire[24];		

	int			posx;
	int			posy;
	int			ammo;
	int			total_ammo;
}	t_shotgun;

typedef struct s_handgun {
	t_xpm		handgun;
	t_xpm		logo;
	t_xpm		bullet;
	t_xpm		reload[26];
	t_xpm		fire[6];
	t_xpm		rotate[9];

	int			i;
	int			posx;
	int			posy;
	int			ammo;
	int			total_ammo;
}	t_handgun;

typedef struct s_knife {
	t_xpm		knife[11];
	t_xpm		logo;

	int			i;
	int			posx;
	int			posy;
}	t_knife;

typedef struct s_sniper {
	t_xpm		shoot_zoom[18];
	t_xpm		sniper[15];
	t_xpm		load[37];
	t_xpm		zoom[7];
	t_xpm		bullet;
	t_xpm		logo;

	int			i;
	int			posx;
	int			posy;
	int			ammo;
	int			total_ammo;
}	t_sniper;

typedef struct s_reload {
	t_xpm		load[18];

	int			posx;
	int			posy;
}	t_reload;

typedef struct s_barrel {
	t_xpm		barrel[3];

	int			posx;
	int			posy;
}	t_barrel;

typedef struct s_nbrs {
	t_xpm		nbrs[11];

	int			posx;
	int			posy;
}	t_nbrs;

typedef struct s_skulls {
	t_xpm		skulls[4];

	int			pos_start;
	int			pos_quit;
	int			posx;
	int			posy;
}	t_skulls;

typedef struct s_cursor {
	t_xpm		cursor;

	int			posx;
	int			posy;
}	t_cursor;

typedef struct s_roof {
	t_rgb	roof;
}	t_roof;

typedef struct s_ground {
	t_rgb	ground;
}	t_ground;

typedef struct s_imgs {
	t_walls		walls;
	t_props		props;

	t_faces		faces;

	t_xpm		menu;
	t_cursor	cursor;
	t_xpm		xpm;
	t_xpm		img;
	t_nbrs		nbrs;

	t_shotgun	shotgun;
	t_handgun	handgun;
	t_sniper	sniper;
	t_knife		knife;

	t_reload	reload;
	t_barrel	barrel;
	t_skulls	skulls;

	t_xpm		texture_n;
	t_xpm		texture_s;
	t_xpm		texture_e;
	t_xpm		texture_w;

	t_xpm		wall_blood_00;
	t_xpm		wall_extra;
	t_xpm		light_00;
	t_xpm		light_01;
	t_xpm		light_02;

	t_xpm		down;
	t_xpm		top;

	t_xpm		roof;
	t_xpm		floor;

	t_xpm		hit;

	t_xpm		doors0;
	t_door		doors;
}	t_imgs;

#endif