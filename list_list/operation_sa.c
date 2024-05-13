/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilies1511 <ilies1511@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 00:57:53 by iziane            #+#    #+#             */
/*   Updated: 2024/05/13 17:41:06 by ilies1511        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node **tail, int flag)
{
	t_node	*first;
	t_node	*second;
	int		len;

	if (!(*tail))
		return ;
	len = count_node(tail);
	if (len < 2)
		return ;
	if (len == 2)
		ra(tail, 0);
	else
	{
		first = (*tail);
		second = (*tail)->next;
		first->next = second->next;
		first->prev->next = second;
		second->prev = first;
		second->prev = first->prev;
		second->next = first;
		first->prev = second;
		*tail = second;
	}
	if (flag == 1)
		write(1, "sa\n", 3);
}
// void	sa(t_node **tail, int flag)
// {
// 	t_node	*next_tail;
// 	// t_node	*next_next;

// 	next_tail = (*tail)->next;
// 	// next_next = (*tail)->next->next;
// 	if (!(*tail))
// 		return ;
// 	(*tail)->prev->next = (*tail)->next;
// 	(*tail)->next->next = (*tail);
// 	(*tail)->next->prev = (*tail)->prev;
// 	(*tail)->next = (*tail)->next->next;
// 	(*tail)->prev = (*tail)->next;
// 	*tail = next_tail;
// 	if (flag == 1)
// 		write(1, "sa\n", 3);
// }
// void	sa(t_node **tail, int flag)
// {
// 	int	temp;

// 	if (!(*tail))
// 		return ;
// 	temp = (*tail)->x;
// 	(*tail)->x = (*tail)->next->x;
// 	(*tail)->next->x = temp;
// 	if (flag == 1)
// 		write(1, "sa\n", 3);
// }
