/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rra_or_rrb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 04:13:32 by iziane            #+#    #+#             */
/*   Updated: 2024/05/21 15:52:54 by iziane           ###   ########.fr       */
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
	current_position(&(*tail));
}

void	rrb(t_node **tail, int flag)
{
	if (!(*tail))
		return ;
	*tail = (*tail)->prev;
	if (flag == 1)
		write(1, "rrb\n", 4);
	current_position(tail);
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

// void	rra(t_node **tail, int flag)
// {
// 	//  printf("\033[1;31m");
//     // printf("\033[0m");
