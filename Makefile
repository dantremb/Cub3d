# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 16:09:57 by nadesjar          #+#    #+#              #
#    Updated: 2023/01/08 19:13:45 by dantremb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_OBJS 		= ./objs/
PATH_SRCS		= ./srcs/
PATH_INIT		= ./srcs/init/
PATH_KILL		= ./srcs/kill/
PATH_DRAW		= ./srcs/draw/
PATH_UTILS  	= ./srcs/utils/
PATH_MOVE		= ./srcs/moves/
PATH_UPD		= ./srcs/update/
PATH_CHECK		= ./srcs/check/

FILES 			= $(PATH_SRCS)cube_3d.c \
				$(PATH_INIT)init.c $(PATH_INIT)read_xpm.c \
				$(PATH_INIT)read_xpm2.c  $(PATH_INIT)read_xpm3.c \
				$(PATH_KILL)kill.c \
				$(PATH_DRAW)color_rgb.c \
				$(PATH_CHECK)check_boarder.c $(PATH_CHECK)check_entry.c \
				$(PATH_CHECK)check_suite.c \
				$(PATH_MOVE)key_press.c $(PATH_MOVE)key_press2.c \
				$(PATH_UTILS)utils.c $(PATH_UTILS)ft_routine.c \
				$(PATH_UPD)raycast_01.c $(PATH_UPD)raycast_02.c \

OBJS 			= $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(FILES))

PATH_OBJS_B 	= ./objs_bonus/
PATH_SRCS_B		= ./srcs_bonus/
PATH_INIT_B		= ./srcs_bonus/init_b/
PATH_KILL_B		= ./srcs_bonus/kill_b/
PATH_DRAW_B		= ./srcs_bonus/draw_b/
PATH_UTILS_B  	= ./srcs_bonus/utils_b/
PATH_MOVE_B		= ./srcs_bonus/moves_b/
PATH_UPD_B		= ./srcs_bonus/update_b/
PATH_CHECK_B	= ./srcs_bonus/check_b/
PATH_MENU_B		= ./srcs_bonus/menu_b/

FILES_B 		= $(PATH_SRCS_B)cube_3d_bonus.c \
				$(PATH_INIT_B)init_bonus.c $(PATH_INIT)read_xpm.c \
				$(PATH_INIT)read_xpm2.c  $(PATH_INIT)read_xpm3.c \
				$(PATH_INIT_B)init_imgs_bonus.c  $(PATH_INIT_B)init_props_bonus.c \
				$(PATH_INIT_B)threads_bonus.c  $(PATH_INIT_B)threads2_bonus.c \
				$(PATH_MENU_B)menu_bonus.c \
				$(PATH_KILL_B)kill_bonus.c $(PATH_KILL_B)free1_bonus.c \
				$(PATH_DRAW_B)color_rgb_bonus.c $(PATH_DRAW_B)ammo_bonus.c \
				$(PATH_DRAW_B)draw_minimap_bonus.c $(PATH_DRAW_B)faces_bonus.c \
				$(PATH_DRAW_B)handgun_bonus.c $(PATH_DRAW_B)life_bonus.c \
				$(PATH_DRAW_B)put_weapon_bonus.c $(PATH_DRAW_B)reload_handgun_bonus.c \
				$(PATH_DRAW_B)reload_sniper_bonus.c $(PATH_DRAW_B)shotgun_knife_bonus.c \
				$(PATH_DRAW_B)sniper_bonus.c \
				$(PATH_CHECK_B)check_boarder_bonus.c $(PATH_CHECK_B)check_entry_bonus.c \
				$(PATH_CHECK_B)check_suite_bonus.c \
				$(PATH_MOVE_B)key_press_bonus.c $(PATH_MOVE_B)key_press2_bonus.c \
				$(PATH_MOVE_B)mouse_control_bonus.c \
				$(PATH_UTILS_B)utils_bonus.c $(PATH_UTILS_B)ft_routine_bonus.c \
				$(PATH_UTILS_B)utils2_bonus.c \
				$(PATH_UPD_B)raycast_door_01_bonus.c $(PATH_UPD_B)raycast_door_02_bonus.c \
				$(PATH_UPD_B)raycast_enemy_bonus.c $(PATH_UPD_B)raycast_flortop_bonus.c \
				$(PATH_UPD_B)raycast_01_bonus.c $(PATH_UPD_B)raycast_02_bonus.c \

