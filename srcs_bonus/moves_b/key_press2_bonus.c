/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press2_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:41:31 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/19 13:41:35 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"
#include "../../includes_bonus/control_bonus.h"

void	ft_move_w(t_game *game)
{
	t_vector2	pos;

	if (game->move_w == 1)
	{
		pos.x = (int)(game->player->pos.x + game->player->dir.x
				* game->move_speed);
		pos.y = (int)(game->player->pos.y);
		if (game->world_map[pos.x][pos.y] != '1'
			&& game->world_map[pos.x][pos.y] != '2')
			game->player->pos.x += game->player->dir.x * game->move_speed;
		if (game->world_map[pos.x][pos.y] == '2')
			if (game->door_open_ct >= 13)
				game->player->pos.x += game->player->dir.x * game->move_speed;
		pos.x = (int)(game->player->pos.x);
		pos.y = (int)(game->player->pos.y
				+ game->player->dir.y * game->move_speed);
		if (game->world_map[pos.x][pos.y] !=
			'1' && game->world_map[pos.x][pos.y] != '2')
			game->player->pos.y += game->player->dir.y * game->move_speed;
		if (game->world_map[pos.x][pos.y] == '2')
		{
			if (game->door_open_ct >= 13)
				game->player->pos.y += game->player->dir.y * game->move_speed;
		}
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
		if (game->world_map[pos.x][pos.y]
			!= '1' && game->world_map[pos.x][pos.y] != '2')
			game->player->pos.x -= game->player->dir.x * game->move_speed;
		if (game->world_map[pos.x][pos.y] == '2')
			if (game->door_open_ct >= 13)
				game->player->pos.x -= game->player->dir.x * game->move_speed;
		pos.x = (int)(game->player->pos.x);
		pos.y = (int)(game->player->pos.y
				- game->player->dir.y * game->move_speed);
		if (game->world_map[pos.x][pos.y] != '1'
			&& game->world_map[pos.x][pos.y] != '2')
			game->player->pos.y -= game->player->dir.y * game->move_speed;
		if (game->world_map[pos.x][pos.y] == '2')
		{
			if (game->door_open_ct >= 13)
				game->player->pos.y -= game->player->dir.y * game->move_speed;
		}
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
		if (game->world_map[pos.x][pos.y] != '1'
			&& game->world_map[pos.x][pos.y] != '2')
			game->player->pos.x -= game->player->plane.x * game->move_speed;
		if (game->world_map[pos.x][pos.y] == '2')
			if (game->door_open_ct >= 13)
				game->player->pos.x -= game->player->plane.x * game->move_speed;
		pos.x = (int)(game->player->pos.x);
		pos.y = (int)(game->player->pos.y - game->player->plane.y
				* game->move_speed);
		if (game->world_map[pos.x][pos.y] != '1'
			&& game->world_map[pos.x][pos.y] != '2')
			game->player->pos.y -= game->player->plane.y * game->move_speed;
		if (game->world_map[pos.x][pos.y] == '2')
		{
			if (game->door_open_ct >= 13)
				game->player->pos.y -= game->player->plane.y * game->move_speed;
		}
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
		if (game->world_map[pos.x][pos.y] != '1'
			&& game->world_map[pos.x][pos.y] != '2')
			game->player->pos.x += game->player->plane.x * game->move_speed;
		if (game->world_map[pos.x][pos.y] == '2')
			if (game->door_open_ct >= 13)
				game->player->pos.x += game->player->plane.x * game->move_speed;
		pos.x = (int)(game->player->pos.x);
		pos.y = (int)(game->player->pos.y + game->player->plane.y
				* game->move_speed);
		if (game->world_map[pos.x][pos.y] != '1'
			&& game->world_map[pos.x][pos.y] != '2')
			game->player->pos.y += game->player->plane.y * game->move_speed;
		if (game->world_map[pos.x][pos.y] == '2')
		{
			if (game->door_open_ct >= 13)
				game->player->pos.y += game->player->plane.y * game->move_speed;
		}
	}
}

int	key_release(int key, t_game *game)
{
	if (key == KEY_W)
		game->move_w = 0;
	else if (key == KEY_A)
		game->move_a = 0;
	else if (key == KEY_S)
		game->move_s = 0;
	else if (key == KEY_D)
		game->move_d = 0;
	return (0);
}
