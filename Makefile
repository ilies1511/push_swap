# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iziane <iziane@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 23:43:41 by iziane            #+#    #+#              #
#    Updated: 2024/05/21 14:10:56 by iziane           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# .SILENT:

NAME		=	push_swap

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g

SRC			=	$(addprefix parser/, input_check.c substring_cases.c utils.c arrayz.c)\
				$(addprefix list_list/, error.c list.c operation_pa.c operation_pb.c operation_sa.c operation_sb.c operation_ss.c operation_ra_or_rb.c operation_rr.c operation_rra_or_rrb.c operation_rrr.c list_manipulator.c utils_algo.c algo.c post_sort.c utils_algo_2.c move_maker.c pre_sort.c)\
				main.c

OBJ			=	$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)


fclean: clean
	make fclean -C $(LIBFT_PATH)
	@rm -rf $(NAME)

clean:
	make clean -C $(LIBFT_PATH)
	@rm -rf $(OBJ)

re: fclean all

.PHONY: all fclean clean re
