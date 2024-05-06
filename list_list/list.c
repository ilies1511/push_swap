/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:04:10 by iziane            #+#    #+#             */
/*   Updated: 2024/05/06 17:19:50 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_left2right(t_node **tail, t_node **head)
{
	t_node	*current;

	if (*tail && *head)
	{
		current = *tail;
		while (current != *head && current != NULL)
		{
			printf("%d ", current->x);
			current = current->next;
		}
		// printf("%d ", current->x);
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
	new_node->next = (*tail);
	new_node->prev = (*head);
	(*head)->next = new_node;
	(*tail)->prev = new_node;
	*tail = new_node;
}

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

void	fill_list(int *array, int amount_numbers)
{
	t_node	*tail_a;
	t_node	*tail_b;
	t_node	*head_a;
	t_node	*head_b;
	int		i;

	i = 0;
	tail_a = NULL;
	tail_b = NULL;
	tail_b = NULL;
	head_b = NULL;
	tail_a = init_list(&tail_a, &head_a, array[i]);
	while (i < amount_numbers)
		add_begin(&tail_a, &head_a, array[i++]);
	print_left2right(&tail_a, &head_a);
	// sa(&tail_a);
	// printf("\nNach 'sa' Operation: \n");
	// print_left2right(&tail_a, &head_a);
	// sb(&tail_b);
	// printf("\nNach 'sb' Operation: \n");
	// print_left2right(&tail_b, &head_b);
	// pb(&tail_a, NULL, &head_a, NULL);
	// printf("\nNach 'pa' Operation: \n");
	// print_left2right(&tail_a, &head_a);
	ss(&tail_a, &tail_b);
	printf("\nNach 'ss' Operation: \n");
	printf("\nStack a\n");
	print_left2right(&tail_a, &head_a);
	printf("\nStack b\n");
	print_left2right(&tail_b, &head_a);
}
