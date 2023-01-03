/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:41:31 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/29 23:39:17 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/control.h"

void	ft_move_w(t_game *game)
{
	t_vector2	pos;

	if (game->move_w == 1)
	{
		pos.x = (int)(game->player->pos.x + game->player->dir.x
				* game->move_speed);
		pos.y = (int)(game->player->pos.y);
		if (game->world_map[pos.x][pos.y] != '1')
			game->player->pos.x += game->player->dir.x * game->move_speed;
		pos.x = (int)(game->player->pos.x);
		pos.y = (int)(game->player->pos.y
				+ game->player->dir.y * game->move_speed);
		if (game->world_map[pos.x][pos.y] != '1')
			game->player->pos.y += game->player->dir.y * game->move_speed;
	}
}

void	ft_move_s(t_game *game)
{
	t_vector2	pos;

	if (game->move_s == 1)
	{
		pos.x = (int)(game->player->pos.x - game->player->dir.x
				* game->move_speed);
		pos.y = (int)(game->player->pos.y);
		if (game->world_map[pos.x][pos.y] != '1')
			game->player->pos.x -= game->player->dir.x * game->move_speed;
		pos.x = (int)(game->player->pos.x);
		pos.y = (int)(game->player->pos.y
				- game->player->dir.y * game->move_speed);
		if (game->world_map[pos.x][pos.y] != '1')
			game->player->pos.y -= game->player->dir.y * game->move_speed;
	}
}

void	ft_move_a(t_game *game)
{
	t_vector2	pos;

	if (game->move_a == 1)
	{
		pos.x = (int)(game->player->pos.x - game->player->plane.x
				* game->move_speed);
		pos.y = (int)(game->player->pos.y);
		if (game->world_map[pos.x][pos.y] != '1')
			game->player->pos.x -= game->player->plane.x * game->move_speed;
		pos.x = (int)(game->player->pos.x);
		pos.y = (int)(game->player->pos.y - game->player->plane.y
				* game->move_speed);
		if (game->world_map[pos.x][pos.y] != '1')
			game->player->pos.y -= game->player->plane.y * game->move_speed;
	}
}

void	ft_move_d(t_game *game)
{
	t_vector2	pos;

	if (game->move_d == 1)
	{
		pos.x = (int)(game->player->pos.x + game->player->plane.x
				* game->move_speed);
		pos.y = (int)(game->player->pos.y);
		if (game->world_map[pos.x][pos.y] != '1')
			game->player->pos.x += game->player->plane.x * game->move_speed;
		pos.x = (int)(game->player->pos.x);
		pos.y = (int)(game->player->pos.y + game->player->plane.y
				* game->move_speed);
		if (game->world_map[pos.x][pos.y] != '1')
			game->player->pos.y += game->player->plane.y * game->move_speed;
	}
}
