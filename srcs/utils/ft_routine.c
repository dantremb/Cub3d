/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/14 04:02:30 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	ft_routine(t_game *game)
{
	ft_raycast(game);
	ft_move_lft(game);
	ft_move_ri(game);
	ft_move_w(game);
	ft_move_s(game);
	ft_move_a(game);
	ft_move_d(game);
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.img.img, 0, 0);
	return (0);
}
