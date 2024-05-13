/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_pa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilies1511 <ilies1511@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:41:10 by iziane            #+#    #+#             */
/*   Updated: 2024/05/13 01:46:53 by ilies1511        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_node **tail_a, t_node **tail_b)
{
	t_node	*next_tail;
	t_node	*end_a;

	next_tail = (*tail_b)->next;
	if (!(*tail_b))
		return ;
	(*tail_b)->next->prev = (*tail_b)->prev;
	(*tail_b)->prev->next = next_tail;
	if (!(*tail_a))
	{
		*tail_a = (*tail_b);
		(*tail_b)->prev = (*tail_b);
		(*tail_b)->next = (*tail_b);
	}
	else
	{
		end_a = (*tail_a)->prev;
		(*tail_b)->next = (*tail_a);
		(*tail_b)->prev = end_a;
		end_a->next = (*tail_b);
		*tail_a = (*tail_b);
	}
	*tail_b = next_tail;
	write(1, "pa\n", 3);
}
// void	pa(t_node **tail_a, t_node **tail_b)
// {
// 	if (!(*tail_b))
// 		return ;
// 	add_begin(tail_a, (*tail_b)->x);
// 	rm_node((*tail_b), tail_b);
// 	write(1, "pa\n", 3);
// }
