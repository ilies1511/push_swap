/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:04:10 by iziane            #+#    #+#             */
/*   Updated: 2024/05/11 18:21:28 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_node(t_node **tail, t_node **head)
{
	t_node	*current;
	int		len;

	if (!(*tail) || (!head))
		return (0);
	len = 0;
	current = *tail;
	while (current->next != *tail)
	{
		len++;
		current = current->next;
	}
	return (len + 1);
}

// int	count_node(t_node **tail, t_node **head)
// {
// 	t_node	*current;
// 	int		len;

// 	if (!(*tail) && (!head))
// 		return (0);
// 	len = 1;
// 	current = *tail;
// 	while (current != *head)
// 	{
// 		len++;
// 		current = current->next;
// 	}
// 	return (len);
// }

void	print_left2right(t_node **tail, t_node **head)
{
	t_node	*current;

	current = *tail;
	if (!(*tail))
		return ;
	while (1)
	{
		printf("%d ", current->x);
		if (current == *head)
			break ;
		current = current->next;
	}
}

void	list_manager(int *array, int amount_numbers, int *sorted_array)
{
	t_node	*tail_a;
	t_node	*tail_b;
	t_node	*head_a;
	t_node	*head_b;
	int		i;
	t_node	*current;

	i = 0;
	tail_a = NULL;
	tail_b = NULL;
	head_a = NULL;
	head_b = NULL;
	while (i < amount_numbers)
		add_begin(&tail_a, &head_a, array[i++]);
	// if (sort_checker(&tail_a, &head_a))
	// {
	// 	printf("sorted\n");
	// 	exit(0);
	// }
	init_index(&tail_a, sorted_array, amount_numbers);
	i = 0;
	current = tail_a;
	printf("Amount Nodes: %d\n", count_node(&tail_a, &head_a));
	current_position(&tail_a, &head_a);
	current_position(&tail_b, &head_b);
	p2b(&tail_a, &head_a, &tail_b, &head_b);
	// current = tail_b;
	// while (current->next != tail_b && current)
	// {
	// 	printf("value: %d index: %d current pos: %d\n", current->x, current->index, current->pos);
	// 	current = current->next;
	// 	i++;
	// }
	current = tail_a;
	while (current->next != tail_a)
	{
		printf("value: %d index: %d current pos: %d\n", current->x, current->index, current->pos);
		current = current->next;
	}
	printf("value: %d index: %d current pos: %d\n", current->x, current->index, current->pos);
	find_target_pos(&tail_a, &head_a, &tail_b, &head_b);
}

	// while (tail_b != head_b)
	// {
	// 	printf("value: %d index: %d target_pos(B->A): %d\n", tail_b->x, tail_b->index, tail_b->pos);
	// 	tail_b = tail_b->next;
	// }
	// while (tail_a != head_a)
	// {
	// 	printf("\nvalue: %d index: %d target_pos(B->A): %d\n", tail_a->x, tail_a->index, tail_a->pos);
	// 	tail_a = tail_a->next;
	// }

	//BABA Vorlage
	// while (current->next != tail_b)
	// {
	// 	printf("value: %d index: %d current pos: %d\n", current->x, current->index, current->pos);
	// 	current = current->next;
	// 	i++;
	// }
