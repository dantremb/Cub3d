/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/29 23:30:14 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

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