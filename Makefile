# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iziane <iziane@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 23:43:41 by iziane            #+#    #+#              #
#    Updated: 2024/05/06 17:22:29 by iziane           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g

SRC			=	$(addprefix parser/, input_check.c substring_cases.c utils.c arrayz.c)\
				$(addprefix list_list/, error.c list.c operation_pb.c operation_sa.c operation_sb.c operation_ss.c)\
 				main.c

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
