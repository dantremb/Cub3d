/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:01:15 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/04 12:17:59 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	int	len;

	if (!str || fd <= 0)
		return ;
	len = ft_strlen(str);
	if (str)
		write(fd, str, len);
	ft_putchar_fd('\n', fd);
}
