/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_door_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2022/11/02 02:42:12 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_raycast_suite_d2(t_game *game, t_ray *ray,
	double wall_x, int line_height)
{
	wall_x -= floorf(wall_x);
	ray->text.x = (int)(wall_x * ft_take_good_wall_d(game)->len_x);
	ray->t_step.y = SCREENW / TILESIZE / 5;
	ray->tpos.y = ray->pos.x * ray->t_step.y;
	ray->v.x = 0.0;
	ft_draw_line_d(game, line_height, ray);
}

void	ft_raycast_suite_d(t_game *game, t_ray *ray)
{
	double	wall_distance;
	double	wall_x;
	int		line_height;

	if (!(ray->side % 2))
		wall_distance = (ray->side_d.x - ray->delta_d.x);
	else
		wall_distance = (ray->side_d.y - ray->delta_d.y);
	if (game->door_open_ct <= 8)
		game->all_ray[(int)ray->pos.x] = wall_distance;
	line_height = (int)(SCREENH / wall_distance);
	ray->draw.x = -line_height / 2 + SCREENH / 2;
	if (ray->draw.x < 0)
		ray->draw.x = 0;
	ray->draw.y = line_height / 2 + SCREENH / 2;
	if (ray->draw.y >= SCREENH)
		ray->draw.y = SCREENH - 1;
	if (ray->side % 2 == 0)
		wall_x = game->player->pos.y + (wall_distance * ray->raydir.y);
	else
		wall_x = game->player->pos.x + (wall_distance * ray->raydir.x);
	ft_raycast_suite_d2(game, ray, wall_x, line_height);
}

void	ft_raycast_hit_d_suite(t_ray *ray)
{
	if (ray->side_d.x < ray->side_d.y)
	{
		ray->side_d.x += ray->delta_d.x;
		ray->map.x += ray->step.x;
		ray->side = 0;
		if (ray->step.x >= 0)
			ray->side = 2;
	}
	else
	{
		ray->side_d.y += ray->delta_d.y;
		ray->map.y += ray->step.y;
		ray->side = 1;
		if (ray->step.y >= 0)
			ray->side = 3;
	}
}

void	ft_raycast_hit_d(t_game *game, t_ray *ray)
{
	bool	hit;

	hit = false;
	while (!hit)
	{
		ft_raycast_hit_d_suite(ray);
		if (game->world_map[ray->map.x][ray->map.y] == '1'
				|| game->world_map[ray->map.x][ray->map.y] == '2')
			hit = true;
	}
}
