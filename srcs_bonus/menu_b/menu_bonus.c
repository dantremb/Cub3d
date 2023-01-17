/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:40:58 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/07 02:01:07 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"
#include "../../includes_bonus/control_bonus.h"

void	ft_menu_up(t_game *game, int ct)
{
	t_vector2	pos;

	pos.x = 0;
	pos.y = 0;
	ft_print_sprite(game, &game->imgs.menu, pos, -16777216);
	pos.x = 500;
	pos.y = 706;
	if (ct >= 0 && ct <= 25)
		ft_print_sprite(game, &game->imgs.skulls.skulls[0], pos, -16777216);
	else if (ct >= 26 && ct <= 50)
		ft_print_sprite(game, &game->imgs.skulls.skulls[1], pos, -16777216);
	else if (ct >= 51 && ct <= 75)
		ft_print_sprite(game, &game->imgs.skulls.skulls[2], pos, -16777216);
	else if (ct >= 76 && ct <= 100)
		ft_print_sprite(game, &game->imgs.skulls.skulls[3], pos, -16777216);
}

void	ft_menu_down(t_game *game, int ct)
{
	t_vector2	pos;

	pos.x = 0;
	pos.y = 0;
	ft_print_sprite(game, &game->imgs.menu, pos, 0);
	pos.x = 500;
	pos.y = 768;
	if (ct >= 0 && ct <= 25)
		ft_print_sprite(game, &game->imgs.skulls.skulls[0], pos, -16777216);
	else if (ct >= 26 && ct <= 50)
		ft_print_sprite(game, &game->imgs.skulls.skulls[1], pos, -16777216);
	else if (ct >= 51 && ct <= 75)
		ft_print_sprite(game, &game->imgs.skulls.skulls[2], pos, -16777216);
	else if (ct >= 76 && ct <= 100)
		ft_print_sprite(game, &game->imgs.skulls.skulls[3], pos, -16777216);
}

void	ft_put_menu(t_game *game)
{
	static int	ct;

	if (!ct || ct >= 100 || ct < 0)
		ct = 0;
	if (game->ct.choose == 1)
		ft_menu_up(game, ct);
	else if (game->ct.choose == -1)
		ft_menu_down(game, ct);
	ct++;
}

void	ft_ctrl_menu(int key, t_game *game)
{
	if (game->ct.start == 1)
	{
		if (key == KEY_W || key == KEY_S)
			game->ct.choose *= -1;
	}
	if (key == KEY_ENTER)
	{
		if (game->ct.choose == 1)
		{
			game->mus_ct = 24;
			game->ct.start = 0;
		}
		else
			x_quit(game);
	}
	if (key == KEY_ESC)
	{
		if (game->ct.start == 1)
			x_quit(game);
		else
			game->ct.start = 1;
		system("killall afplay");
		game->mus_ct = 2;
	}
}
