/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2022/11/01 20:16:15 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

int	ft_check_set(int c, const char *set)
{
	int	i;

	i = 0;
	while (set && set[i])
		if (set[i++] == c)
			return (true);
	return (false);
}

int	ft_charcmp(unsigned char a, unsigned char b)
{
	if (a == b)
		return (true);
	return (false);
}

bool	ft_wait(int delay)
{
	static int	i;

	if (!i || i > delay)
		i = 0;
	if (i == delay)
	{
		i++;
		return (true);
	}
	i++;
	return (false);
}

bool	ft_wait2(int delay)
{
	static int	i;

	if (!i || i > delay)
		i = 0;
	if (i == delay)
	{
		i++;
		return (true);
	}
	i++;
	return (false);
}

bool	ft_wait3(int delay)
{
	static int	i;

	if (!i || i > delay)
		i = 0;
	if (i == delay)
	{
		i++;
		return (true);
	}
	i++;
	return (false);
}
