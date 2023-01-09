/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/08 19:50:48 by dantremb         ###   ########.fr       */
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


void	ft_replace_or_load(char **texture, char *temp)
{
	if (*texture)
		ft_free(*texture);
	*texture = ft_strdup(ft_trim_token(temp, ' '));
}