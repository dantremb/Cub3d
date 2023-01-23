/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:53:26 by dantremb          #+#    #+#             */
/*   Updated: 2023/01/22 18:19:53 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(t_game *game, char *error)
{
	printf("Error:Cub3D:%s\n", error);
	(void)game;
	exit(0);
}

bool	ft_validate_filename(char *file)
{
	if (ft_strlen(file) < 5)
		return (true);
	else if (ft_strncmp((file + (ft_strlen(file) - 4)), ".cub", 4) != 0)
		return (true);
	return (false);
}

void	ft_replace_or_load(char **texture, char *temp)
{
	if (*texture)
		ft_free(*texture);
	*texture = ft_strdup(ft_trim_token(temp, ' '));
}

void	ft_load_texture(t_game *game, char *temp)
{
	printf("temp: %s\n", temp);
	if (ft_strncmp(temp, "NO", 2) == 0)
		ft_replace_or_load(&game->tx_n, temp + 2);
	else if (ft_strncmp(temp, "SO", 2) == 0)
		ft_replace_or_load(&game->tx_s, temp + 2);
	else if (ft_strncmp(temp, "WE", 2) == 0)
		ft_replace_or_load(&game->tx_w, temp + 2);
	else if (ft_strncmp(temp, "EA", 2) == 0)
		ft_replace_or_load(&game->tx_e, temp + 2);
	else if (ft_strncmp(temp, "F", 1) == 0)
		ft_replace_or_load(&game->tx_f, temp + 1);
	else if (ft_strncmp(temp, "C", 1) == 0)
		ft_replace_or_load(&game->tx_c, temp + 1);
	else
		ft_exit(game, "Wrong or Missing Texture\n");
}

bool	ft_get_texture(t_game *game, char *file)
{
	printf("ft_get_texture...\n");
	char	*tmp;
	int		fd;
	
	fd  = open(file, O_RDONLY);
	printf("open fd = %d\n", fd);
	if (fd < 0)
		ft_exit(game, "Impossible to Open File\n");
	tmp = ft_get_next_line(fd);
	printf("tmp: %s\n", tmp);
	while (tmp)
	{
		if (tmp[0] != '\n' && !ft_is_only(tmp, ' '))
			ft_load_texture(game, ft_trim_token(tmp, ' '));
		ft_free(tmp);
		if (game->tx_n && game->tx_s && game->tx_e && game->tx_w && game->tx_f && game->tx_c)
			return (false);
		tmp = ft_get_next_line(fd);
	}
	return (true);
}

void	ft_validate_map(t_game *game, char *file)
{
	printf("validating map...\n");
	if (ft_validate_filename(file) == true)
		ft_exit(game, "Invalid file name");
	if (ft_get_texture(game, file))
		ft_exit(game, "Missing data in map file");
}

int main (int argc, char **argv)
{
	t_game game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
		printf("Usage: ./cub3d <map.cub>\n");
	else
		ft_validate_map(&game, argv[1]);
}
