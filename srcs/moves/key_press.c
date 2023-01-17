/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/13 11:18:32 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/control.h"

int	key_press(int key, t_game *game)
{
	if (key == KEY_W)
		game->move_w = 1;
	else if (key == KEY_S)
		game->move_s = 1;
	else if (key == KEY_A)
		game->move_a = 1;
	else if (key == KEY_D)
		game->move_d = 1;
	else if (key == KEY_RIGHT)
		game->move_ri = 1;
	else if (key == KEY_LEFT)
		game->move_lft = 1;
	else if (key == KEY_ESC)
		x_quit(game);
	return (0);
}

void	ft_move_lft(t_game *game)
{
	double		olddirx;
	double		oldplanex;

	olddirx = game->player->dir.x;
	oldplanex = game->player->plane.x;
	if (game->move_lft == 1)
	{
		game->player->dir.x = game->player->dir.x * cos(game->rot_speed)
			- game->player->dir.y * sin(game->rot_speed);
		game->player->dir.y = olddirx * sin(game->rot_speed)
			+ game->player->dir.y * cos(game->rot_speed);
		game->player->plane.x = game->player->plane.x * cos(game->rot_speed)
			- game->player->plane.y * sin(game->rot_speed);
		game->player->plane.y = oldplanex * sin(game->rot_speed)
			+ game->player->plane.y * cos(game->rot_speed);
	}
}

void	ft_move_ri(t_game *game)
{
	double		olddirx;
	double		oldplanex;

	olddirx = game->player->dir.x;
	oldplanex = game->player->plane.x;
	if (game->move_ri == 1)
	{
		game->player->dir.x = game->player->dir.x * cos(-game->rot_speed)
			- game->player->dir.y * sin(-game->rot_speed);
		game->player->dir.y = olddirx * sin(-game->rot_speed)
			+ game->player->dir.y * cos(-game->rot_speed);
		game->player->plane.x = game->player->plane.x * cos(-game->rot_speed)
			- game->player->plane.y * sin(-game->rot_speed);
		game->player->plane.y = oldplanex * sin(-game->rot_speed)
			+ game->player->plane.y * cos(-game->rot_speed);
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
	else if (key == KEY_RIGHT)
		game->move_ri = 0;
	else if (key == KEY_LEFT)
		game->move_lft = 0;
	return (0);
}
