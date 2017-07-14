# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/02 12:01:32 by jle-quel          #+#    #+#              #
#    Updated: 2017/07/14 18:18:11 by jefferson        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

FLAGS += -Wall -Wextra -Werror -I includes

SRC =	./sources/main.c		\
		./sources/ft_tools.c	\
		./sources/ft_termcap.c	\
		./sources/ft_signal1.c	\
		./sources/ft_signal2.c	\
		./sources/ft_select.c	\
		./sources/ft_display1.c	\
		./sources/ft_display2.c	\
		./sources/ft_cursor.c	\

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(FLAGS) $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -lncurses -o $(NAME)
	@echo "\033[32mCompiled Executable\033[0m"

clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean
	@make
