/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_flortop_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:36:35 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/12 16:29:12 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_raycast_rooftop_loop(t_game *game, t_vector2f *floor_step,
	t_vector2f *floor, t_vector2 *xy)
{
	t_vector2	pos;
	int			cell_x;
	int			cell_y;
	int			tx;
	int			ty;

	cell_x = (int)(floor->x);
	cell_y = (int)(floor->y);
	tx = (int)(TILESIZE * (floor->x - cell_x)) & (TILESIZE - 1);
	ty = (int)(TILESIZE * (floor->y - cell_y)) & (TILESIZE - 1);
	floor->x += floor_step->x;
	floor->y += floor_step->y;
	pos.x = xy->x;
	pos.y = xy->y;
	if (game->imgs.floor.tile[ty][tx] != (t_uint)-16777216)
		draw_color(game, game->imgs.img.name, pos,
			(int)game->imgs.floor.tile[ty][tx]);
	pos.x = xy->x;
	pos.y = SCREENH - xy->y - 1;
	if (game->imgs.roof.tile[ty][tx] != (t_uint)-16777216)
		draw_color(game, game->imgs.img.name, pos,
			(int)game->imgs.roof.tile[ty][tx]);
	xy->x++;
}

void	ft_raycast_rooftop_suite(t_game *game,
	t_vector2f *ray_dir0, t_vector2f *ray_dir1)
{
	ray_dir0->x = game->player->dir.x - game->player->plane.x;
	ray_dir0->y = game->player->dir.y - game->player->plane.y;
	ray_dir1->x = game->player->dir.x + game->player->plane.x;
	ray_dir1->y = game->player->dir.y + game->player->plane.y;
}

void	ft_raycast_rooftop(t_game *game)
{
	float		row_distance;
	int			p;

	game->topdown.xy.y = SCREENH / 2;
	while (game->topdown.xy.y < SCREENH)
	{
		ft_raycast_rooftop_suite(game, &game->topdown.ray_dir0,
			&game->topdown.ray_dir1);
		p = game->topdown.xy.y - SCREENH / 2;
		game->topdown.pos_z = 0.5 * SCREENH;
		row_distance = game->topdown.pos_z / p;
		game->topdown.floor_step.x = row_distance
			* (game->topdown.ray_dir1.x - game->topdown.ray_dir0.x) / SCREENW;
		game->topdown.floor_step.y = row_distance
			* (game->topdown.ray_dir1.y - game->topdown.ray_dir0.y) / SCREENW;
		game->topdown.floor.x = game->player->pos.x
			+ row_distance * game->topdown.ray_dir0.x;
		game->topdown.floor.y = game->player->pos.y
			+ row_distance * game->topdown.ray_dir0.y;
		game->topdown.xy.x = 0;
		while (game->topdown.xy.x < SCREENW)
			ft_raycast_rooftop_loop(game, &game->topdown.floor_step,
				&game->topdown.floor, &game->topdown.xy);
		game->topdown.xy.y++;
	}
}
