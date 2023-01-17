/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/17 14:18:34 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_free_imgs6(t_game *game, int i)
{
	i = -1;
	while (++i < 36)
	{
		ft_free_ptr((void **)game->imgs.sniper.load[i].tile);
		ft_free_ptr((void **)game->imgs.sniper.load[i].all_colors);
		ft_free_ptr((void **)game->imgs.sniper.load[i].cpy_fd);
		ft_free_ptr((void **)game->imgs.sniper.load[i].colors);
	}
	i = -1;
	while (++i < 7)
	{
		ft_free_ptr((void **)game->imgs.sniper.zoom[i].tile);
		ft_free_ptr((void **)game->imgs.sniper.zoom[i].all_colors);
		ft_free_ptr((void **)game->imgs.sniper.zoom[i].cpy_fd);
		ft_free_ptr((void **)game->imgs.sniper.zoom[i].colors);
	}
	i = -1;
	while (++i < 18)
	{
		ft_free_ptr((void **)game->imgs.sniper.shoot_zoom[i].tile);
		ft_free_ptr((void **)game->imgs.sniper.shoot_zoom[i].all_colors);
		ft_free_ptr((void **)game->imgs.sniper.shoot_zoom[i].cpy_fd);
		ft_free_ptr((void **)game->imgs.sniper.shoot_zoom[i].colors);
	}
}

void	ft_free_imgs7(t_game *game, int i)
{
	i = -1;
	while (++i < 4)
	{
		ft_free_ptr((void **)game->imgs.skulls.skulls[i].tile);
		ft_free_ptr((void **)game->imgs.skulls.skulls[i].all_colors);
		ft_free_ptr((void **)game->imgs.skulls.skulls[i].cpy_fd);
		ft_free_ptr((void **)game->imgs.skulls.skulls[i].colors);
	}
	i = -1;
	while (++i < 15)
	{
		ft_free_ptr((void **)game->imgs.doors.door0[i].tile);
		ft_free_ptr((void **)game->imgs.doors.door0[i].all_colors);
		ft_free_ptr((void **)game->imgs.doors.door0[i].cpy_fd);
		ft_free_ptr((void **)game->imgs.doors.door0[i].colors);
	}
	i = -1;
	while (++i < 10)
	{
		ft_free_ptr((void **)game->imgs.nbrs.nbrs[i].tile);
		ft_free_ptr((void **)game->imgs.nbrs.nbrs[i].all_colors);
		ft_free_ptr((void **)game->imgs.nbrs.nbrs[i].cpy_fd);
		ft_free_ptr((void **)game->imgs.nbrs.nbrs[i].colors);
	}
}

void	ft_free_imgs8(t_game *game, int i)
{
	i = -1;
	while (++i < 4)
	{
		ft_free_ptr((void **)game->enemy0.face[i].tile);
		ft_free_ptr((void **)game->enemy0.face[i].all_colors);
		ft_free_ptr((void **)game->enemy0.face[i].cpy_fd);
		ft_free_ptr((void **)game->enemy0.face[i].colors);
	}
}

void	ft_free_imgs9(t_game *game)
{
	ft_free_ptr((void **)game->imgs.handgun.logo.tile);
	ft_free_ptr((void **)game->imgs.shotgun.logo.tile);
	ft_free_ptr((void **)game->imgs.knife.logo.tile);
	ft_free_ptr((void **)game->imgs.sniper.logo.tile);
}

int	x_quit(t_game *game)
{
	int	i;

	i = 0;
	game->music.quit = 1;
	system("killall afplay");
	ft_free_ptr((void **)game->world_map);
	ft_free(game->all_ray);
	ft_free(game->ray);
	ft_free_imgs1(game);
	ft_free_imgs2(game);
	ft_free_imgs3(game, i);
	ft_free_imgs4(game, i);
	ft_free_imgs5(game, i);
	ft_free_imgs6(game, i);
	ft_free_imgs7(game, i);
	ft_free_imgs8(game, i);
	ft_free_imgs9(game);
	printf("Why did you kill me !#*@**#?\n");
	exit(0);
}
