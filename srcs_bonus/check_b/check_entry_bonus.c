/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:49:33 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/04 14:20:15 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	check_entry(t_game *game, int entry, char *name)
{
	if (entry != 2)
	{
		perror("Error, Wrong arguments numbers\n");
		x_quit(game);
	}
	map_read(game, name);
	map_size(game);
	save_map(game);
	check_board(game);
}

int	check_name(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (name == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strncmp(name + len - 4, ".cub", len) != 0)
		return (0);
	return (1);
}

void	map_read(t_game *game, char *name)
{
	int	fd;

	game->tmp = ft_calloc(sizeof(char *), TILESIZE);
	if (!game->tmp)
	{
		free(game->tmp);
		perror("Error, wrong malloc <map_0>");
		x_quit(game);
	}
	fd = open(name, O_RDONLY, 0644);
	game->ct.i = -1;
	while (++game->ct.i >= 0)
	{
		game->tmp[game->ct.i] = get_next_line(fd);
		if (!game->tmp[game->ct.i])
			break ;
	}
	game->len.len_y = game->ct.i;
}

void	map_size(t_game *game)
{
	game->ct.map_size = 0;
	game->ct.i = -1;
	while (game->tmp[++game->ct.i])
	{
		game->ct.k = -1;
		while (game->tmp[game->ct.i][++game->ct.k])
			game->ct.map_size += 1;
	}
}

void	save_map(t_game *game)
{
	int	len;

	game->world_map = ft_calloc(sizeof(char *), game->len.len_y + 1);
	if (!game->world_map)
	{
		perror("Error, wrong malloc <map>\n");
		x_quit(game);
	}
	game->ct.i = -1;
	while (++game->ct.i < game->len.len_y)
	{
		len = ft_strlen(game->tmp[game->ct.i]);
		game->world_map[game->ct.i] = ft_strdup(game->tmp[game->ct.i]);
		game->world_map[game->ct.i][len - 1] = '\0';
		if (len > game->len.max_len_x)
			game->len.max_len_x = len - 1;
		printf("%s\n", game->world_map[game->ct.i]);
	}
	ft_free_ptr((void *)game->tmp);
}
