/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2022/11/01 20:12:31 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	draw_player_minimap(t_game *game)
{
	t_vector2	pos;
	int			i;
	int			k;

	i = -1;
	while (++i < 6)
	{
		k = -1;
		while (++k < 6)
		{
			pos.x = k + game->w - 80;
			pos.y = i + 77;
			draw_color(game, game->imgs.img.name, pos,
				create_trgb(0, 24, 0, 255));
		}
	}
}

void	draw_minimap_suite(t_game *game, int a, int b)
{
	t_vector2	pos;
	int			i;
	int			k;

	i = -1;
	if (game->world_map[a][b] != '0')
	{
		while (++i < 6)
		{
			k = -1;
			while (++k < 6)
			{
				pos.x = (b * 6) + k + game->w - (game->player->pos.y * 6) - 77;
				pos.y = (a * 6) + i - (game->player->pos.x * 6) + 80;
				if (pos.x < 1500 && pos.x > 1352 && pos.y >= 0 && pos.y <= 146)
					draw_color(game, game->imgs.img.name, pos,
						create_trgb(0, 60, 0, 60));
			}
		}
	}
}

void	ft_print_bg_map(t_game *game)
{
	t_vector2	pos;
	int			i;
	int			k;

	i = -1;
	while (++i < 146)
	{
		k = 1352;
		while (++k < SCREENW)
		{
			pos.x = k;
			pos.y = i;
			draw_color(game, game->imgs.img.name, pos,
				create_trgb(0, 10, 10, 10));
		}
	}
}

void	draw_minimap(t_game *game)
{
	int	a;
	int	b;

	ft_print_bg_map(game);
	a = -1;
	while (game->world_map[++a])
	{
		b = -1;
		while (game->world_map[a][++b])
			draw_minimap_suite(game, a, b);
	}
	draw_player_minimap(game);
}

void	draw_cursor(t_game *game)
{
	t_vector2	pos;
	int			x;
	int			y;
	int			i;

	x = game->w / 2;
	y = game->h / 2;
	i = -1;
	while (++i < 20)
	{
		pos.x = x + i - 20;
		pos.y = y + 9;
		draw_color(game, game->imgs.img.name, pos,
			create_trgb(0, 199, 21, 113));
		x++;
	}
	i = -1;
	while (++i < 20)
	{
		pos.x = x - 20;
		pos.y = y - 9 + i;
		draw_color(game, game->imgs.img.name, pos,
			create_trgb(0, 199, 21, 113));
		y++;
	}
}
