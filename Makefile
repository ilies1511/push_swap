# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iziane <iziane@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 23:43:41 by iziane            #+#    #+#              #
#    Updated: 2024/05/23 02:27:22 by iziane           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME			=	push_swap
NAME_CHECKER	=	checker

SRC_MAIN		=	main.c
OBJ_MAIN		=	$(SRC_MAIN:.c=.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g

SRC			=	$(addprefix parser/, input_check.c substring_cases.c utils.c arrayz.c)\
				$(addprefix list_list/, error.c list.c operation_pa.c operation_pb.c operation_sa.c operation_sb.c operation_ss.c operation_ra_or_rb.c operation_rr.c operation_rra_or_rrb.c operation_rrr.c list_manipulator.c utils_algo.c algo.c post_sort.c utils_algo_2.c move_maker.c pre_sort.c go2algo.c)\

OBJ			=	$(SRC:%.c=%.o)

SRC_CHECKER	=	$(addprefix bonus/, pre_sort.c utils_algo.c utils_algo_2.c arrayz.c error.c heart.c input_check.c list_manipulator.c main_checker.c operation_pa.c operation_pb.c operation_ra_or_rb.c operation_rr.c operation_rra_or_rrb.c operation_rrr.c operation_sa.c operation_sb.c operation_ss.c post_sort.c substring_cases.c utils.c )

OBJ_CHECKER	= $(SRC_CHECKER:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_MAIN) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_MAIN) $(LIBFT) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)


fclean: clean
	make fclean -C $(LIBFT_PATH)
	@rm -rf $(NAME)
	@rm -rf $(NAME_CHECKER)

clean:
	make clean -C $(LIBFT_PATH)
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_MAIN)
	@rm -rf $(OBJ_CHECKER)

re: fclean all

bonus: $(LIBFT) $(OBJ_CHECKER)
	 $(CC) $(CFLAGS) $(OBJ_CHECKER) $(LIBFT) -o $(NAME_CHECKER)

.PHONY: all fclean clean re bonus
