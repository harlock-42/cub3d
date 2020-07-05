# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 14:39:06 by tallaire          #+#    #+#              #
#    Updated: 2019/12/23 11:10:56 by tallaire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

RM = rm -rf

CFLAGS = -Werror -Wextra -Wall -c

HEADER = ./includes/libft.h

BUFFER_SIZE = -D BUFFER_SIZE=1024

SRC_NAME =		c_is_str.c\
		ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strcpy.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\
		get_next_line.c\
		get_next_line_utils.c

OBJ_NAME	= $(SRC_NAME:.c=.o)

SRCBONUS =	$(SRC)\
			ft_lstnew_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstiter_bonus.c

OBJ_PATH	= ./.obj

SRC_PATH	= ./srcs

OBJBONUS =	$(SRC:.c=.o)\
			$(SRCBONUS:.c=.o)

OBJ		= $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
SRC		= $(addprefix $(SRC_PATH)/, $(SRC_NAME))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@echo Creating object directory
	@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ) $(HEADER)
	@echo Compiling $(NAME)..
	@ar rc $(NAME) $(OBJ)
	@echo ranlib $(NAME)..
	@ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo Compiling $< in $@..
	@$(CC) -o $@ $(CFLAGS) $(BUFFER_SIZE) $<

bonus: $(BONUS) $(HEADER)
	@$(CC) $(CFLAGS) $(SRCBONUS)
	@ar rc $(NAME) $(OBJBONUS)
	@ranlib $(NAME)

clean:
	@echo Delete $(OBJ)
	@$(RM) $(OBJ) $(OBJ_PATH) $(OBJBONUS)

fclean: clean
	@echo delete $(NAME)
	@$(RM) $(NAME)

re: fclean all

print-%:
	@echo $*=$($*)

.PHONY: all bonus clean fclean re
