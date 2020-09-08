# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/18 16:35:14 by tallaire          #+#    #+#              #
#    Updated: 2020/09/08 12:16:02 by tallaire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Cub3D

CC		= clang

RM		= rm -rf

CP		= cp -r

LS		= ls -la

CFLAGS		= -Werror -Wextra -Wall -c

#LFLAGS		= -framework OpenGL -framework AppKit
LFLAGS		= -lm -lbsd -lX11 -lXext

INCLUDE_NAME		= cub3d.h\
			  ft_printf.h\
			  get_next_line.h\
			  libft.h\
			  mlx.h

SRC_NAME		= aie_error.c\
			arg_save.c\
			check_color_data.c\
			check_map.c\
			check_is_map_close.c\
			check_is_map_close_last_column.c\
			check_param_file.c\
			check_path.c\
			check_res.c\
			display.c\
			draw_column_px.c\
			escape_game.c\
			exit_game.c\
			free_data.c\
			get_color.c\
			get_data_id.c\
			get_file.c\
			get_map.c\
			get_texture_and_sprite.c\
			get_texture_path.c\
			init.c\
			init_2.c\
			init_3.c\
			key.c\
			main.c\
			move_player.c\
			parsing_map.c\
			print_texture.c\
			raycasting.c\
			raycasting_2.c\
			sprite.c\
			sprite_utils.c\
			utils.c

OBJ_NAME		= $(SRC_NAME:.c=.o)

LIBMLX_MAC		= libmlx.a

LIBMLX_NAME		= libmlx_Linux.a

LIBFT_NAME		= libft.a

LIBPRINTF_NAME		= libftprintf.a

INCLUDE_PATH		= ./includes

SRC_PATH		= ./srcs

OBJ_PATH		= ./.obj

LIB_PATH		= ./.libs

LIBFT_SRC_PATH		= ./ft_printf/libft

LIBPRINTF_SRC_PATH	= ./ft_printf

MLX_LINUX_PATH		= ./minilibx_linux

INCLUDE			= $(addprefix $(INCLUDE_PATH)/, $(INCLUDE_NAME))

SRC			= $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ			= $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

LIBFT			= $(addprefix $(LIB_PATH)/, $(LIBFT_NAME))

LIBPRINTF		= $(addprefix $(LIB_PATH)/, $(LIBPRINTF_NAME))

LIBFT_SRC		= $(addprefix $(LIBFT_SRC_PATH)/, $(LIBFT_NAME))

LIBPRINTF_SRC		= $(addprefix $(LIBPRINTF_SRC_PATH)/, $(LIBPRINTF_NAME))

LIBMLX_LINUX		= $(addprefix $(MLX_LINUX_PATH)/, $(LIBMLX_NAME))

all: $(OBJ_PATH) $(LIB_PATH) $(NAME)

$(OBJ_PATH):
	@echo Creating object directory
	@mkdir -p $(OBJ_PATH)

$(LIB_PATH):
	@echo Creating library directory
	@mkdir -p $(LIB_PATH)

$(NAME): $(OBJ) $(LIBPRINTF) $(LIBFT) $(LIBMLX_LINUX) $(INCLUDE)
	@echo Compiling executable $(NAME)..
	@$(CC) -o $(NAME) $(OBJ) $(LIBPRINTF) $(LIBFT) $(LIBMLX_LINUX) $(LFLAGS)
	@$(LS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo Compiling $< in $@..
	@$(CC) -o $@ $(CFLAGS) $<

$(LIBPRINTF): $(LIBPRINTF_SRC)
	@echo Copy $(LIBPRINTF_SRC) in $(LIBPRINTF)..
	@$(CP) $(LIBPRINTF_SRC) $(LIBPRINTF)

$(LIBPRINTF_SRC):
	@echo Compiling FT_PRINTF..
	@(cd $(LIBPRINTF_SRC_PATH) && $(MAKE))

$(LIBFT): $(LIBFT_SRC)
	@echo Copy $(LIBFT_SRC) in $(LIBFT)..
	@($(CP) $(LIBFT_SRC) $(LIBFT))

$(LIBFT_SRC):
	@echo Compiling LIBFT..
	@(cd $(LIBFT_SRC_PATH) && $(MAKE))

$(LIBMLX_LINUX):
	@echo Compiling minilibx linux..
	@(cd $(MLX_LINUX_PATH) && $(MAKE))

clean:
	@echo Delete $(OBJ)..
	@$(RM) $(OBJ) $(OBJ_PATH)
	@echo Delete library files and directory
	@$(RM) $(LIBFT) $(LIBPRINTF) $(LIB_PATH)
	@(cd $(LIBPRINTF_SRC_PATH) && $(MAKE) clean)
	@$(LS)
	@(cd $(MLX_LINUX_PATH) && $(MAKE) clean)
	@$(LS)

fclean: clean
	@echo Delete executable $(NAME)..
	@$(RM) $(NAME)
	@echo Delete library $(LIBFT)..
	@(cd $(LIBFT_SRC_PATH) && $(RM) $(LIBFT_NAME) && $(LS))
	@echo Delete library $(LIBPRINTF)..
	@(cd $(LIBPRINTF_SRC_PATH) && $(MAKE) fclean && $(LS))
	@$(LS)

re : fclean all

.PHONY: all clean fclean re
