/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/17 14:19:13 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_free_imgs1(t_game *game)
{
	ft_free(game->imgs.texture_n.name);
	ft_free(game->imgs.texture_s.name);
	ft_free(game->imgs.texture_w.name);
	ft_free(game->imgs.texture_e.name);
	ft_free_ptr((void **)game->imgs.texture_n.tile);
	ft_free_ptr((void **)game->imgs.texture_s.tile);
	ft_free_ptr((void **)game->imgs.texture_e.tile);
	ft_free_ptr((void **)game->imgs.texture_w.tile);
}

int	x_quit(t_game *game)
{
	ft_free_ptr((void **)game->world_map);
	ft_free(game->ray);
	ft_free_imgs1(game);
	printf("Why did you kill me !#*@**#?\n");
	exit(0);
}
