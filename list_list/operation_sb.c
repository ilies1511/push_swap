/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 01:14:22 by iziane            #+#    #+#             */
/*   Updated: 2024/05/19 01:29:07 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_node **tail, int flag)
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
		rb(tail, 0);
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
		write(1, "sb\n", 3);
	current_position(tail);
}

// void	sb(t_node **tail, int flag)
// {
// 	t_node	*first;
// 	t_node	*second;
// 	int		len;

// 	if (!(*tail))
// 		return ;
// 	len = count_node(tail);
// 	if (len < 2)
// 		ra(tail, 0);
// 	else
// 	{
// 		first = (*tail);
// 		second = (*tail)->next;
// 		first->next = second->next;
// 		first->prev->next = second;
// 		second->prev = first;
// 		second->prev = first->prev;
// 		second->next = first;
// 		first->prev = second;
// 		*tail = second;
// 	}
// 	if (flag == 1)
// 		write(1, "sb\n", 3);
// }


// void	sb(t_node **tail_b, int flag)
// {
// 	int	temp;

// 	if (*tail_b == NULL || (*tail_b)->next == NULL)
// 		return ;
// 	temp = (*tail_b)->x;
// 	(*tail_b)->x = (*tail_b)->next->x;
// 	(*tail_b)->next->x = temp;
// 	if (flag == 1)
// 		write(1, "sb\n", 3);
// }
