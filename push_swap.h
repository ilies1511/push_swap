/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:17:19 by iziane            #+#    #+#             */
/*   Updated: 2024/05/05 00:08:49 by iziane           ###   ########.fr       */
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
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

// Utils Parcing Input (Array)
int		count_word(const char *str);
void	sort_array(int *array, int len);
int		check_duplicates(int *array, int amount_numbers);
//Utils Linked List
void	fill_list(int *array, int amount_numbers);
void	print_left2right(t_node **tail, t_node **head);
void	add_begin(t_node **tail, t_node **head, int value);
t_node	*init_list(t_node **tail, t_node **head, int value);
void	deallocate_list(t_node **tail, t_node **head);
void	rm_node(t_node *node, t_node **tail, t_node **head);

#endif
