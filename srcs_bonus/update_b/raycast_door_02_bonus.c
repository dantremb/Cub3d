/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_door_02_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:20:34 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/14 04:07:42 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

t_xpm	*ft_take_good_wall_d(t_game *game)
{
	static int	i;

	if (!i)
		i = 0;
	if (game->door_ct == 1)
	{
		if (game->door_open_ct < 14)
			return (&game->imgs.doors.door0[game->door_open_ct]);
		if (game->door_open_ct == 14)
			return (&game->imgs.doors.door0[14]);
	}
	else if (game->door_ct == 0)
	{
		if (game->door_open_ct > 0)
		{
			if (game->door_open_ct == 14)
				return (&game->imgs.doors.door0[game->door_open_ct--]);
			return (&game->imgs.doors.door0[game->door_open_ct]);
		}
		if (game->door_open_ct == 0)
			return (&game->imgs.doors.door0[0]);
	}
	else
		return (&game->imgs.doors.door0[0]);
	return (&game->imgs.doors.door0[0]);
}

void	ft_draw_walls_d(t_game *game, t_vector2 pos, t_ray *ray, t_xpm *display)
{
	while (ray->w.x < ray->draw.y)
	{
		ray->text.y = (int)ray->tpos.x & (display->len_y - 1);
		ray->tpos.x += ray->t_step.x;
		pos.x = (int)(ray->tpos.y + ray->v.x);
		pos.y = ray->w.x;
		if (game->world_map[ray->map.x][ray->map.y] == '2')
		{
			if (display->tile[ray->text.y][ray->text.x] != (t_uint) - 16777216)
				draw_color(game, game->imgs.img.name, pos,
					(int)display->tile[ray->text.y][ray->text.x]);
		}
		ray->w.x++;
	}
}

static void	ft_draw_all_lines_d(t_game *game, int line_height,
	t_ray *ray, t_xpm *display)
{
	t_vector2	pos;

	pos.x = (int)(ray->tpos.y + ray->v.x);
	pos.y = ray->w.y;
	while (ray->w.y < ray->w.x)
		ray->w.y++;
	ray->t_step.x = 1.0 * display->len_x / line_height;
	ray->tpos.x = (ray->draw.x - SCREENH / 2 + line_height / 2) * ray->t_step.x;
	ft_draw_walls_d(game, pos, ray, display);
	ray->w.y = ray->w.x;
}

void	ft_draw_line_d(t_game *game, int line_height, t_ray *ray)
{
	t_xpm	*display;

	display = ft_take_good_wall_d(game);
	if (ray->side == 0 && ray->raydir.x > 0)
		ray->text.x = display->len_x - ray->text.x - 1;
	if (ray->side == 1 && ray->raydir.y < 0)
		ray->text.x = display->len_x - ray->text.x - 1;
	while (ray->tpos.y + ray->v.x < ray->tpos.y
		+ (ray->t_step.y * PRECISION) && ray->tpos.y < SCREENW)
	{
		ray->w.y = 0;
		ray->w.x = ray->draw.x;
		ft_draw_all_lines_d(game, line_height, ray, display);
		ray->v.x += PRECISION;
	}
}
