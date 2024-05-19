/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_pa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:41:10 by iziane            #+#    #+#             */
/*   Updated: 2024/05/19 06:43:44 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_node **tail_a, t_node **tail_b, int flag)
{
	t_node	*node2push;
	t_node	*new_tail;
	t_node	*end_b;
	// printf("\033[1;34m");
	// int	len_before_pa = count_node(tail_a);

	// // printf("vor pa *********************************************************\n");
	// printf("tail position is = %d ; tail  prev is = %d \n", (*tail_a)->pos, (*tail_a)->prev->pos);
	// printf("tail value is = %d ; tail  prev value is = %d \n", (*tail_a)->x, (*tail_a)->prev->x);
	// // printf("*********************************************************\n");
	new_tail = malloc(sizeof(t_node));
	if (!new_tail)
		return ;
	if (!(*tail_b))
		return ;
	node2push = (*tail_b);
	if (node2push->next == node2push)
		(*tail_b) = NULL;
	else
	{
		end_b = (*tail_b)->prev;
		new_tail = (*tail_b)->next;
		new_tail->prev = node2push->prev;
		end_b->next = new_tail;
		*tail_b = new_tail;
	}
	if ((*tail_a) == NULL)
	{
		node2push->next = node2push;
		node2push->prev = node2push;
	}
	else
	{
		node2push->next = (*tail_a);
		node2push->prev = (*tail_a)->prev;
		(*tail_a)->prev->next = node2push;
		(*tail_a)->prev = node2push;
	}
	*tail_a = node2push;
	if (flag == 1)
		write(1, "pa\n", 3);
	current_position(tail_a);
	current_position(tail_b);

	// int	len_after_pa = count_node(tail_a);
	// printf("len_after_pa = %d\n", len_after_pa);
	// printf("\033[0m");
	// printf("nach pa *********************************************************\n");
	// printf("tail position is = %d ; tail  prev is = %d \n", (*tail_a)->pos, (*tail_a)->prev->pos);
	// printf("tail value is = %d ; tail  prev value is = %d \n", (*tail_a)->x, (*tail_a)->prev->x);
	// printf("*********************************************************************\n");
}


// void	pa(t_node **tail_a, t_node **tail_b)
// {
// 	t_node	*next_tail;
// 	t_node	*end_a;
// 	t_node	*end_b;
// 	t_node	*node2push;

// 	// printf("\nbefore\n");
// 	// out_put_a(*tail_a);
// 	int	t = 0;

// 	if (!(*tail_b))
// 		return ;
// 	if (*tail_b != (*tail_b)->next)
// 	{
// 		t = 1;
// 		end_b = (*tail_b)->prev;
// 		next_tail = (*tail_b)->next;
// 		(*tail_b)->next->prev = (*tail_b)->prev;
// 		end_b->next = next_tail;
// 	}
// 	else
// 		*tail_b = NULL;
// 	// if (!(*tail_a))
// 	// {
// 	// 	*tail_a = (*tail_b);
// 	// 	(*tail_b)->prev = (*tail_b);
// 	// 	(*tail_b)->next = (*tail_b);
// 	// }
// 	// else
// 	// {
// 		// end_a = (*tail_a)->prev;
// 		// (*tail_b)->next = (*tail_a);
// 		// (*tail_b)->prev = end_a;
// 		// end_a->next = (*tail_b);
// 		// *tail_a = (*tail_b);
// 	// }
// 	node2push = *tail_b;
// 	end_a = (*tail_a)->prev;
// 	end_a->next = node2push;
// 	node2push->next = *tail_a;
// 	node2push->prev = end_a;
// 	(*tail_a)->prev = node2push;
// 	if (t)
// 		*tail_b = next_tail;
// 	// printf("\nafter\n");
// 	// out_put_a(*tail_a);
// 	write(1, "pa\n", 3);
// }
// void	pa(t_node **tail_a, t_node **tail_b)
// {
// 	if (!(*tail_b))
// 		return ;
// 	add_begin(tail_a, (*tail_b)->x);
// 	rm_node((*tail_b), tail_b);
// 	write(1, "pa\n", 3);
// }
