/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/04 12:19:12 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_mount_tile2(t_xpm *xpm)
{
	char	*buff;
	int		i;
	int		k;

	i = -1;
	xpm->tile = ft_calloc(sizeof(t_uint *), xpm->len_y + 1);
	while (++i < xpm->len_y)
	{
		xpm->tile[i] = ft_calloc(sizeof(t_uint), xpm->len_x);
		k = -1;
		while (++k < xpm->len_x)
		{
			buff = ft_charjoin(xpm->colors[i][k * 2],
					xpm->colors[i][k * 2 + 1]);
			xpm->tile[i][k] = ft_return_rgb(ft_change_sygn2(xpm, buff));
			ft_free(buff);
		}
	}
}

int	ft_imgs_load(t_xpm *xpm, int k)
{
	if (ft_strrchr(xpm->c_nbr, '2', 6) != NULL)
	{
		ft_color(2);
		printf("Image #[%d] Named [%s] load\n", ++k, xpm->name);
		ft_color(8);
		ft_mount_tile2(xpm);
	}
	else if (ft_strrchr(xpm->c_nbr, '1', 6) != NULL)
	{
		ft_color(2);
		printf("Image #[%d] Named [%s] load\n", ++k, xpm->name);
		ft_color(8);
		ft_mount_tile(xpm);
	}
	else
	{
		ft_color(1);
		printf("Image NOT load\n");
		ft_color(8);
	}
	return (k);
}

void	ft_split_color_xpm(t_game *game, t_xpm *xpm)
{
	int	i;

	xpm->colors = ft_calloc(sizeof(char *), 2096);
	xpm->all_colors = ft_calloc(sizeof(char *), 2096);
	if (!xpm->colors || !xpm->all_colors)
	{
		printf("error, wrong alloc <ft_split_xpm>\n");
		x_quit(game);
	}
	if (ft_strnstr(xpm->cpy_fd[2], "pixel", ft_strlen(xpm->cpy_fd[2])))
		i = 3;
	else
		i = 2;
	i = ft_split_xpm_save_all_colors(xpm, i);
	while (xpm->cpy_fd[i])
	{
		if (strncmp(xpm->cpy_fd[i], "/* pixels */", 12) == 0)
		{
			ft_split_xpm_save_colors(xpm, i);
			break ;
		}
		i++;
	}
}

void	ft_split_xpm(t_game *game, t_xpm *xpm)
{
	static int	k;
	int			fd;

	if (!k)
		k = 0;
	fd = ft_open_fd(xpm->name, 1);
	if (fd < 0)
	{
		printf("error, wrong fd <ft_split_xpm>\n");
		x_quit(game);
	}
	ft_read_xpm(game, xpm, fd);
	close(fd);
	ft_split_color_xpm(game, xpm);
	k = ft_imgs_load(xpm, k);
}
