/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rra_or_rrb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 04:13:32 by iziane            #+#    #+#             */
/*   Updated: 2024/05/23 04:17:50 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	rra(t_node **tail)
{
	if (!(*tail))
		return ;
	*tail = (*tail)->prev;
}

void	rrb(t_node **tail)
{
	if (!(*tail))
		return ;
	*tail = (*tail)->prev;
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
