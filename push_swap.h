/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:17:19 by iziane            #+#    #+#             */
/*   Updated: 2024/05/21 11:14:35 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

// typedef struct s_swap
// {
// 	int		len;
// 	t_node	*first;
// 	t_node	*second;
// 	t_node	*third;
// 	t_node	*last;
// }			t_swap;

typedef struct s_find_target_pos
{
	int		delta_index;
	int		len_a;
	int		len_b;
	int		k;
	int		i;
}			t_target;

// typedef struct s_extrems
// {
// 	t_node	*start;
// 	t_node	*end;
// }			t_extrems;

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
void	print_left2right(t_node **tail, t_node **head);
void	add_begin(t_node **tail, int value);
t_node	*init_list(t_node **tail, t_node **head, int value);
void	deallocate_list(t_node **tail);
void	rm_node(t_node *node, t_node **tail);
void	add_end(t_node **tail, int value);
int		count_node(t_node **tail);
//Algo
void	init_index(t_node **tail, int *sorted_array, int len);
t_node	*find_highest(t_node **tail);
t_node	*find_lowest(t_node **tail);
void	tiny_sort(t_node **tail);
int		sort_checker(t_node **tail);
void	p2b(t_node **tail_a, t_node **tail_b);
void	current_position(t_node **tail);
void	find_target_pos(t_node **t_a, t_node **t_b);
void	travel_costs(t_node **tail_a, t_node **tail_b);
void	find_cheapest(t_node **tail_a, t_node **tail_b);
int		target_value(t_node *a, int i);
void	shifter(t_node **tail_a);
void	out_put_a(t_node *a);
void	rot_stack_a(t_node **tail, int *cost);
void	rot_stack_b(t_node **tail, int *cost);
void	do_cheapest_moves(t_node **tail_a, t_node **tail_b, t_node *cheapest);
int		absoluter(int number);
//Operation
void	sa(t_node **tail, int flag);
void	sb(t_node **tail, int flag);
void	ss(t_node **tail_a, t_node **tail_b);
void	pb(t_node **tail_a, t_node **tail_b, int flag);
void	pa(t_node **tail_a, t_node **tail_b, int flag);
void	ra(t_node **tail, int flag);
void	rb(t_node **tail, int flag);
void	rr(t_node **tail_a, t_node **tail_b);
void	rra(t_node **tail, int flag);
void	rrb(t_node **tail, int flag);
void	rrr(t_node **tail_a, t_node **tail_b);
//Utils Debug

#endif
