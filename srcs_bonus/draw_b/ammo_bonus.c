/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:49:30 by nadesjar          #+#    #+#             */
/*   Updated: 2022/11/01 20:12:14 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_put_ammo(t_game *game, int pos, int img_nbr)
{
	t_vector2	pos1;

	pos1.y = 35;
	if (pos == 1)
		pos1.x = 150;
	else if (pos == 2)
		pos1.x = 185;
	else if (pos == 3)
		pos1.x = 220;
	else if (pos == 4)
		pos1.x = 250;
	else if (pos == 5)
		pos1.x = 285;
	ft_print_sprite(game, &game->imgs.nbrs.nbrs[img_nbr], pos1, -16777216);
}

void	ft_choose_ammo(t_game *game)
{
	int	total_ammo;
	int	ammo;

	if (game->gun == 1)
	{
		total_ammo = game->imgs.handgun.total_ammo;
		ammo = game->imgs.handgun.ammo;
	}
	else if (game->gun == 2)
	{
		total_ammo = game->imgs.shotgun.total_ammo;
		ammo = game->imgs.shotgun.ammo;
	}
	else if (game->gun == 3)
	{
		total_ammo = game->imgs.sniper.total_ammo;
		ammo = game->imgs.sniper.ammo;
	}
	else
		return ;
	ft_put_ammo(game, 1, ammo / 10);
	ft_put_ammo(game, 2, ammo % 10);
	ft_put_ammo(game, 3, 10);
	ft_put_ammo(game, 4, total_ammo / 10);
	ft_put_ammo(game, 5, total_ammo % 10);
}
