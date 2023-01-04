/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_props_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:22:40 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/04 13:31:35 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_init_face(t_game *game)
{
	ft_init_sprites(game, game->imgs.faces.faces, "./fd/faces", 15);
	game->tmp_face = game->imgs.faces.faces[0];
}

void	ft_load_xpm(t_game *game, t_xpm *img, int fd)
{
	img->name = get_next_line(fd);
	ft_init_colors(game, img, 1);
	ft_free(img->name);
}

void	ft_init_logo(t_game *game, t_xpm *img, char *name)
{
	img->name = ft_strdup(name);
	ft_init_colors(game, img, 1);
	ft_free(img->name);
}

void	ft_init_shotgun(t_game *game)
{
	ft_init_sprites(game, game->imgs.shotgun.fire,
		"./fd/shotgun", 24);
	ft_init_logo(game, &game->imgs.shotgun.logo,
		"./pics/guns/shotgun/shotgun_logo.xpm\n");
}

void	ft_init_bullet(t_game *game)
{
	int	fd;

	fd = ft_open_fd("./fd/bullet", 1);
	if (fd < 0)
	{
		printf("error, <%s>", "./fd/bullet");
		x_quit(game);
	}
	ft_load_xpm(game, &game->imgs.handgun.bullet, fd);
	ft_load_xpm(game, &game->imgs.shotgun.bullet, fd);
	ft_load_xpm(game, &game->imgs.sniper.bullet, fd);
	close(fd);
}
