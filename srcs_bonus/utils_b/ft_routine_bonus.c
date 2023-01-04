/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/04 13:31:45 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_all_routine(t_game *game, int *i)
{
	usleep(50000);
	ft_open_door(game);
	ft_raycast_rooftop(game);
	ft_raycast(game);
	ft_raycast_enemy(game, *i / 2);
	draw_cursor(game);
	ft_put_faces(game);
	ft_put_weapon_logo(game);
	ft_put_lifebar(game);
	ft_choose_ammo(game);
	ft_check_enemy_hit(game);
	if (game->reload == 0)
		ft_put_weapon(game);
	ft_reload(game);
	draw_minimap(game);
	ft_move_w(game);
	ft_move_s(game);
	ft_move_a(game);
	ft_move_d(game);
	if (hit_box(game))
		game->player->pos = game->player->last_pos;
	game->player->last_pos = game->player->pos;
}

void	ft_routine_game(t_game *game, int i)
{
	if (game->mus_ct == 24)
	{
		system("killall afplay");
		game->mus_ct = 3;
	}
	ft_music(game);
	ft_all_routine(game, &i);
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.img.img, 0, 0);
}

void	ft_routine_menu(t_game *game)
{
	if (game->mus_ct == 23)
	{
		system("killall afplay");
		game->mus_ct = 2;
	}
	ft_music(game);
	ft_put_menu(game);
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.img.img, 0, 0);
}

int	ft_routine(t_game *game)
{
	static int	i;
	static int	k;

	if (!i || i > 7)
		i = 0;
	if (!k || k > 2)
		k = 0;
	if (game->ct.start != 1)
	{
		ft_routine_game(game, i);
	}
	else if (game->ct.start == 1)
	{
		ft_routine_menu(game);
	}
	i++;
	k++;
	return (0);
}
