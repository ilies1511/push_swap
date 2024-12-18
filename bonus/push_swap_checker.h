/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:49:24 by iziane            #+#    #+#             */
/*   Updated: 2024/05/23 05:14:24 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
// # include "../push_swap.h"
# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"

typedef struct s_array_filler
{
	int		i;
	int		k;
	int		substring_words;
	char	**substring_case;
	int		j;
}			t_array_filler;

typedef struct s_find_target_pos
{
	int		delta_index;
	int		len_a;
	int		len_b;
	int		k;
	int		i;
}			t_target;

typedef struct s_node
{
	int				cost_a;
	int				cost_b;
	int				x;
	int				target_pos;
	int				target_x;
	int				pos;
	int				index;
	int				target_index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_swap
{
	int		len;
	t_node	*first;
	t_node	*second;
	t_node	*third;
	t_node	*last;
}			t_swap;

// Utils Parcing Input (Array)
int		number_counter(char **argv);
void	parcer(char **argv, int amount_numbers);
void	central(int amount_numbers, char **argv);
int		pre_atoi(char *str);
void	int_range_check(char **argv, int amount_numbers);
void	substring_case_function(int substring_words, char **argv, int *k);
void	substring_case_function_preatoi(int words, char **argv, int *k);
int		*array_filler(int *amount_numbers, char **argv, int *array);
int		count_word(const char *str);
void	sort_array(int *array, int len);
int		check_duplicates(int *array, int amount_numbers);
int		*make_array(int *amount_numbers, char **argv);
void	print_array(int *array, int amount_numbers);
int		*array_dub(int *array, int amount_numbers);
//Utils Linked List
void	list_manager(int *array, int amount_numbers, int *sorted_array);
void	add_begin(t_node **tail, int value);
t_node	*init_list(t_node **tail, t_node **head, int value);
void	deallocate_list(t_node **tail);
void	add_end(t_node **tail, int value);
int		count_node(t_node **tail);
//Algo
void	init_index(t_node **tail, int *sorted_array, int len);
t_node	*find_highest(t_node **tail);
t_node	*find_lowest(t_node **tail);
// void	tiny_sort(t_node **tail);
int		sort_checker_bonus(t_node **tail);
void	p2b(t_node **tail_a, t_node **tail_b);
void	current_position(t_node **tail);
int		target_value(t_node *a, int i);
void	shifter(t_node **tail_a);
//Operation
void	sa(t_node **tail);
void	sb(t_node **tail);
void	ss(t_node **tail_a, t_node **tail_b);
void	pb(t_node **tail_a, t_node **tail_b);
void	pa(t_node **tail_a, t_node **tail_b);
void	ra(t_node **tail);
void	rb(t_node **tail);
void	rr(t_node **tail_a, t_node **tail_b);
void	rra(t_node **tail);
void	rrb(t_node **tail);
void	rrr(t_node **tail_a, t_node **tail_b);
//Bonus
int		ft_space_checker(const char *str);
int		reader(t_node	**tail_a, t_node **tail_b);

#endif
