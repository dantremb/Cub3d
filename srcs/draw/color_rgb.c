/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2022/11/01 18:47:42 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

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
