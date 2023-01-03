/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:45:47 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/14 04:07:14 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	*ft_load_imgs1(void *arg)
{
	t_game	*game;

	game = arg;
	ft_init_sprites(game, game->imgs.sniper.load, "./fd/sniper_reload", 36);
	return (NULL);
}

void	*ft_load_imgs2(void *arg)
{
	t_game	*game;

	game = arg;
	ft_init_sprites(game, game->imgs.sniper.shoot_zoom,
		"./fd/sniper_shoot_zoom", 18);
	ft_init_logo(&game->imgs.sniper.logo,
		"./pics/guns/sniper/sniper_logo.xpm\n");
	ft_init_sprites(game, game->imgs.skulls.skulls, "./fd/skulls", 4);
	return (NULL);
}

void	*ft_load_imgs3(void *arg)
{
	t_game	*game;

	game = arg;
	game->imgs.handgun.i = 0;
	game->imgs.handgun.handgun.name = ft_strdup("./pics/guns/handgun/01.xpm\n");
	ft_init_colors(&game->imgs.handgun.handgun, 1);
	free(game->imgs.handgun.handgun.name);
	ft_init_sprites(game, game->imgs.handgun.fire, "./fd/shoot_handgun", 6);
	ft_init_sprites(game, game->imgs.handgun.rotate, "./fd/rotate", 9);
	ft_init_logo(&game->imgs.handgun.logo,
		"./pics/guns/handgun/handgun_logo.xpm\n");
	ft_init_logo(&game->imgs.knife.logo, "./pics/guns/knife/knife_logo.xpm\n");
	ft_init_sprites(game, game->imgs.sniper.zoom, "./fd/sniper_zoom", 7);
	return (NULL);
}

void	*ft_load_imgs4(void *arg)
{
	t_game	*game;

	game = arg;
	ft_init_sprites(game, game->imgs.handgun.reload, "./fd/reload_handgun", 26);
	return (NULL);
}

void	*ft_load_imgs5(void *arg)
{
	t_game	*game;

	game = arg;
	ft_init_sprites(game, game->imgs.knife.knife, "./fd/knife", 11);
	ft_init_sprites(game, game->imgs.sniper.sniper, "./fd/sniper", 15);
	ft_init_face(game);
	return (NULL);
}
