/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:53:24 by dantremb          #+#    #+#             */
/*   Updated: 2023/01/22 17:45:16 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../libs/libft/includes/libft.h"
# include "../libs/mlx-linux/mlx.h"

typedef struct s_game
{
	char **map;
	char *tx_n;
	char *tx_s;
	char *tx_w;
	char *tx_e;
	char *tx_f;
	char *tx_c;
}				t_game;

#endif