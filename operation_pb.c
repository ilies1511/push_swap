/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_pb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 01:21:36 by iziane            #+#    #+#             */
/*   Updated: 2024/05/05 01:53:34 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **tail_a, t_node **tail_b, t_node **head_a, t_node **head_b)
{
	int	temp;
	int	flag;

	flag = 0;
	temp = (*tail_a)->x;
	// if (*tail_b == NULL || *head_b == NULL)
	// {
	// 	*tail_b = init_list(&(*tail_b), &(*head_b), temp);
	// 	flag = 1;
	// }
	rm_node((*tail_a), tail_a, head_a);
	// if (flag != 1)
		add_begin(tail_b, head_b, temp);
}
