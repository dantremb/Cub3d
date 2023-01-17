/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:39:58 by nadesjar          #+#    #+#             */
/*   Updated: 2022/11/02 00:51:56 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_put_lifebar_1(t_game *game, t_vector2 *pos, int *i, int *k)
{
	while (*k < game->player->life + 1 && *i < 15)
	{
		pos->x = 10 + *k;
		pos->y = 102 + *i;
		draw_color(game, game->imgs.img.name, *pos,
			ft_return_rgb("236423") + *k / 2);
		*k += 1;
	}
}

void	ft_put_lifebar_2(t_game *game, t_vector2 *pos, int *i, int *k)
{
	*k = game->player->life;
	while (*k >= 0)
	{
		pos->x = 10 + *k;
		pos->y = 102 + *i;
		draw_color(game, game->imgs.img.name, *pos,
			ft_return_rgb("236423") + *k / 2);
		*k -= 1;
	}
}

void	ft_put_lifebar_3(t_game *game, t_vector2 pos)
{
	pos.x = 10 + game->player->k + game->player->x;
	pos.y = 102 + game->player->i;
	draw_color(game, game->imgs.img.name, pos,
		ft_return_rgb("236423") + game->player->k / 2);
	game->player->k--;
}

void	ft_put_lifebar(t_game *game)
{
	t_vector2	pos;

	game->player->x = 20;
	game->player->i = -1;
	while (++game->player->i < 25)
	{
		game->player->k = 0;
		ft_put_lifebar_1(game, &pos, &game->player->i, &game->player->k);
		game->player->k = 80;
		if (game->player->life < 80 + game->player->x)
			ft_put_lifebar_2(game, &pos, &game->player->i, &game->player->k);
		else
		{
			while (game->player->k + game->player->x >= 0
				&& game->player->i >= 15)
			{
				ft_put_lifebar_3(game, pos);
			}
		}
		if (game->player->i >= 15)
			game->player->x -= 2;
	}
}
