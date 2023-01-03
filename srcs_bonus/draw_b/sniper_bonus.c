/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sniper_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:43:31 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/13 11:21:20 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_sniper_shoot_in_zoom(t_game *game, t_vector2 pos, int *i)
{
	if (*i == 7)
		system("afplay ./music/sniper.mp3 &");
	if (game->imgs.sniper.ammo > 0 && *i == 6)
		game->imgs.sniper.ammo--;
	else if (game->imgs.sniper.ammo <= 0 && *i == 6)
	{
		pos.y += 4;
		ft_print_sprite(game, &game->imgs.sniper.shoot_zoom[*i],
			pos, -16777216);
		game->fire = 0;
		return ;
	}
	ft_print_sprite(game, &game->imgs.sniper.shoot_zoom[*i], pos, -16777216);
	++*i;
	if (*i >= 18)
	{
		*i = 6;
		game->fire = 0;
		return ;
	}
}

void	ft_sniper_shoot(t_game *game, t_vector2 pos, int *i)
{
	if (*i == 0 && game->imgs.sniper.ammo > 0)
	{
		if (game->imgs.sniper.ammo > 0)
			game->imgs.sniper.ammo--;
	}
	else if (*i == 0)
	{
		pos.y += 4;
		ft_print_sprite(game, &game->imgs.sniper.sniper[0], pos, -16777216);
		game->fire = 0;
		return ;
	}
	if (*i == 0)
		system("afplay ./music/sniper.mp3 &");
	ft_print_sprite(game, &game->imgs.sniper.sniper[*i + 1], pos, -16777216);
	++*i;
	if (*i >= 14)
	{
		*i = 0;
		game->fire = 0;
		return ;
	}
}

void	ft_put_sniper(t_game *game, t_vector2 pos, int *i)
{
	if (game->fire == 0 && game->zoom == 0 && *i == 0)
		ft_print_sprite(game, &game->imgs.sniper.sniper[0], pos, -16777216);
	else if (game->fire == 0 && game->zoom == 1 && *i < 6)
	{
		ft_print_sprite(game, &game->imgs.sniper.zoom[*i], pos, -16777216);
		*i += 1;
	}
	else if (game->fire == 0 && game->zoom == 1 && *i == 6)
		ft_print_sprite(game, &game->imgs.sniper.zoom[*i], pos, -16777216);
	else if (game->fire == 1 && game->zoom == 1 && *i >= 6)
		ft_sniper_shoot_in_zoom(game, pos, i);
	else if (game->fire > 0 && game->zoom == 0)
		ft_sniper_shoot(game, pos, i);
	else if (game->zoom == 0 && *i > 0)
	{
		*i -= 1;
		ft_print_sprite(game, &game->imgs.sniper.zoom[*i], pos, -16777216);
	}
}

void	ft_reload_sniper(t_game *game)
{
	static int	i;
	static int	k;

	if (!i)
		i = 0;
	if (!k)
		k = 0;
	ft_zoom_out_sniper1(game, &k);
	if (game->zoom == 2)
		ft_zoom_out_sniper2(game, &k);
	else if (game->zoom == 0 || game->zoom == 3)
	{
		ft_reload_sniper_suite(game, &i, &k);
	}
	else if (game->zoom == 4)
	{
		ft_sniper_zoom_out(game, &i, &k);
	}
}
