/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_handgun_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:21:58 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/07 01:59:24 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_handgun_anim_end(t_game *game, int *i)
{
	int	ammo;

	if (game->imgs.handgun.ammo + game->imgs.handgun.total_ammo < 12)
	{
		game->imgs.handgun.ammo = game->imgs.handgun.ammo
			+ game->imgs.handgun.total_ammo;
		game->imgs.handgun.total_ammo = 0;
	}
	else
	{
		ammo = 12 - game->imgs.handgun.ammo;
		game->imgs.handgun.total_ammo -= ammo;
		game->imgs.handgun.ammo += ammo;
		if (game->imgs.handgun.total_ammo < 0)
			game->imgs.handgun.total_ammo = 0;
	}
	*i = 0;
	game->reload = 0;
}

void	ft_print_handgun(t_game *game)
{
	t_vector2	pos;

	pos.x = 0;
	pos.y = 0;
	game->reload = 0;
	ft_print_sprite(game, &game->imgs.handgun.handgun, pos, -16777216);
}

void	ft_reload_handgun(t_game *game)
{
	t_vector2	pos;
	static int	i;

	pos.x = 0;
	pos.y = 0;
	if (!i)
		i = 0;
	if (game->imgs.handgun.ammo < 12)
	{
		if (game->imgs.handgun.total_ammo <= 0)
		{
			game->reload = 0;
			ft_print_sprite(game, &game->imgs.handgun.handgun, pos, -16777216);
			return ;
		}
		if (i == 0)
			system("afplay ./music/reload_handgun.mp3 &");
		ft_print_sprite(game, &game->imgs.handgun.reload[i], pos, -16777216);
		i++;
		if (i >= 26)
			ft_handgun_anim_end(game, &i);
	}
	else if (game->reload > 0)
		ft_print_handgun(game);
}

void	ft_reload(t_game *game)
{
	if (game->reload > 0 && game->gun == 1)
		ft_reload_handgun(game);
	else if (game->reload > 0 && game->gun == 3)
		ft_reload_sniper(game);
}
