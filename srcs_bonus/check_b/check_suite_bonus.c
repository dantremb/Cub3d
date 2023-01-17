/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_suite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:03:48 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/09 15:35:16 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"
#include "../../includes_bonus/control_bonus.h"

void	check_direction_suite(t_game *game)
{
	if (game->world_map[game->ct.i][game->ct.k] == CASE_N)
	{
		game->dir_x = -1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
	if (game->world_map[game->ct.i][game->ct.k] == CASE_S)
	{
		game->dir_x = 1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = -0.66;
	}
}

void	check_direction(t_game *game)
{
	if (game->world_map[game->ct.i][game->ct.k] == CASE_E)
	{
		game->dir_x = 0;
		game->dir_y = 1;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
	if (game->world_map[game->ct.i][game->ct.k] == CASE_W)
	{
		game->dir_x = 0;
		game->dir_y = -1;
		game->plane_x = -0.66;
		game->plane_y = 0;
	}
	check_direction_suite(game);
}

void	ft_change_nsew(t_game *game)
{
	int	line;
	int	i;

	i = -1;
	while (ft_strchr_bool(game->world_map[++i], 'N') == false
		&& ft_strchr_bool(game->world_map[i], 'S') == false
		&& ft_strchr_bool(game->world_map[i], 'E') == false
		&& ft_strchr_bool(game->world_map[i], 'W') == false
		&& game->world_map[i])
		;
	line = i;
	i = -1;
	while ((game->world_map[line][++i] != 'N'
		&& game->world_map[line][i] != 'S'
			&& game->world_map[line][i] != 'E'
			&& game->world_map[line][i] != 'W')
			&& game->world_map[line][i] != '\0')
		;
	game->pos_x = line + 0.5;
	game->pos_y = i + 0.5;
	game->world_map[line][i] = '0';
}

void	ft_check_double(t_game *game)
{
	int	i;
	int	ct;

	ct = 0;
	i = -1;
	while (game->world_map[++i])
	{
		if ((ft_strchr_bool(game->world_map[i], 'N') == true
				|| ft_strchr_bool(game->world_map[i], 'S') == true
				|| ft_strchr_bool(game->world_map[i], 'E') == true
				|| ft_strchr_bool(game->world_map[i], 'W') == true)
			&& game->world_map[i])
		ct++;
	}
	if (ct != 1)
		game->ct.error = -2;
}

bool	ft_valid_map(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (!ft_strchr("0127ZNSEW \n", line[i]))
		{
			printf("Error, invalid letter in map.\n");
			return (true);
		}
	}
	return (false);
}
