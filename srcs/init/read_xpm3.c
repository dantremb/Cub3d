/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_xpm3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:29:03 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/04 14:17:38 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_init_lens_suite(t_game *game, t_xpm *xpm, int ct, int k)
{
	char	*tmp;
	int		i;

	tmp = ft_calloc(sizeof(char), 5);
	if (!tmp)
	{
		printf("error, wrong alloc <init_lens>\n");
		x_quit(game);
	}
	i = 0;
	while (xpm->cpy_fd[ct][++i] != ' ')
		tmp[++k] = xpm->cpy_fd[ct][i];
	xpm->len_x = ft_atoi(tmp);
	k = -1;
	while (xpm->cpy_fd[ct][++i] != ' ')
		tmp[++k] = xpm->cpy_fd[ct][i];
	tmp[++k] = '\0';
	xpm->len_y = ft_atoi(tmp);
	ft_free((char *)tmp);
}

void	ft_init_lens(t_game *game, t_xpm *xpm)
{
	int		k;
	int		ct;

	if (ft_strnstr(xpm->cpy_fd[2], "pixel", ft_strlen(xpm->cpy_fd[2])))
		ct = 3;
	else
		ct = 2;
	k = -1;
	if (xpm->cpy_fd[ct])
		ft_init_lens_suite(game, xpm, ct, k);
}

void	ft_read_xpm(t_game *game, t_xpm *xpm, int fd)
{
	char	*buff;
	int		i;

	xpm->cpy_fd = ft_calloc(sizeof(char *), 2000);
	buff = get_next_line(fd);
	i = -1;
	while (buff)
	{
		xpm->cpy_fd[++i] = ft_strdup(buff);
		free(buff);
		buff = get_next_line(fd);
	}
	ft_init_lens(game, xpm);
	ft_free(buff);
}

int	ft_split_xpm_save_all_colors(t_xpm *xpm, int i)
{
	int	k;
	int	tmp;

	tmp = i;
	k = 0;
	while (xpm->cpy_fd[++i])
	{
		if (strncmp(xpm->cpy_fd[i], "/* pixels */", 12) == 0)
			break ;
		xpm->all_colors[k] = ft_strdup(xpm->cpy_fd[i] + 1);
		xpm->all_colors[k]
		[ft_strlen(xpm->all_colors[k]) - 3] = '\n';
		xpm->all_colors[k]
		[ft_strlen(xpm->all_colors[k]) - 2] = '\0';
		k++;
	}
	xpm->c_nbr = ft_strdup(xpm->cpy_fd[tmp]);
	return (i);
}

void	ft_split_xpm_save_colors_suite(t_xpm *xpm, int i, int k)
{
	xpm->colors[k] = ft_strdup(xpm->cpy_fd[i] + 1);
	if (xpm->colors[k][ft_strlen(xpm->colors[k]) - 2] == ',')
	{
		xpm->colors[k][ft_strlen(xpm->colors[k]) - 3] = '\n';
		xpm->colors[k][ft_strlen(xpm->colors[k]) - 2] = '\0';
	}
	else
	{
		xpm->colors[k][ft_strlen(xpm->colors[k]) - 2] = '\n';
		xpm->colors[k][ft_strlen(xpm->colors[k]) - 1] = '\0';
	}
}
