/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilies1511 <ilies1511@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:47:46 by iziane            #+#    #+#             */
/*   Updated: 2024/05/12 01:22:59 by ilies1511        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	deallocate_list(t_node **tail, t_node **head)
{
	t_node	*current;

	if (*tail == NULL || *head == NULL)
		return ;
	current = *tail;
	while (current != *head)
	{
		current = current->next;
		free (current->prev);
		current->prev = NULL;
	}
	free(current);
	*tail = NULL;
	*head = NULL;
}

void	rm_node(t_node *node, t_node **tail)
{
	if (!(*tail))
		return ;
	// if (node != *tail && node != *head)
	// {
	// 	node->prev->next = node->next;
	// 	node->next->prev = node->prev;
	// }
	else if (node == (*tail))
	{
		((*tail)->prev)->next = (*tail)->next;
		(*tail)->next->prev = ((*tail)->prev);
		*tail = node->next;
	}
	// else if (node == (*head))
	// {
	// 	(*tail)->prev = (*head)->prev;
	// 	(*head)->prev = (*tail);
	// 	*head = (*head)->prev;
	// }
	free(node);
	node = NULL;
}
// void	rm_node(t_node *node, t_node **tail, t_node **head)
// {
// 	if (!(*tail) || !(*head))
// 		return ;
// 	// if (node != *tail && node != *head)
// 	// {
// 	// 	node->prev->next = node->next;
// 	// 	node->next->prev = node->prev;
// 	// }
// 	else if (node == (*tail))
// 	{
// 		(*head)->next = node->next;
// 		node->next->prev = (*head);
// 		*tail = node->next;
// 	}
// 	// else if (node == (*head))
// 	// {
// 	// 	(*tail)->prev = (*head)->prev;
// 	// 	(*head)->prev = (*tail);
// 	// 	*head = (*head)->prev;
// 	// }
// 	free(node);
// 	node = NULL;
// }
