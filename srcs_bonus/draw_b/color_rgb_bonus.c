/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2022/11/01 20:12:23 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_color(t_game *game, char *img, t_vector2 pos, int color)
{
	char	*dst;

	dst = img + (pos.y * game->pixel + pos.x * (game->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_print_sprite(t_game *game, t_xpm *img,
	t_vector2 start_pos, t_uint color)
{
	t_vector2	pos;
	t_vector2	totalpos;

	pos.y = -1;
	while (++pos.y < img->len_y)
	{
		pos.x = -1;
		while (++pos.x < img->len_x)
		{
			if (img->tile[pos.y][pos.x] != color)
			{
				totalpos.x = start_pos.x + pos.x;
				totalpos.y = start_pos.y + pos.y;
				if (totalpos.x < SCREENW && totalpos.y < SCREENH)
					draw_color(game, game->imgs.img.name, totalpos,
						(int)img->tile[pos.y][pos.x]);
			}
		}
	}
}
