/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:08:24 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/04 13:44:40 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_init_imgs_from_argc(t_game *game)
{
	ft_init_colors(game, &game->imgs.texture_n, 1);
	ft_init_colors(game, &game->imgs.texture_s, 1);
	ft_init_colors(game, &game->imgs.texture_e, 1);
	ft_init_colors(game, &game->imgs.texture_w, 1);
	ft_init_floor_top(game, &game->imgs.top);
	ft_init_floor_top(game, &game->imgs.down);
}

void	ft_init_menu(t_game *game)
{
	game->imgs.menu.name = ft_strdup("./pics/other/menu_all.xpm\n");
	ft_init_colors(game, &game->imgs.menu, 1);
}

void	ft_init_sprites(t_game *game, t_xpm *imgs, char *name, int ct)
{
	int	fd;
	int	i;

	fd = ft_open_fd(name, 1);
	if (fd < 0)
	{
		printf("error, <%s>", name);
		x_quit(game);
	}
	i = -1;
	while (++i < ct)
		ft_load_xpm(game, &imgs[i], fd);
	close(fd);
}

void	ft_init_imgs_extra(t_game *game)
{
	game->imgs.light_00.name = ft_strdup("./pics/walls/wall_light0_00.xpm\n");
	ft_init_colors(game, &game->imgs.light_00, 1);
	game->imgs.light_01.name = ft_strdup("./pics/walls/wall_light0_01.xpm\n");
	ft_init_colors(game, &game->imgs.light_01, 1);
	game->imgs.light_02.name = ft_strdup("./pics/walls/wall_light0_02.xpm\n");
	ft_init_colors(game, &game->imgs.light_02, 1);
	game->imgs.wall_extra.name = ft_strdup("./pics/walls/wall_17.xpm\n");
	ft_init_colors(game, &game->imgs.wall_extra, 1);
	game->imgs.wall_blood_00.name = ft_strdup("./pics/walls/wall_20.xpm\n");
	ft_init_colors(game, &game->imgs.wall_blood_00, 1);
	game->imgs.roof.name = ft_strdup("./pics/floor/floor_plate.xpm\n");
	ft_init_colors(game, &game->imgs.roof, 1);
	game->imgs.floor.name = ft_strdup("./pics/floor/purple.xpm\n");
	ft_init_colors(game, &game->imgs.floor, 1);
	game->imgs.hit.name = ft_strdup("./pics/hit.xpm\n");
	ft_init_colors(game, &game->imgs.hit, 1);
}

void	ft_init_imgs(t_game *game)
{
	game->mus_ct = 1;
	ft_music(game);
	ft_start_threads(game);
	ft_end_threads(game);
	ft_init_imgs_extra(game);
	ft_init_imgs_from_argc(game);
	ft_init_menu(game);
	ft_init_sprites(game, game->imgs.doors.door0, "./fd/door", 15);
	ft_init_sprites(game, game->enemy0.face, "./fd/enemy00/face", 4);
	ft_init_sprites(game, game->imgs.nbrs.nbrs, "./fd/nbrs", 11);
	ft_init_bullet(game);
	game->imgs.img.img = mlx_new_image(game->mlx, game->w, game->h);
	game->imgs.img.name = mlx_get_data_addr(game->imgs.img.img,
			&game->bpp, &game->pixel, &game->endian);
	system("killall afplay");
	game->mus_ct = 2;
	ft_music(game);
}
