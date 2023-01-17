/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_sniper_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:52:30 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/14 04:03:58 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_zoom_out_sniper1(t_game *game, int *k)
{
	t_vector2	pos;

	pos.x = 0;
	pos.y = 0;
	if ((game->imgs.sniper.total_ammo <= 0 || game->imgs.sniper.ammo == 5)
		&& game->zoom != 4)
	{
		game->reload = 0;
		ft_print_sprite(game, &game->imgs.sniper.sniper[0], pos, -16777216);
		return ;
	}
	if (game->zoom == 1)
	{
		game->zoom = 2;
		*k = 6;
	}
}

void	ft_zoom_out_sniper2(t_game *game, int *k)
{
	t_vector2	pos;

	pos.x = 0;
	pos.y = 0;
	if (*k >= 0)
	{
		ft_print_sprite(game, &game->imgs.sniper.zoom[*k], pos, -16777216);
		*k -= 1;
	}
	else
	{
		ft_print_sprite(game, &game->imgs.sniper.zoom[0], pos, -16777216);
		game->zoom = 3;
	}
}

void	ft_sniper_anim_end(t_game *game, int *i, int *k)
{
	int	ammo;

	if (game->imgs.sniper.ammo + game->imgs.sniper.total_ammo < 5)
	{
		game->imgs.sniper.ammo = game->imgs.sniper.ammo
			+ game->imgs.sniper.total_ammo;
		game->imgs.sniper.total_ammo = 0;
	}
	else
	{
		ammo = 5 - game->imgs.sniper.ammo;
		game->imgs.sniper.total_ammo -= ammo;
		game->imgs.sniper.ammo += ammo;
		if (game->imgs.sniper.total_ammo < 0)
			game->imgs.sniper.total_ammo = 0;
	}
	if (game->zoom == 3)
	{
		game->zoom = 4;
		*k = 0;
		return ;
	}
	*i = 0;
	game->reload = 0;
}

void	ft_reload_sniper_suite(t_game *game, int *i, int *k)
{
	t_vector2	pos;

	pos.x = 0;
	pos.y = 0;
	ft_print_sprite(game, &game->imgs.sniper.load[*i], pos, -16777216);
	if (*i == 0)
		system("afplay ./music/reload_sniper.mp3 &");
	*i += 1;
	if (*i >= 36)
		ft_sniper_anim_end(game, i, k);
}

void	ft_sniper_zoom_out(t_game *game, int *i, int *k)
{
	t_vector2	pos;

	pos.x = 0;
	pos.y = 0;
	if (*k < 6)
	{
		ft_print_sprite(game, &game->imgs.sniper.zoom[*k], pos, -16777216);
		*k += 1;
	}
	else
	{
		ft_print_sprite(game, &game->imgs.sniper.zoom[6], pos, -16777216);
		*i = 0;
		game->reload = 0;
		game->zoom = 1;
	}
}
