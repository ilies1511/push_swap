/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:38:13 by iziane            #+#    #+#             */
/*   Updated: 2024/05/07 04:01:09 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra_or_rb(t_node **tail, t_node **head)
{
	if (!(*tail) || !(*head))
		return ;
	*head = (*tail);
	*tail = (*tail)->next;
}

// void	ra(t_node **tail, t_node **head)
// {

// 	t_node	*temp;

// 	if (!(*tail) || !(*head))
// 		return ;
// 	temp = (*tail);
// 	rm_node((*tail), tail, head);
// 	add_end(tail, head, temp->x);
// }
