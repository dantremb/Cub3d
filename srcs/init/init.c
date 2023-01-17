/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/17 16:03:43 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_init_colors(t_game *game, t_xpm *xpm, int ct)
{
	int		fd;

	xpm->name[ft_strlen(xpm->name) - 1] = '\0';
	fd = open(xpm->name, O_RDONLY, 0644);
	if (fd < 0)
	{
		printf("error, wrong open <init color>\n");
		x_quit(game);
	}
	if (ct == 1)
		ft_split_xpm(game, xpm);
	close(fd);
}

void	ft_init_floor_top(t_game *game, t_xpm *xpm)
{
	char	**tmp;

	if (xpm->name[ft_strlen(xpm->name) - 1] == '\n')
		xpm->name[ft_strlen(xpm->name) - 1] = '\0';
	tmp = ft_split(xpm->name, ',');
	if (!tmp || !ft_str_is_num(tmp[0]) || !ft_str_is_num(tmp[1]) || !ft_str_is_num(tmp[2]))
	{
		printf("error, color miss or not num\n");
		x_quit(game);
	}
	xpm->rgb.r = ft_atoi(tmp[0]);
	xpm->rgb.g = ft_atoi(tmp[1]);
	xpm->rgb.b = ft_atoi(tmp[2]);
	if (xpm->rgb.r > 255 || xpm->rgb.r < 0 || xpm->rgb.g > 255
		|| xpm->rgb.g < 0 || xpm->rgb.b > 255 || xpm->rgb.b < 0)
	{
		printf("error, color over 255 or less than 0\n");
		x_quit(game);
	}
	xpm->coll = create_trgb(0, xpm->rgb.r, xpm->rgb.g, xpm->rgb.b);
	ft_free_ptr((void *)tmp);
}

t_ply	*ft_init_player(t_game *game)
{
	t_ply	*player;

	player = malloc(sizeof(*player));
	if (!player)
		return (NULL);
	player->pa = 1;
	player->pos.x = game->pos_x;
	player->pos.y = game->pos_y;
	player->dir.x = game->dir_x;
	player->dir.y = game->dir_y;
	player->plane.x = game->plane_x;
	player->plane.y = game->plane_y;
	return (player);
}

void	init_vars(t_game *game)
{
	game->move_w = 0;
	game->move_a = 0;
	game->move_s = 0;
	game->move_d = 0;
	game->move_ri = 0;
	game->move_lft = 0;
	game->w = SCREENW;
	game->h = SCREENH;
	game->ct.error2 = 0;
	game->move_speed = 0.15;
	game->rot_speed = 0.05;
	game->ray = malloc(sizeof(t_ray));
	if (!game->ray)
	{
		printf("error, wrong malloc");
		x_quit(game);
	}
}

void	ft_init_imgs(t_game *game)
{
	ft_init_colors(game, &game->imgs.texture_n, 1);
	ft_init_colors(game, &game->imgs.texture_s, 1);
	ft_init_colors(game, &game->imgs.texture_e, 1);
	ft_init_colors(game, &game->imgs.texture_w, 1);
	ft_init_floor_top(game, &game->imgs.top);
	ft_init_floor_top(game, &game->imgs.down);
	game->imgs.img.img = mlx_new_image(game->mlx, game->w, game->h);
	game->imgs.img.name = mlx_get_data_addr(game->imgs.img.img,
			&game->bpp, &game->pixel, &game->endian);
}
