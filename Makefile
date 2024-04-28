# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iziane <iziane@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 23:43:41 by iziane            #+#    #+#              #
#    Updated: 2024/04/27 14:37:23 by iziane           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g

SRC			=	utils.c main.c

OBJ			=	$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@cd $(LIBFT_PATH) && make -s


fclean: clean
	@cd $(LIBFT_PATH) && make fclean -s
	@rm -rf $(NAME)

clean:
	@cd $(LIBFT_PATH) && make clean -s
	@rm -rf $(OBJ)

re: fclean all

.PHONY: all fclean clean re