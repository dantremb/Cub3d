/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_enemy_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:44:58 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/13 11:09:39 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"
#include <unistd.h>

t_xpm	ft_return_good_enemy(t_game *game, int ct)
{
	if (ct == 0)
		return (game->enemy0.face[0]);
	else if (ct == 1)
		return (game->enemy0.face[1]);
	else if (ct == 2)
		return (game->enemy0.face[2]);
	else if (ct == 3)
		return (game->enemy0.face[3]);
	return (game->enemy0.face[0]);
}

void	ft_raycast_enemy2(t_game *game)
{
	double	matrix;

	matrix = 1.0 / (game->player->plane.y * game->player->dir.x
			- game->player->dir.y * game->player->plane.x);
	game->ray_enemy.sprite.x = game->enemy0.pos.x - game->player->pos.y;
	game->ray_enemy.sprite.y = game->enemy0.pos.y - game->player->pos.x;
	game->ray_enemy.transform.x = matrix * (game->player->dir.x
			* game->ray_enemy.sprite.x - game->player->dir.y
			* game->ray_enemy.sprite.y);
	game->ray_enemy.transform.y = matrix * (-game->player->plane.x
			* game->ray_enemy.sprite.x + game->player->plane.y
			* game->ray_enemy.sprite.y);
	game->ray_enemy.sprite_screen_x = (int)((game->w / 2)
			* (1 + game->ray_enemy.transform.x / game->ray_enemy.transform.y));
	game->ray_enemy.v_move_screen = (int)(VMOVE / game->ray_enemy.transform.y);
	game->ray_enemy.sprite_height = abs((int)(game->h
				/ (game->ray_enemy.transform.y))) / VDIV;
}

void	ft_raycast_enemy3(t_game *game)
{
	game->ray_enemy.draw_start.y = -game->ray_enemy.sprite_height / 2
		+ game->h / 2 + game->ray_enemy.v_move_screen;
	if (game->ray_enemy.draw_start.y < 0)
		game->ray_enemy.draw_start.y = 0;
	game->ray_enemy.draw_end.y = game->ray_enemy.sprite_height / 2
		+ game->h / 2 + game->ray_enemy.v_move_screen;
	if (game->ray_enemy.draw_end.y >= game->h)
		game->ray_enemy.draw_end.y = game->h - 1;
	game->ray_enemy.sprite_width = abs((int)(game->h
				/ (game->ray_enemy.transform.y))) / UDIV;
	game->ray_enemy.draw_start.x = -game->ray_enemy.sprite_width
		/ 2 + game->ray_enemy.sprite_screen_x;
	if (game->ray_enemy.draw_start.x < 0)
		game->ray_enemy.draw_start.x = 0;
	game->ray_enemy.draw_end.x = game->ray_enemy.sprite_width
		/ 2 + game->ray_enemy.sprite_screen_x;
	if (game->ray_enemy.draw_end.x > game->w)
		game->ray_enemy.draw_end.x = game->w;
}

void	ft_raycast_enemy_loop(t_game *game, t_xpm *img, int stripe)
{
	int		y;
	int		d;

	y = game->ray_enemy.draw_start.y;
	while (y < game->ray_enemy.draw_end.y)
	{
		d = (y - game->ray_enemy.v_move_screen) * 256 - game->h * 128
			+ game->ray_enemy.sprite_height * 128;
			game->ray_enemy.tex.y = ((d * TILESIZE)
				/ game->ray_enemy.sprite_height) / 256;
		game->ray_enemy.pos.x = stripe;
		game->ray_enemy.pos.y = y;
		if (game->ray_enemy.tex.y >= img->len_y
			|| game->ray_enemy.tex.x >= img->len_x)
			break ;
		if (img->tile[game->ray_enemy.tex.y][game->ray_enemy.tex.x]
			!= (t_uint) - 16777216)
			draw_color(game, game->imgs.img.name, game->ray_enemy.pos,
				(int)img->tile[game->ray_enemy.tex.y][game->ray_enemy.tex.x]);
		y++;
	}
}

void	ft_raycast_enemy(t_game *game, int ct)
{
	t_xpm		img;
	int			stripe;

	img = ft_return_good_enemy(game, ct);
	ft_raycast_enemy2(game);
	ft_raycast_enemy3(game);
	stripe = game->ray_enemy.draw_start.x;
	while (stripe < game->ray_enemy.draw_end.x)
	{
		game->ray_enemy.tex.x = (int)(256 * (stripe - \
		(-game->ray_enemy.sprite_width / 2 + game->ray_enemy.sprite_screen_x))
				* TILESIZE / game->ray_enemy.sprite_width) / 256;
		if (game->ray_enemy.transform.y > 0 && game->ray_enemy.transform.y
			< game->all_ray[stripe])
		{
			ft_raycast_enemy_loop(game, &img, stripe);
		}
		stripe++;
	}
}
