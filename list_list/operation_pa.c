/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_pa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:41:10 by iziane            #+#    #+#             */
/*   Updated: 2024/05/06 17:54:58 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_node **tail_a, t_node **head_a, t_node **tail_b, t_node **head_b)
{
	if (!(*tail_b))
		return ;
	add_begin(tail_a, head_a, (*tail_b)->x);
	rm_node((*tail_b), tail_b, head_b);
}
