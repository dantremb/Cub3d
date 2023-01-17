/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_weapon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:18:49 by nadesjar          #+#    #+#             */
/*   Updated: 2022/11/01 20:12:52 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_put_weapon_logo(t_game *game)
{
	t_vector2	pos_logo;
	t_vector2	bullet;

	pos_logo.x = 0;
	pos_logo.y = 0;
	bullet.x = 110;
	bullet.y = 18;
	if (game->gun == 0)
		ft_print_sprite(game, &game->imgs.knife.logo, pos_logo, -16777216);
	else if (game->gun == 1)
	{
		ft_print_sprite(game, &game->imgs.handgun.logo, pos_logo, -16777216);
		ft_print_sprite(game, &game->imgs.handgun.bullet, bullet, -16777216);
	}
	else if (game->gun == 2)
	{
		ft_print_sprite(game, &game->imgs.shotgun.logo, pos_logo, -16777216);
		ft_print_sprite(game, &game->imgs.shotgun.bullet, bullet, -16777216);
	}
	else if (game->gun == 3)
	{
		ft_print_sprite(game, &game->imgs.sniper.logo, pos_logo, -16777216);
		ft_print_sprite(game, &game->imgs.sniper.bullet, bullet, -16777216);
	}
}

void	ft_fire(t_game *game, t_vector2 pos)
{
	static int	i;
	static int	k;

	if (!i)
		i = 0;
	if (!k)
		k = 0;
	if (game->gun == 0)
		ft_put_knife(game, pos, &i);
	else if (game->gun == 1)
		ft_put_handgun(game, pos, &i, &k);
	else if (game->gun == 2)
		ft_put_shotgun(game, pos, &i);
	else if (game->gun == 3)
		ft_put_sniper(game, pos, &i);
}

void	ft_move_weapon(t_game *game)
{
	static int	ct;
	static int	wait;

	if (!ct)
		ct = 0;
	if (!wait || wait > 2)
		wait = 0;
	if (wait == 2)
	{
		if (game->move_gun <= 4 && ct == 0)
		{
			if (game->move_gun == 4)
				ct = 1;
			game->move_gun++;
		}
		else if (game->move_gun > 0)
		{
			if (game->move_gun == 1)
				ct = 0;
			game->move_gun--;
		}
	}
	wait++;
}

void	ft_put_weapon(t_game *game)
{
	t_vector2	pos;

	ft_move_weapon(game);
	pos.x = 0;
	pos.y = game->move_gun + game->gun_up;
	if (game->gun_up > 0)
		game->gun_up -= 80;
	ft_fire(game, pos);
}
