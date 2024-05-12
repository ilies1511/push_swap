/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilies1511 <ilies1511@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:17:19 by iziane            #+#    #+#             */
/*   Updated: 2024/05/12 02:28:36 by ilies1511        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

// typedef struct s_extrems
// {
// 	t_node	*start;
// 	t_node	*end;
// }			t_extrems;

typedef struct s_node
{
	void			*content;
	int				x;
	int				target_pos;
	int				pos;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

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
void	deallocate_list(t_node **tail, t_node **head);
void	rm_node(t_node *node, t_node **tail);
void	add_end(t_node **tail, t_node **head, int value);
int		count_node(t_node **tail);
//Algo
void	init_index(t_node **tail, int *sorted_array, int len);
t_node	*find_highest(t_node **tail, int amount_numbers);
t_node	*find_lowest(t_node **tail, int amount_numbers);
void	tiny_sort(t_node **tail, t_node **head);
int		sort_checker(t_node **tail);
void	p2b(t_node **tail_a, t_node **tail_b);
void	current_position(t_node **tail);
void	find_target_pos(t_node **t_a, t_node **t_b);
//Operation
void	sa(t_node **tail, int flag);
void	sb(t_node **tail_b, int flag);
void	ss(t_node **tail_a, t_node **tail_b);
void	pb(t_node **tail_a, t_node **tail_b);
void	pa(t_node **tail_a, t_node **tail_b);
void	ra(t_node **tail, t_node **head, int flag);
void	rb(t_node **tail, t_node **head, int flag);
void	rr(t_node **tail_a, t_node **tail_b, t_node **head_a, t_node **head_b);
void	rra(t_node **tail, t_node **head, int flag);
void	rrb(t_node **tail, t_node **head, int flag);
void	rrr(t_node **tail_a, t_node **tail_b, t_node **head_a, t_node **head_b);

#endif
