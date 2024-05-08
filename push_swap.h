/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:17:19 by iziane            #+#    #+#             */
/*   Updated: 2024/05/08 19:04:49 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				x;
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
void	list_manager(int *array, int amount_numbers);
void	print_left2right(t_node **tail, t_node **head);
void	add_begin(t_node **tail, t_node **head, int value);
t_node	*init_list(t_node **tail, t_node **head, int value);
void	deallocate_list(t_node **tail, t_node **head);
void	rm_node(t_node *node, t_node **tail, t_node **head);
void	add_end(t_node **tail, t_node **head, int value);
void	init_index(t_node **tail);
int		count_node_and_set_default_index(t_node **tail);
//Operation
void	sa(t_node **tail);
void	sb(t_node **tail_b);
void	ss(t_node **tail_a, t_node **tail_b);
void	pb(t_node **tail_a, t_node **tail_b, t_node **head_a, t_node **head_b);
void	pa(t_node **tail_a, t_node **head_a, t_node **tail_b, t_node **head_b);
void	ra_or_rb(t_node **tail, t_node **head);
void	rr(t_node **tail_a, t_node **tail_b, t_node **head_a, t_node **head_b);
void	rra_or_rrb(t_node **tail, t_node **head);
void	rrr(t_node **tail_a, t_node **tail_b, t_node **head_a, t_node **head_b);
#endif
