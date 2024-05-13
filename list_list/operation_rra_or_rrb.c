/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rra_or_rrb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilies1511 <ilies1511@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 04:13:32 by iziane            #+#    #+#             */
/*   Updated: 2024/05/13 16:57:33 by ilies1511        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_node **tail, int flag)
{
	if (!(*tail))
		return ;
	*tail = (*tail)->prev;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_node **tail, int flag)
{
	if (!(*tail))
		return ;
	*tail = (*tail)->prev;
	if (flag == 1)
		write(1, "rrb\n", 4);
}
// void	rra(t_node **tail, t_node **head, int flag)
// {
// 	if (!(*tail) || !(*head))
// 		return ;
// 	*tail = (*head);
// 	*head = (*head)->prev;
// 	if (flag == 1)
// 		write(1, "rra\n", 4);
// }

// void	rrb(t_node **tail, t_node **head, int flag)
// {
// 	if (!(*tail) || !(*head))
// 		return ;
// 	*tail = (*head);
// 	*head = (*head)->prev;
// 	if (flag == 1)
// 		write(1, "rrb\n", 4);
// }
