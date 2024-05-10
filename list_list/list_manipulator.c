/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 04:41:57 by iziane            #+#    #+#             */
/*   Updated: 2024/05/09 18:25:13 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*init_list(t_node **tail, t_node **head, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		deallocate_list(tail, head);
		exit (1);
	}
	new_node->x = value;
	new_node->next = new_node;
	new_node->prev = new_node;
	*tail = new_node;
	*head = new_node;
	return (*tail);
}

void	add_end(t_node **tail, t_node **head, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->x = value;
	if (!(*tail) || !(*head))
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*tail = new_node;
		*head = new_node;
	}
	else
	{
		new_node->next = (*tail);
		new_node->prev = (*head);
		(*head)->next = new_node;
		(*tail)->prev = new_node;
		*head = new_node;
	}
}

void	add_begin(t_node **tail, t_node **head, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		deallocate_list(tail, head);
		exit (1);
	}
	new_node->x = value;
	if (!(*tail) || !(*head))
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*tail = new_node;
		*head = new_node;
	}
	else
	{
		new_node->next = (*tail);
		new_node->prev = (*head);
		(*head)->next = new_node;
		(*tail)->prev = new_node;
		*tail = new_node;
	}
}
