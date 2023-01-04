/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:13:25 by nadesjar          #+#    #+#             */
/*   Updated: 2022/11/01 22:36:52 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_free_imgs1(t_game *game)
{
	ft_free(game->imgs.texture_n.name);
	ft_free(game->imgs.texture_s.name);
	ft_free(game->imgs.texture_w.name);
	ft_free(game->imgs.texture_e.name);
	ft_free(game->imgs.light_00.name);
	ft_free(game->imgs.light_01.name);
	ft_free(game->imgs.light_02.name);
	ft_free(game->imgs.wall_extra.name);
	ft_free(game->imgs.top.name);
	ft_free(game->imgs.down.name);
	ft_free_ptr((void **)game->imgs.texture_n.tile);
	ft_free_ptr((void **)game->imgs.texture_s.tile);
	ft_free_ptr((void **)game->imgs.texture_e.tile);
	ft_free_ptr((void **)game->imgs.texture_w.tile);
	ft_free_ptr((void **)game->imgs.light_00.tile);
	ft_free_ptr((void **)game->imgs.light_01.tile);
	ft_free_ptr((void **)game->imgs.light_02.tile);
	ft_free_ptr((void **)game->imgs.wall_extra.tile);
	ft_free_ptr((void **)game->imgs.wall_blood_00.tile);
}

void	ft_free_imgs2(t_game *game)
{
	ft_free_ptr((void **)game->imgs.handgun.handgun.tile);
	ft_free_ptr((void **)game->imgs.handgun.bullet.tile);
	ft_free_ptr((void **)game->imgs.handgun.bullet.all_colors);
	ft_free_ptr((void **)game->imgs.handgun.bullet.cpy_fd);
	ft_free_ptr((void **)game->imgs.handgun.bullet.colors);
	ft_free_ptr((void **)game->imgs.shotgun.bullet.tile);
	ft_free_ptr((void **)game->imgs.shotgun.bullet.all_colors);
	ft_free_ptr((void **)game->imgs.shotgun.bullet.cpy_fd);
	ft_free_ptr((void **)game->imgs.shotgun.bullet.colors);
	ft_free_ptr((void **)game->imgs.sniper.bullet.tile);
	ft_free_ptr((void **)game->imgs.sniper.bullet.all_colors);
	ft_free_ptr((void **)game->imgs.sniper.bullet.cpy_fd);
	ft_free_ptr((void **)game->imgs.sniper.bullet.colors);
	ft_free_ptr((void **)game->imgs.floor.tile);
	ft_free_ptr((void **)game->imgs.floor.all_colors);
	ft_free_ptr((void **)game->imgs.floor.cpy_fd);
	ft_free_ptr((void **)game->imgs.floor.colors);
	ft_free_ptr((void **)game->imgs.roof.tile);
	ft_free_ptr((void **)game->imgs.roof.all_colors);
	ft_free_ptr((void **)game->imgs.roof.cpy_fd);
	ft_free_ptr((void **)game->imgs.roof.colors);
	ft_free_ptr((void **)game->imgs.hit.tile);
	ft_free_ptr((void **)game->imgs.hit.all_colors);
	ft_free_ptr((void **)game->imgs.hit.cpy_fd);
	ft_free_ptr((void **)game->imgs.hit.colors);
}

void	ft_free_imgs3(t_game *game, int i)
{
	i = -1;
	while (++i < 15)
	{
		ft_free_ptr((void **)game->imgs.faces.faces[i].tile);
		ft_free_ptr((void **)game->imgs.faces.faces[i].all_colors);
		ft_free_ptr((void **)game->imgs.faces.faces[i].cpy_fd);
		ft_free_ptr((void **)game->imgs.faces.faces[i].colors);
	}
	i = -1;
	while (++i < 6)
	{
		ft_free_ptr((void **)game->imgs.handgun.fire[i].tile);
		ft_free_ptr((void **)game->imgs.handgun.fire[i].all_colors);
		ft_free_ptr((void **)game->imgs.handgun.fire[i].cpy_fd);
		ft_free_ptr((void **)game->imgs.handgun.fire[i].colors);
	}
	i = -1;
	while (++i < 24)
	{
		ft_free_ptr((void **)game->imgs.shotgun.fire[i].tile);
		ft_free_ptr((void **)game->imgs.shotgun.fire[i].all_colors);
		ft_free_ptr((void **)game->imgs.shotgun.fire[i].cpy_fd);
		ft_free_ptr((void **)game->imgs.shotgun.fire[i].colors);
	}
}

void	ft_free_imgs4(t_game *game, int i)
{
	i = -1;
	while (++i < 26)
	{
		ft_free_ptr((void **)game->imgs.handgun.reload[i].tile);
		ft_free_ptr((void **)game->imgs.handgun.reload[i].all_colors);
		ft_free_ptr((void **)game->imgs.handgun.reload[i].cpy_fd);
		ft_free_ptr((void **)game->imgs.handgun.reload[i].colors);
	}
	i = -1;
	while (++i < 9)
	{
		ft_free_ptr((void **)game->imgs.handgun.rotate[i].tile);
		ft_free_ptr((void **)game->imgs.handgun.rotate[i].all_colors);
		ft_free_ptr((void **)game->imgs.handgun.rotate[i].cpy_fd);
		ft_free_ptr((void **)game->imgs.handgun.rotate[i].colors);
	}
	i = -1;
	while (++i < 11)
	{
		ft_free_ptr((void **)game->imgs.knife.knife[i].tile);
		ft_free_ptr((void **)game->imgs.knife.knife[i].all_colors);
		ft_free_ptr((void **)game->imgs.knife.knife[i].cpy_fd);
		ft_free_ptr((void **)game->imgs.knife.knife[i].colors);
	}
}

void	ft_free_imgs5(t_game *game, int i)
{
	i = -1;
	while (++i < 15)
	{
		ft_free_ptr((void **)game->imgs.sniper.sniper[i].tile);
		ft_free_ptr((void **)game->imgs.sniper.sniper[i].all_colors);
		ft_free_ptr((void **)game->imgs.sniper.sniper[i].cpy_fd);
		ft_free_ptr((void **)game->imgs.sniper.sniper[i].colors);
	}
}
