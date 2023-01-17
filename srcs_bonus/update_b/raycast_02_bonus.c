/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_02_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:20:34 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/14 04:05:25 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_raycast_suite(t_game *game, t_ray *ray)
{
	double	wall_x;
	int		line_height;

	if (!(ray->side % 2))
		game->wall_distance = (ray->side_d.x - ray->delta_d.x);
	else
		game->wall_distance = (ray->side_d.y - ray->delta_d.y);
	game->all_ray[(int)ray->pos.x] = game->wall_distance;
	line_height = (int)(SCREENH / game->wall_distance);
	ray->draw.x = -line_height / 2 + SCREENH / 2;
	if (ray->draw.x < 0)
		ray->draw.x = 0;
	ray->draw.y = line_height / 2 + SCREENH / 2;
	if (ray->draw.y >= SCREENH)
		ray->draw.y = SCREENH - 1;
	if (ray->side % 2 == 0)
		wall_x = game->player->pos.y + (game->wall_distance * ray->raydir.y);
	else
		wall_x = game->player->pos.x + (game->wall_distance * ray->raydir.x);
	wall_x -= floorf(wall_x);
	ray->text.x = (int)(wall_x * ft_take_good_wall(game, ray)->len_x);
	ray->t_step.y = SCREENW / TILESIZE / 5;
	ray->tpos.y = ray->pos.x * ray->t_step.y;
	ray->v.x = 0.0;
	ft_draw_line(game, line_height, ray);
}

t_xpm	*ft_take_good_wall(t_game *game, t_ray *ray)
{
	if (ray->map.x == 9 && ray->map.y == 11 && ray->side == 1)
	{
		if (game->ct.light00 >= 0 && game->ct.light00 <= 647)
			return (&game->imgs.light_00);
		if (game->ct.light00 >= 648 && game->ct.light00 <= 926)
			return (&game->imgs.light_01);
		if (game->ct.light00 >= 927 && game->ct.light00 <= 1000)
			return (&game->imgs.light_02);
	}
	else if (ray->map.x % 6 == 0 || ray->map.y % 9 == 0)
		return (&game->imgs.wall_extra);
	else if (ray->map.x == 3 && ray->map.y == 11 && ray->side == 0)
		return (&game->imgs.wall_blood_00);
	else if (ray->side == 0)
		return (&game->imgs.texture_n);
	else if (ray->side == 1)
		return (&game->imgs.texture_w);
	else if (ray->side == 2)
		return (&game->imgs.texture_s);
	return (&game->imgs.texture_e);
}

void	ft_draw_all_lines_suite(t_game *game, t_ray *ray)
{
	if (game->see_door == 1)
	{
		ft_ray_init(game, game->save_ray, game->save_ply);
		if (ray->raydir.y < 0)
		{
			ray->step.y = -1;
			ray->side_d.y = (game->save_ply->pos.y - game->save_ray->map.y)
				* game->save_ray->delta_d.y;
		}
		else
		{
			ray->step.y = 1;
			ray->side_d.y = (ray->map.y + 1.0 - game->save_ply->pos.y)
				* game->save_ray->delta_d.y;
		}
		ft_raycast_hit_d(game, ray);
		ft_raycast_suite_d(game, game->save_ray);
	}
}

static void	ft_draw_all_lines(t_game *game, int line_height,
	t_ray *ray, t_xpm *display)
{
	t_vector2	pos;

	while (ray->w.y < ray->w.x)
		ray->w.y++;
	ray->t_step.x = 1.0 * display->len_x / line_height;
	ray->tpos.x = (ray->draw.x - SCREENH / 2 + line_height / 2) * ray->t_step.x;
	while (ray->w.x < ray->draw.y)
	{
		ray->text.y = (int)ray->tpos.x & (display->len_y - 1);
		ray->tpos.x += ray->t_step.x;
		pos.x = (int)(ray->tpos.y + ray->v.x);
		pos.y = ray->w.x;
		if (display->tile[ray->text.y][ray->text.x] != (t_uint) - 16777216)
			draw_color(game, game->imgs.img.name, pos,
				(int)display->tile[ray->text.y][ray->text.x]);
		ray->w.x++;
	}
	ray->w.y = ray->w.x;
	ft_draw_all_lines_suite(game, ray);
	game->see_door = 0;
	game->see_enemy = 0;
}

void	ft_draw_line(t_game *game, int line_height, t_ray *ray)
{
	t_xpm	*display;

	display = ft_take_good_wall(game, ray);
	if (ray->side == 0 && ray->raydir.x > 0)
		ray->text.x = display->len_x - ray->text.x - 1;
	if (ray->side == 1 && ray->raydir.y < 0)
		ray->text.x = display->len_x - ray->text.x - 1;
	while (ray->tpos.y + ray->v.x < ray->tpos.y
		+ (ray->t_step.y * PRECISION) && ray->tpos.y < SCREENW)
	{
		ray->w.y = 0;
		ray->w.x = ray->draw.x;
		ft_draw_all_lines(game, line_height, ray, display);
		ray->v.x += PRECISION;
	}
}
