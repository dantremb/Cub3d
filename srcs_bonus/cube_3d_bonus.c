/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/08 20:17:24 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube3d_bonus.h"

void	ft_clean_map(int fd)
{
	char	*tmp;
	int		fdsave;

	fdsave = ft_open_fd("tmp.cub", 2);
	if (fdsave < 0)
		return ;
	tmp = get_next_line(fd);
	while (tmp[0] == '\n' || ft_is_only(tmp, ' ', ft_strlen(tmp) - 2))
	{
		ft_free(tmp);
		tmp = get_next_line(fd);
	}
	while (tmp)
	{
		ft_putstr_fd(tmp, fdsave);
		ft_free(tmp);
		tmp = get_next_line(fd);
	}
	close(fdsave);
}

int	ft_split_map_suite(t_game *game, int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp)
	{
		if (tmp[0] != '\n' && !ft_is_only(tmp, ' ', ft_strlen(tmp) - 2))
			ft_load_texture(game, ft_trim_token(tmp, ' '));
		ft_free(tmp);
		if (game->imgs.texture_n.name && game->imgs.texture_s.name
			&& game->imgs.texture_w.name && game->imgs.texture_e.name
			&& game->imgs.down.name && game->imgs.top.name)
			return (0);
		tmp = get_next_line(fd);
	}
	return (1);
}

void	ft_split_map(t_game *game, char *name)
{
	int	fd;

	if (check_name(name) == 0)
	{
		printf("Error, Invalid files <name>.cub\n");
		x_quit(game);
	}
	fd = ft_open_fd(name, 1);
	if (fd < 0)
	{
		printf("error, wrong open for <name>.cub\n");
		x_quit(game);
	}
	if (ft_split_map_suite(game, fd))
	{
		printf("Error, missing map data <name>.cub\n");
		close(fd);
		x_quit(game);
	}
	ft_clean_map(fd);
	close(fd);
}

void	*ft_run_mlx(void *arg)
{
	t_game	*game;

	game = arg;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->w, game->h, "BANKAI");
	ft_init_imgs(game);
	game->player = ft_init_player(game);
	mlx_hook(game->win, 17, 0, x_quit, game);
	mlx_loop_hook(game->mlx, ft_routine, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 6, 1L << 6, mouse_move, game);
	mlx_mouse_hook(game->win, ft_shoot, game);
	mlx_loop(game->mlx);
	return (NULL);
}

int	main(int entry, char **name)
{
	t_game	game;

	if (entry == 2)
	{
		ft_memset(&game, 0, sizeof(t_game));
		ft_split_map(&game, name[1]);
		check_entry(&game, entry, "tmp.cub");
		init_vars(&game);
		ft_run_mlx(&game);
	}
	else
		printf("Please enter a valid map name.\n");
	return (0);
}
