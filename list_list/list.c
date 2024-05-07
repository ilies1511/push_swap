/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:04:10 by iziane            #+#    #+#             */
/*   Updated: 2024/05/07 03:45:04 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_left2right(t_node **tail, t_node **head)
{
	t_node	*current;

	if (*tail || *head)
	{
		current = *tail;
		while (current != *head && current != NULL)
		{
			printf("%d ", current->x);
			current = current->next;
		}
		printf("%d ", current->x);
	}
}

// void	print_left2right(t_node **tail, t_node **head)
// {
// 	t_node	*current;

// 	if (*tail && *head)
// 	{
// 		current = *tail;
// 		while (current)
// 		{
// 			if (current == (*head))
// 				break ;
// 			printf("%d ", current->x);
// 			current = current->next;
// 		}
// 		printf("%d\n", current->x);
// 		if ((*tail) == (*head))
// 			printf("%d ", current->x);
// 	}
// }

// void	print_left2right(t_node **tail, t_node **head)
// {
// 	t_node	*current;

// 	if (*tail && *head)
// 	{
// 		current = *tail;
// 		while (current != *head && current != NULL)
// 		{
// 			printf("%d ", current->x);
// 			current = current->next;
// 		}
// 		printf("%d\n", current->x);
// 		if ((*tail) == (*head))
// 			printf("%d ", current->x);
// 	}
// }

void	add_end(t_node **tail, t_node **head, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->x = value;
	new_node->next = (*tail);
	new_node->prev = (*head);
	(*head)->next = new_node;
	(*tail)->prev = new_node;
	*head = new_node;
}

// void	print_left2right(t_node **tail, t_node **head)
// {
// 	t_node	*current;

// 	current = *tail;
// 	if (*tail && (*tail)->next)
// 	{
// 		while (current != *head && current != NULL)
// 		{
// 			printf("nexts: %d; \t", current->next->x);
// 			printf("value: %d; \t", current->x);
// 			printf("prevs next: %d \n", current->prev->next->x);
// 			current = current->next;
// 		}
// 		current = current->next;
// 		printf("value: %d; \t", current->x);
// 	}
// 	else if ((*tail) == (*head))
// 		printf("%d ", current->x);
// }

// void	print_left2right(t_node **tail, t_node **head)
// {
// 	t_node	*current;

// 	current = *head;
// 	if (*head && (*head)->prev)
// 	{
// 		while (current != *tail && current != NULL)
// 		{
// 			// printf("nexts: %d; \t", current->next->x);
// 			printf("value: %d; \n", current->x);
// 			// printf("prevs next: %d \n", current->prev->next->x);
// 			current = current->prev;
// 		}
// 		current = current->prev;
// 		printf("value: %d; \t", current->x);
// 	}
// 	else if ((*tail) == (*head))
// 		printf("%d ", current->x);
// }
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
	// tail_a = init_list(&tail_a, &head_a, array[i]);
	// i = i + 1;
	while (i < amount_numbers)
		add_begin(&tail_a, &head_a, array[i++]);
	// printf("\nPost add_begin\n");
	// print_left2right(&tail_a, &head_a);
	// printf("\nPost add_begin\n");
	// ra(&tail_a, &head_a);
	printf("Test stack b pre\n");
	add_begin(&tail_b, &head_b, 99);
	printf("\nTest stack b ppst\n");
	print_left2right(&tail_b, &head_b);
}
