/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:20:34 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/14 04:09:38 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_raycast_suite(t_game *game, t_ray *ray)
{
	double	wall_distance;
	double	wall_x;
	int		line_height;

	if (!(ray->side % 2))
		wall_distance = (ray->side_d.x - ray->delta_d.x);
	else
		wall_distance = (ray->side_d.y - ray->delta_d.y);
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
	wall_x -= floorf(wall_x);
	ray->text.x = (int)(wall_x * ft_take_good_wall(game, ray)->len_x);
	ray->t_step.y = SCREENW / TILESIZE / 5;
	ray->tpos.y = ray->pos.x * ray->t_step.y;
	ray->v.x = 0.0;
	ft_draw_line(game, line_height, ray);
}

t_xpm	*ft_take_good_wall(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		return (&game->imgs.texture_n);
	else if (ray->side == 1)
		return (&game->imgs.texture_s);
	else if (ray->side == 2)
		return (&game->imgs.texture_w);
	else if (ray->side == 3)
		return (&game->imgs.texture_e);
	return (&game->imgs.texture_n);
}

void	ft_draw_all_lines_suite(t_game *game, t_vector2 pos, t_ray *ray)
{
	int			tmp;

	tmp = SCREENH;
	while (ray->w.y < tmp + 1)
	{
		pos.x = (int)(ray->tpos.y + ray->v.x);
		pos.y = tmp;
		draw_color(game, game->imgs.img.name, pos, game->imgs.down.coll);
		tmp--;
	}
}

static void	ft_draw_all_lines(t_game *game, int line_height,
	t_ray *ray, t_xpm *display)
{
	t_vector2	pos;

	while (ray->w.y < ray->w.x)
	{
		pos.x = (int)(ray->tpos.y + ray->v.x);
		pos.y = ray->w.y;
		draw_color(game, game->imgs.img.name, pos, game->imgs.top.coll);
		ray->w.y++;
	}
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
	ft_draw_all_lines_suite(game, pos, ray);
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
