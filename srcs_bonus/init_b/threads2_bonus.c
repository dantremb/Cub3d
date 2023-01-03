/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads2_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:52:57 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/13 11:29:48 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	*ft_load_imgs6(void *arg)
{
	t_game	*game;

	game = arg;
	ft_init_shotgun(game);
	return (NULL);
}

void	ft_start_threads(t_game *game)
{
	if (pthread_create(&game->load_imgs[0],
			NULL, &ft_load_imgs1, &game[0]) != 0)
		return ;
	if (pthread_create(&game->load_imgs2[0],
			NULL, &ft_load_imgs2, &game[0]) != 0)
		return ;
	if (pthread_create(&game->load_imgs3[0],
			NULL, &ft_load_imgs3, &game[0]) != 0)
		return ;
	if (pthread_create(&game->load_imgs4[0],
			NULL, &ft_load_imgs4, &game[0]) != 0)
		return ;
	if (pthread_create(&game->load_imgs5[0],
			NULL, &ft_load_imgs5, &game[0]) != 0)
		return ;
	if (pthread_create(&game->load_imgs6[0],
			NULL, &ft_load_imgs6, &game[0]) != 0)
		return ;
}

void	ft_end_threads(t_game *game)
{
	if (pthread_join(game->load_imgs[0], NULL) != 0)
		return ;
	if (pthread_join(game->load_imgs2[0], NULL) != 0)
		return ;
	if (pthread_join(game->load_imgs3[0], NULL) != 0)
		return ;
	if (pthread_join(game->load_imgs4[0], NULL) != 0)
		return ;
	if (pthread_join(game->load_imgs5[0], NULL) != 0)
		return ;
	if (pthread_join(game->load_imgs6[0], NULL) != 0)
		return ;
}
