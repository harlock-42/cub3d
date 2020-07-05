# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 15:29:36 by tallaire          #+#    #+#              #
#    Updated: 2020/03/12 16:51:19 by tallaire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC		= clang

RM		= rm -rf

CP		= cp -R

LS		= ls -la

CFLAGS 		= -Werror -Wextra -Wall -Weverything -c

INCLUDE 	= ./includes/ft_printf.h\
		  ./includes/libft.h

SRC_NAME 	=	ft_printf.c\
			ft_printf_utils.c\
			ft_printf_utils_2.c\
			ft_printf_check_convert.c\
			ft_printf_get_convert.c\
			ft_printf_do_width_string.c\
			ft_printf_do_width_int.c\
			ft_printf_do_width_ptr.c\
			ft_printf_do_width_int_base.c\
			ft_printf_char.c\
			ft_printf_int.c\
			ft_printf_int_base.c\
			ft_printf_string.c\
			ft_printf_ptr.c\
			ft_printf_modulo.c

OBJ_NAME		= $(SRC_NAME:.c=.o)

LIBFT_NAME		= libft.a

SRC_PATH		= ./srcs

OBJ_PATH		= ./.obj

LIB_PATH		= ./.libs

LIBFT_SRC_PATH		= ./libft

SRC			= $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ			= $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

LIBFT			= $(addprefix $(LIB_PATH)/, $(LIBFT_NAME))

LIBFT_SRC		= $(addprefix $(LIBFT_SRC_PATH)/, $(LIBFT_NAME))

all: $(OBJ_PATH) $(LIB_PATH) $(NAME)

$(OBJ_PATH):
	@echo Creating object directory..
	@mkdir -p $(OBJ_PATH)

$(LIB_PATH):
	@echo Creating library directory..
	@mkdir -p $(LIB_PATH)

$(NAME): $(OBJ) $(LIBFT) $(INCLUDE)
	@echo Compiling executable $(NAME)..
	@ar rc $(NAME) $(OBJ) $(LIBFT)
	@$(LS)


$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo Compiling $< in $@..
	@$(CC) -o $@ $(CFLAGS) $<

$(LIBFT): $(LIBFT_SRC)
	@echo Copy $(LIBFT_SRC) in $(LIBFT)
	@$(CP) $(LIBFT_SRC) $(LIBFT)

$(LIBFT_SRC):
	@echo Compiling Libft..
	@(cd ./libft && $(MAKE))

clean:
	@echo Delete $(OBJ_NAME)
	@$(RM) $(OBJ)
	@echo Delete $(OBJ_PATH)
	@$(RM) $(OBJ_PATH)
	@$(LS)
	@echo Delete object files and directory from Libft..
	@(cd ./libft && $(MAKE) clean && $(LS))

fclean: clean
	@echo Delete $(NAME)
	@$(RM) $(NAME)
	@echo Delete $(LIBFT_NAME) from Libft..
	@$(RM) $(LIBFT_SRC)
	@echo Delete $(LIBFT)..
	@$(RM) $(LIBFT) $(LIB_PATH)

re: fclean all

.PHONY: all clean fclean re
