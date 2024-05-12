/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_pa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilies1511 <ilies1511@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:41:10 by iziane            #+#    #+#             */
/*   Updated: 2024/05/13 01:21:58 by ilies1511        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_node **tail_a, t_node **tail_b)
{
	if (!(*tail_b))
		return ;
	add_begin(tail_a, (*tail_b)->x);
	rm_node((*tail_b), tail_b);
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
