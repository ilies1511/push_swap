/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 00:57:53 by iziane            #+#    #+#             */
/*   Updated: 2024/05/19 06:38:26 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node **tail, int flag)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	t_node	*last;
	int		len;

	if (!(*tail))
		return ;
	len = count_node(tail);
	if (len < 2)
		return ;
	if (len == 2)
	{
		ra(tail, 0);
		return ;
	}
	else
	{
		// current = (*tail)->next;
		// current->prev = (*tail)->prev;
		// current->next = (*tail);
		// (*tail)->next = current->next;
		// (*tail)->prev = current;
		first = (*tail);
		second = (*tail)->next;
		third = (*tail)->next->next;
	 	last = (*tail)->prev;
		second->next = first;
		second->prev = last;
		first->prev = second;
		first->next = third;
		third->prev = first;
		last->next = second;
		// second->next = (*tail)->next->next;
		// second->prev = (*tail)->prev;
		// first->next = (*tail)->next->next;
		// first->prev = second;
		// (*tail)->next->next->prev = first;
		// (*tail)->next = second;
		// second->next->prev = first;
		// first->prev = second;
		*tail = second;
	}
	if (flag == 1)
		write(1, "sa\n", 3);
	current_position(tail);
	// printf("bach sa\n");
	// t_node *current = *tail;
	// while(current && current->prev)
	// {
	// // 	printf("current position is = %d ; current  prev is = %d \n", (current)->pos, (current)->prev->pos);
	// // printf("current value is = %d ; current  prev value is = %d \n", (current)->x, (current)->prev->x);
	// current = current->prev;
	// if (current == (*tail))
	// {
	// 	printf("tail ereicht \n");
	// 	printf("fake teil position is = %d ; current  prev is = %d \n", (current)->pos, (current)->prev->pos);
	// 	printf("faek teil value is = %d ; current  prev value is = %d \n", (current)->x, (current)->prev->x);
	// 	break;
	// }
	// }
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
