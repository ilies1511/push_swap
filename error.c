/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:47:46 by iziane            #+#    #+#             */
/*   Updated: 2024/05/05 00:08:42 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rm_node(t_node *node, t_node **tail, t_node **head)
{
	if (node != *tail && node != *head)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	if (node == (*tail))
		*tail = node->next;
	else if (node == (*head))
		*head = node->prev;
	free(node);
	node = NULL;
}
