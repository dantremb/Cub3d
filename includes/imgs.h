/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:13:43 by nadesjar          #+#    #+#             */
/*   Updated: 2022/11/01 18:58:57 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMGS_H
# define IMGS_H

# include "cube3d.h"

typedef unsigned int	t_uint;

typedef struct s_rgb
{
	int			t;
	int			r;
	int			g;
	int			b;
}	t_rgb;

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

typedef struct s_imgs {
	t_xpm		xpm;
	t_xpm		img;
	t_xpm		texture_n;
	t_xpm		texture_s;
	t_xpm		texture_e;
	t_xpm		texture_w;
	t_xpm		down;
	t_xpm		top;
}	t_imgs;

#endif