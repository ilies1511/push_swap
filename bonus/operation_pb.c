/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_pb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 01:21:36 by iziane            #+#    #+#             */
/*   Updated: 2024/05/23 04:12:18 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

static void	check_destination(t_node **tail_b, t_node *node2push)
{
	if (!(*tail_b))
	{
		node2push->next = node2push;
		node2push->prev = node2push;
	}
	else
	{
		node2push->next = (*tail_b);
		node2push->prev = (*tail_b)->prev;
		(*tail_b)->prev->next = node2push;
		(*tail_b)->prev = node2push;
	}
}

void	pb(t_node **tail_a, t_node **tail_b, int flag)
{
	t_node	*node2push;
	t_node	*end_a;
	t_node	*new_tail;

	(void)flag;
	if (!(*tail_a))
		return ;
	node2push = (*tail_a);
	if (node2push->next == node2push)
		(*tail_a) = NULL;
	else
	{
		end_a = (*tail_a)->prev;
		new_tail = (*tail_a)->next;
		new_tail->prev = node2push->prev;
		end_a->next = new_tail;
		(*tail_a) = new_tail;
	}
	check_destination(tail_b, node2push);
	(*tail_b) = node2push;
}

// Bevor Muhammed Fehler gefunden hat

// void	pb(t_node **tail_a, t_node **tail_b)
// {
// 	t_node	*next_tail;
// 	t_node	*end_b;

// 	next_tail = (*tail_a)->next;
// 	if (!(*tail_a))
// 		return ;
// 	(*tail_a)->next->prev = (*tail_a)->prev;
// 	(*tail_a)->prev->next = next_tail;
// 	if (!(*tail_b))
// 	{
// 		*tail_b = (*tail_a);
// 		(*tail_a)->prev = (*tail_a);
// 		(*tail_a)->next = (*tail_a);
// 	}
// 	else
// 	{
// 		end_b = (*tail_b)->prev;
// 		(*tail_a)->next = (*tail_b);
// 		(*tail_a)->prev = end_b;
// 		end_b->next = (*tail_a);
// 		*tail_b = (*tail_a);
// 	}
// 	*tail_a = next_tail;
// 	write(1, "pb\n", 3);
// }

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
