/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/08 20:11:53 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

int	ft_shoot(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1 && game->ct.start != 1)
	{
		game->fire = 1;
		game->imgs.handgun.i = 0;
	}
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	int	xx;
	int	i;

	//mlx_mouse_hide();
	i = 0;
	xx = x - game->last.x;
	if (xx < 0)
		xx *= -1;
	if (game->ct.start != 1)
	{
		while (i < xx)
		{
			move_mouse_x(game, x);
			if (i > 16)
				break ;
			i++;
		}
	}
	game->last.x = x;
	game->last.y = y;
	return (0);
}

void	ft_mouse_move_x_suite(t_game *game, int x,
	double olddirx, double oldplanex)
{
	if (x > game->last.x)
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

void	move_mouse_x(t_game *game, int x)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->player->dir.x;
	oldplanex = game->player->plane.x;
	if (x < game->last.x)
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
	ft_mouse_move_x_suite(game, x, olddirx, oldplanex);
}