OBJS_B 			= $(patsubst $(PATH_SRCS_B)%.c, $(PATH_OBJS_B)%.o, $(FILES_B))

CC 				= gcc

CFLAGS 			= -Wall -Werror -Wextra
MLXFLAG_MAC 	= -framework OpenGl -framework Cocoa
MLXFLAG_LINUX	= -lbsd -lXext -lX11 -lm

LIBS			= make_lib
MLX_LIB_LINUX	= minilibx/mlx-linux/libmlx.a
MLX_LIB_MAC		= minilibx/opengl/libmlx.a
LIBFT_A			= srcs/libft/libft.a

NAME 			= cub3D
NAME_B			= cub3D_bonus

all: signature $(LIBS) $(NAME)

$(NAME): msg_in $(OBJS) msg_out
	@cp $(MLX_LIB_LINUX) $(NAME)
	@gcc $(OBJS) $(MLX_LIB_LINUX) $(LIBFT_A) $(MLXFLAG_LINUX) -o $(NAME)
# @./$(NAME) ./maps/test_mandatory.cub

$(PATH_OBJS)%.o:	$(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)utils
	@mkdir -p $(PATH_OBJS)kill
	@mkdir -p $(PATH_OBJS)init
	@mkdir -p $(PATH_OBJS)draw
	@mkdir -p $(PATH_OBJS)moves
	@mkdir -p $(PATH_OBJS)ray
	@mkdir -p $(PATH_OBJS)libft
	@mkdir -p $(PATH_OBJS)update
	@mkdir -p $(PATH_OBJS)check
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$G■"

bonus: $(NAME_B)

$(NAME_B): msg_in $(OBJS_B) msg_out
	@cp $(MLX_LIB_LINUX) $(NAME_B)
	@gcc $(OBJS_B) $(MLX_LIB_LINUX) $(LIBFT_A) $(MLXFLAG_LINUX) -o $(NAME_B)
# @./$(NAME_B) ./maps/test.cub

$(PATH_OBJS_B)%.o:	$(PATH_SRCS_B)%.c
	@mkdir -p $(PATH_OBJS_B)
	@mkdir -p $(PATH_OBJS_B)utils_b
	@mkdir -p $(PATH_OBJS_B)kill_b
	@mkdir -p $(PATH_OBJS_B)init_b
	@mkdir -p $(PATH_OBJS_B)draw_b
	@mkdir -p $(PATH_OBJS_B)moves_b
	@mkdir -p $(PATH_OBJS_B)ray_b
	@mkdir -p $(PATH_OBJS_B)libft_b
	@mkdir -p $(PATH_OBJS_B)update_b
	@mkdir -p $(PATH_OBJS_B)check_b
	@mkdir -p $(PATH_OBJS_B)menu_b
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$G■"

make_lib:
	@$(MAKE) -s -C ./srcs/libft

msg_in:
	@echo $L"COMPILATION DE Cub_3D EN COURS..."$W

msg_out:
	@echo $G"\nCUBE READY !!!"$W

clean:
	@rm -fr ./objs/ ./objs_bonus/
	@echo $G"\n                                   BYE BYE\n"$W
	@$(MAKE) clean -C ./srcs/libft

fclean: clean
	@rm -f $(NAME) $(NAME_B) $(LIBFT_A) tmp.cub
	@$(MAKE) fclean -C ./srcs/libft

signature:
	@echo "$G\n\|/~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~\|/"
	@echo " |             ---------------------------------------------             |"
	@echo " |             *--*           $LPROJET: CUB_3D$G            *--*             |"
	@echo " |             *--*      $LPAR: DANTREMB && NADESJAR$G      *--*             |"
	@echo " |             ---------------------------------------------             |"
	@echo "/|\~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~/|\ \n$W"

L	= $(shell tput -Txterm setaf 5)
R	= $(shell tput -Txterm setaf 1)
G	= $(shell tput -Txterm setaf 2)
C	= $(shell tput -Txterm setaf 6)
W	= $(shell tput -Txterm setaf 7)

re:	fclean all

.PHONY: all make_lib push signature msg_in msg_out clean fclean re
