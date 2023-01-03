/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handgun_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:39:27 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/14 04:03:29 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_handgun_idle_and_rotate(t_game *game, t_vector2 pos, int *k)
{
	if (game->rotate_gun == 1)
	{
		ft_print_sprite(game, &game->imgs.handgun.rotate[*k], pos, -16777216);
		++*k;
		if (*k >= 9)
		{
			*k = 0;
			game->rotate_gun = 0;
			return ;
		}
	}
	else
		ft_print_sprite(game, &game->imgs.handgun.handgun, pos, -16777216);
}

void	ft_handgun_fire(t_game *game, t_vector2 pos, int *i)
{
	if (*i == 0)
		system("afplay ./music/handgun.mp3 &");
	ft_print_sprite(game, &game->imgs.handgun.fire[*i], pos, -16777216);
	++*i;
	if (*i >= 6)
	{
		if (game->imgs.handgun.ammo == 0)
		{
			pos.y += 4;
			ft_print_sprite(game, &game->imgs.handgun.handgun, pos, -16777216);
		}
		else if (*i == 6 && game->imgs.handgun.ammo > 0)
			game->imgs.handgun.ammo--;
		*i = 0;
		game->fire = 0;
		return ;
	}
}

void	ft_put_handgun(t_game *game, t_vector2 pos, int *i, int *k)
{
	if (game->fire == 0)
		ft_handgun_idle_and_rotate(game, pos, k);
	else if (game->fire > 0 && game->imgs.handgun.ammo > 0)
		ft_handgun_fire(game, pos, i);
	else
	{
		pos.y += 4;
		game->fire = 0;
		ft_print_sprite(game, &game->imgs.handgun.handgun, pos, -16777216);
	}
}
