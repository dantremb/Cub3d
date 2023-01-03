/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/20 11:38:39 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_init_colors(t_xpm *xpm, int ct)
{
	int		fd;

	xpm->name[ft_strlen(xpm->name) - 1] = '\0';
	fd = open(xpm->name, O_RDONLY, 0644);
	if (!fd)
	{
		printf("error, wrong open <init color>\n");
		exit(0);
	}
	if (ct == 1)
		ft_split_xpm(xpm);
	close(fd);
}

void	ft_init_floor_top(t_xpm *xpm)
{
	char	**tmp;

	tmp = ft_split(xpm->name, ',');
	if (!tmp)
	{
		printf("error, wrong alloc <init floor>\n");
		exit(0);
	}
	xpm->rgb.r = ft_atoi(tmp[0]);
	xpm->rgb.g = ft_atoi(tmp[1]);
	xpm->rgb.b = ft_atoi(tmp[2]);
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
	player->life = 400;
	return (player);
}

void	ft_init_vars2(t_game *game)
{
	game->ct.start = 1;
	game->ct.choose = 1;
	game->w = SCREENW;
	game->h = SCREENH;
	game->move_speed = 0.3;
	game->rot_speed = 0.015;
	game->gun = 1;
	game->rotate_gun = 1;
}

void	init_vars(t_game *game)
{
	ft_init_vars2(game);
	game->enemy0.dir.x = 1;
	game->imgs.handgun.ammo = 12;
	game->imgs.shotgun.ammo = 2;
	game->imgs.sniper.ammo = 5;
	game->imgs.handgun.total_ammo = 15;
	game->imgs.shotgun.total_ammo = 12;
	game->imgs.sniper.total_ammo = 8;
	game->all_ray = ft_calloc(sizeof(double), BUFF_SIZE);
	game->ray = malloc(sizeof(t_ray));
	if (!game->ray || ! game->all_ray)
	{
		printf("error, wrong malloc");
		exit(0);
	}
}
