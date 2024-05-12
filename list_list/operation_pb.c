/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_pb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilies1511 <ilies1511@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 01:21:36 by iziane            #+#    #+#             */
/*   Updated: 2024/05/13 01:31:35 by ilies1511        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_node **tail_a, t_node **tail_b)
{
	t_node	*next_tail;
	t_node	*end_b;

	next_tail = (*tail_a)->next;
	if (!(*tail_a))
		return ;
	(*tail_a)->next->prev = (*tail_a)->prev;
	(*tail_a)->prev->next = next_tail;
	if (!(*tail_b))
	{
		*tail_b = (*tail_a);
		(*tail_a)->prev = (*tail_a);
		(*tail_a)->next = (*tail_a);
	}
	else
	{
		end_b = (*tail_b)->prev;
		(*tail_a)->next = (*tail_b);
		(*tail_a)->prev = end_b;
		end_b->next = (*tail_a);
		*tail_b = (*tail_a);
	}
	*tail_a = next_tail;
	write(1, "pb\n", 3);
}

// Wokring but too many lines
// void	pb(t_node **tail_a, t_node **tail_b)
// {
// 	t_node	*next_tail;
// 	t_node	*end_b;

// 	next_tail = (*tail_a)->next;
// 	if (!(*tail_a))
// 		return ;
// 	if (!(*tail_b))
// 	{
// 		*tail_b = (*tail_a);
// 		(*tail_a)->next->prev = (*tail_a)->prev;
// 		(*tail_a)->prev->next = next_tail;
// 		(*tail_a)->prev = (*tail_a);
// 		(*tail_a)->next = (*tail_a);
// 	}
// 	else
// 	{
// 		end_b = (*tail_b)->prev;
// 		(*tail_a)->next->prev = (*tail_a)->prev;
// 		(*tail_a)->prev->next = next_tail;
// 		(*tail_a)->next = (*tail_b);
// 		(*tail_a)->prev = end_b;
// 		end_b->next = (*tail_a);
// 		*tail_b = (*tail_a);
// 	}
// 	*tail_a = next_tail;
// 	write(1, "pb\n", 3);
// }


//Dieser Block funktioniert wie er sollte‚
	// if (!(*tail_b))
	// {
	// 	*tail_b = (*tail_a);
	// 	(*tail_a)->next->prev = (*tail_a)->prev;
	// 	(*tail_a)->prev->next = next_tail;
	// 	(*tail_a)->prev = (*tail_a);
	// 	(*tail_a)->next = (*tail_a);
	// 	*tail_a = next_tail;
	// }
