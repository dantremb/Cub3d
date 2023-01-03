/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shotgun_knife_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:46:07 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/13 11:21:01 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_put_knife(t_game *game, t_vector2 pos, int *i)
{
	if (game->fire > 0)
	{
		ft_print_sprite(game, &game->imgs.knife.knife[*i + 1], pos, -16777216);
		if (*i == 0)
			system("afplay ./music/knife.mp3 &");
		++*i;
		if (*i >= 10)
		{
			*i = 0;
			game->fire = 0;
			return ;
		}
	}
	else if (game->fire == 0)
		ft_print_sprite(game, &game->imgs.knife.knife[0], pos, -16777216);
}

void	ft_shotgun_fire(t_game *game, int *i)
{
	if (*i == 1)
		system("afplay ./music/shotgun.mp3 &");
	if (*i >= 23)
	{
		game->imgs.shotgun.ammo = 0;
		if (game->imgs.shotgun.total_ammo <= 0)
		{
			game->imgs.shotgun.total_ammo = 0;
		}
		else
		{
			game->imgs.shotgun.ammo = 2;
			game->imgs.shotgun.total_ammo -= 2;
		}
		*i = 0;
		game->fire = 0;
	}
}

void	ft_put_shotgun(t_game *game, t_vector2 pos, int *i)
{
	if (game->fire == 0)
		ft_print_sprite(game, &game->imgs.shotgun.fire[0], pos, -16777216);
	else if (game->fire > 0)
	{
		if (game->imgs.shotgun.ammo <= 0
			&& game->imgs.shotgun.total_ammo <= 0 && *i == 0)
		{
			pos.y += 4;
			*i = 0;
			game->fire = 0;
			ft_print_sprite(game, &game->imgs.shotgun.fire[0], pos, -16777216);
			return ;
		}
		else if (game->imgs.shotgun.ammo > 0 && *i == 1)
			game->imgs.shotgun.ammo -= 2;
		++*i;
		ft_shotgun_fire(game, i);
		ft_print_sprite(game, &game->imgs.shotgun.fire[*i + 1], pos, -16777216);
	}
}
