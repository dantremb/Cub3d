/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_xpm2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:29:51 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/14 04:08:54 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_split_xpm_save_colors(t_xpm *xpm, int i)
{
	int	k;

	k = 0;
	while (xpm->cpy_fd[++i])
	{
		if (xpm->cpy_fd[i][0] == '}')
			break ;
		ft_split_xpm_save_colors_suite(xpm, i, k);
		k++;
	}
	k--;
	if (xpm->colors[k][ft_strlen(xpm->colors[k]) - 2] == '}')
	{
		xpm->colors[k][ft_strlen(xpm->colors[k]) - 3] = '\n';
		xpm->colors[k][ft_strlen(xpm->colors[k]) - 2] = '\0';
	}
}

char	*ft_change_sygn(t_xpm *xpm, char c)
{
	int		i;

	i = -1;
	while (xpm->all_colors[++i])
	{
		if (xpm->all_colors[i][0] == c)
		{
			if (ft_strnstr(xpm->all_colors[i], "None",
					ft_strlen(xpm->all_colors[i])))
				return ("None");
			else
				return (xpm->all_colors[i] + 5);
		}
	}
	return (NULL);
}

t_uint	ft_return_rgb(char *str)
{
	t_uint	rgb;
	t_rgb	color;
	char	tmp[2];

	if (ft_strnstr(str, "None", ft_strlen(str)))
	{
		color.t = 255;
		color.r = 0;
		color.g = 0;
		color.b = 0;
		return ((t_uint)create_trgb(color.t, color.r, color.g, color.b));
	}
	color.t = 0;
	tmp[0] = str[0];
	tmp[1] = str[1];
	color.r = ft_atoi_base(tmp, "0123456789ABCDEF");
	tmp[0] = str[2];
	tmp[1] = str[3];
	color.g = ft_atoi_base(tmp, "0123456789ABCDEF");
	tmp[0] = str[4];
	tmp[1] = str[5];
	color.b = ft_atoi_base(tmp, "0123456789ABCDEF");
	rgb = create_trgb(0, color.r, color.g, color.b);
	return (rgb);
}

void	ft_mount_tile(t_xpm *xpm)
{
	int	i;
	int	k;

	i = -1;
	xpm->tile = ft_calloc(sizeof(t_uint *), xpm->len_y + 1);
	while (++i < xpm->len_y)
	{
		xpm->tile[i] = ft_calloc(sizeof(t_uint), xpm->len_x);
		k = -1;
		while (++k < xpm->len_x)
		{
			xpm->tile[i][k] = \
				ft_return_rgb(ft_change_sygn(xpm, xpm->colors[i][k]));
		}
	}
}

char	*ft_change_sygn2(t_xpm *xpm, char *buff)
{
	int		i;

	i = 0;
	while (xpm->all_colors[i])
	{
		if (xpm->all_colors[i][0] == buff[0]
			&& xpm->all_colors[i][1] == buff[1])
		{
			if (ft_strnstr(xpm->all_colors[i],
					"None", ft_strlen(xpm->all_colors[i])))
				return ("None");
			else
				return (xpm->all_colors[i] + 6);
		}
		i++;
	}
	return (NULL);
}
