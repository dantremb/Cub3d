/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:44:15 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/28 22:22:26 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_H
# define CONTROL_H

// LINUX //
typedef enum s_keyboard
{
	KEY_A = 97,
	KEY_D = 100,
	KEY_S = 115,
	KEY_W = 119,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_E = 101,
	KEY_R = 114,
	KEY_M_L = 1,
	KEY_M_R = 3,
	KEY_0 = 48,
	KEY_1 = 49,
	KEY_2 = 50,
	KEY_3 = 51,
	KEY_SPACE = 32,
	KEY_ENTER = 65293,
	KEY_ESC = 65307,
	KEY_TAB = 65289,
}	t_keyboard;

// mac //
/*
typedef enum s_keyboard
{
	KEY_A = 0,
	KEY_D = 2,
	KEY_S = 1,
	KEY_W = 13,
	KEY_RIGHT = 124,
	KEY_LEFT = 123,
	KEY_E = 14,
	KEY_Q = 12,
	KEY_R = 15,
	KEY_0 = 29,
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_TAB = 48,
	KEY_ENTER = 36,
	KEY_SPACE = 49,
	KEY_ESC = 53,
}	t_keyboard;
*/

typedef enum s_letters{
	CASE_0 = '0',
	CASE_1 = '1',
	CASE_N = 'N',
	CASE_S = 'S',
	CASE_E = 'E',
	CASE_W = 'W',
}	t_letters;

#endif