/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/01 00:19:48 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../includes/control.h"

void	ft_clean_map(int fd, t_game *game)
{
	char	*tmp;
	int		fdsave;

	fdsave = ft_open_fd("tmp.cub", 2);
	if (!fdsave)
	{	
		close(fd);
		x_quit(game);
	}
	tmp = get_next_line(fd);
	while (tmp)
	{
		if (tmp[0] != '\n' && !ft_is_only(tmp, ' ', ft_strlen(tmp) - 2))
			ft_putstr_fd(tmp, fdsave);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fdsave);
}

void	ft_split_map_suite(t_game *game, int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp)
	{
		if (tmp[0] != '\n' && !ft_is_only(tmp, ' ', ft_strlen(tmp) - 2))
			ft_load_texture(game, ft_trim_token(tmp, ' '));
		free(tmp);
		if (game->imgs.texture_n.name && game->imgs.texture_s.name
			&& game->imgs.texture_w.name && game->imgs.texture_e.name
			&& game->imgs.down.name && game->imgs.top.name)
			break ;
		tmp = get_next_line(fd);
	}
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
	if (!fd)
	{
		printf("error, wrong open for <name>.cub\n");
		x_quit(game);
	}
	ft_split_map_suite(game, fd);
	ft_clean_map(fd, game);
	close(fd);
}

void	*ft_run_mlx(void *arg)
{
	t_game	*game;

	game = arg;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->w, game->h, "BANKAI");
	ft_init_imgs(game);
	//mlx_mouse_hide();
	game->player = ft_init_player(game);
	mlx_hook(game->win, 17, 0, x_quit, game);
	mlx_loop_hook(game->mlx, ft_routine, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_loop(game->mlx);
	return (NULL);
}

int	main(int entry, char **name)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	ft_split_map(&game, name[1]);
	check_entry(&game, entry, "tmp.cub");
	init_vars(&game);
	ft_run_mlx(&game);
	return (0);
}
