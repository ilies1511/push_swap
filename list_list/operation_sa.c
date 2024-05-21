/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 00:57:53 by iziane            #+#    #+#             */
/*   Updated: 2024/05/21 13:30:39 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//TODO: Working BackUp
// void	sa(t_node **tail, int flag)
// {
// 	t_node	*first;
// 	t_node	*second;
// 	t_node	*third;
// 	t_node	*last;
// 	int		len;

// 	if (!(*tail))
// 		return ;
// 	len = count_node(tail);
// 	if (len < 2)
// 		return ;
// 	if (len == 2)
// 	{
// 		ra(tail, 0);
// 		return ;
// 	}
// 	else
// 	{
// 		first = (*tail);
// 		second = (*tail)->next;
// 		third = (*tail)->next->next;
// 		last = (*tail)->prev;
// 		second->next = first;
// 		second->prev = last;
// 		first->prev = second;
// 		first->next = third;
// 		third->prev = first;
// 		last->next = second;
// 		*tail = second;
// 	}
// 	if (flag == 1)
// 		write(1, "sa\n", 3);
// 	current_position(tail);
// }

void	helper_swap(t_node **tail, t_swap *data)
{
	data->second->next = data->first;
	data->second->prev = data->last;
	data->first->prev = data->second;
	data->first->next = data->third;
	data->third->prev = data->first;
	data->last->next = data->second;
	*tail = data->second;
}

void	sa(t_node **tail, int flag)
{
	t_swap	*data;

	data = (t_swap *)malloc(sizeof(t_swap));
	if (!data)
		exit (1);
	if (!(*tail))
		return ;
	data->len = count_node(tail);
	data->first = (*tail);
	data->second = (*tail)->next;
	data->third = (*tail)->next->next;
	data->last = (*tail)->prev;
	if (data->len < 2)
		return ;
	if (data->len == 2)
	{
		ra(tail, 0);
		return ;
	}
	else
		helper_swap(tail, data);
	if (flag == 1)
		write(1, "sa\n", 3);
	current_position(tail);
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
