/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_pb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 01:21:36 by iziane            #+#    #+#             */
/*   Updated: 2024/05/10 23:53:05 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_node **tail_a, t_node **tail_b, t_node **head_a, t_node **head_b)
{
	if (!(*tail_a))
		return ;
	printf("tail_a %p \t\n", tail_a);
	printf("tail_b %p \t\n", tail_b);
	add_begin(tail_b, head_b, (*tail_a)->x); // tail, head, value
	rm_node((*tail_a), tail_a, head_a);
	write(1, "pb\n", 3);
}

// void	pb(t_node **tail_a, t_node **tail_b, t_node **head_a, t_node **head_b)
// {
// 	if (!(*tail_b))
// 		init_list(tail_b, head_b, (*tail_a)->x);
// 	else
// 		add_begin(tail_b, head_b, (*tail_a)->x);
// 	rm_node((*tail_a), tail_a, head_a);
// 	write(1, "pb\n", 3);
// }
