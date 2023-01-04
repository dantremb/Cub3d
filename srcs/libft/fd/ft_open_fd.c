/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:35:49 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/04 12:17:41 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_open_fd(char *str, int i)
{
	static int	fd;

	if (i == 1)
		fd = open(str, O_RDONLY, 0644);
	else if (i == 2)
		fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (i == 3)
		fd = open(str, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (i == 4)
		fd = open(str, O_RDWR | O_CREAT | O_APPEND, 0644);
	else if (i == 5)
		fd = open(str, O_WRONLY | O_CREAT, 0644);
	else if (i == 6)
		fd = open(str, O_RDWR | O_APPEND | O_CREAT, 0644);
	else if (i == 7)
		fd = open(str, O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (-1);
	return (fd);
}
