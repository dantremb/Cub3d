/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/19 17:48:42 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"
#include "../../includes_bonus/control_bonus.h"

void	ft_change_gun(t_game *game, int key)
{
	game->gun_up = 300;
	if (key == KEY_0)
	{
		system("afplay ./music/pull_out_knife.mp3 &");
		game->gun = 0;
	}
	else if (key == KEY_1)
	{
		system("afplay ./music/pull_out_knife.mp3 &");
		game->rotate_gun = 1;
		game->gun = 1;
	}
	else if (key == KEY_2)
	{
		system("afplay ./music/gun_change.mp3 &");
		game->gun = 2;
	}
	else if (key == KEY_3)
	{
		system("afplay ./music/gun_change.mp3 &");
		game->gun = 3;
	}
}

void	ft_key_press_suite(t_game *game, int key)
{
	if (key == KEY_TAB)
	{
		if (game->reload == 0 && game->gun == 3
			&& game->fire == 0 && game->zoom == 1)
			game->zoom = 0;
		else if (game->reload == 0 && game->gun == 3
			&& game->fire == 0 && game->zoom == 0)
			game->zoom = 1;
	}
	else if (key == KEY_0 || key == KEY_1 || key == KEY_2 || key == KEY_3)
		ft_change_gun(game, key);
	else if (key == KEY_R)
	{
		if (game->reload == 0 && (game->gun == 1 || game->gun == 3))
		{
			if (game->gun == 1)
				system("afplay ./music/reload_handgun.mp3 &");
			game->reload = 1;
		}
	}
}

bool	hit_box(t_game *game)
{
	bool	collision;

	collision = false;
	if ((game->player->pos.y < (game->enemy0.pos.x + 0.30f)
			&& (game->player->pos.y + 0.30f) > game->enemy0.pos.x)
		&& (game->player->pos.x < (game->enemy0.pos.y + 0.30f)
			&& (game->player->pos.x + 0.30f) > game->enemy0.pos.y))
		collision = true;
	return (collision);
}

int	key_press(int key, t_game *game)
{
	static int	i;

	if (!i)
		i = 0;
	if (game->ct.start != 1)
	{
		if (key == KEY_W)
			game->move_w = 1;
		else if (key == KEY_S)
			game->move_s = 1;
		else if (key == KEY_A)
			game->move_a = 1;
		else if (key == KEY_D)
			game->move_d = 1;
		ft_key_press_suite(game, key);
	}
	ft_ctrl_menu(key, game);
	return (0);
}
