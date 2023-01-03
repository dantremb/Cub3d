/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faces_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:45:06 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/14 04:03:19 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_put_faces1(t_game *game)
{
	if (game->player->life >= 320)
		game->tmp_face = game->imgs.faces.faces[0];
	else if (game->player->life >= 220)
		game->tmp_face = game->imgs.faces.faces[3];
	else if (game->player->life >= 130)
		game->tmp_face = game->imgs.faces.faces[6];
	else if (game->player->life >= 60)
		game->tmp_face = game->imgs.faces.faces[9];
	else if (game->player->life >= 0)
		game->tmp_face = game->imgs.faces.faces[12];
}

void	ft_put_faces2(t_game *game)
{
	if (game->player->life >= 320)
		game->tmp_face = game->imgs.faces.faces[1];
	else if (game->player->life >= 220)
		game->tmp_face = game->imgs.faces.faces[4];
	else if (game->player->life >= 130)
		game->tmp_face = game->imgs.faces.faces[7];
	else if (game->player->life >= 60)
		game->tmp_face = game->imgs.faces.faces[10];
	else if (game->player->life >= 0)
		game->tmp_face = game->imgs.faces.faces[13];
}

void	ft_put_faces3(t_game *game)
{
	if (game->player->life >= 320)
		game->tmp_face = game->imgs.faces.faces[2];
	else if (game->player->life >= 220)
		game->tmp_face = game->imgs.faces.faces[5];
	else if (game->player->life >= 130)
		game->tmp_face = game->imgs.faces.faces[8];
	else if (game->player->life >= 60)
		game->tmp_face = game->imgs.faces.faces[11];
	else if (game->player->life >= 0)
		game->tmp_face = game->imgs.faces.faces[14];
}

void	ft_put_faces(t_game *game)
{
	t_vector2	pos;

	if (ft_wait(10) == true)
	{
		if (game->ct.face >= 0 && game->ct.face <= 333)
			ft_put_faces1(game);
		else if (game->ct.face >= 334 && game->ct.face <= 666)
			ft_put_faces2(game);
		else if (game->ct.face >= 667 && game->ct.face <= 1000)
			ft_put_faces3(game);
	}
	pos.x = 330;
	pos.y = 10;
	ft_print_sprite(game, &game->tmp_face, pos, -16777216);
}
