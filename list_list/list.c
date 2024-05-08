/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:04:10 by iziane            #+#    #+#             */
/*   Updated: 2024/05/08 19:24:34 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_node_and_set_default_index(t_node **tail)
{
	t_node	*current;
	int		len;

	len = 0;
	current = *tail;
	while (1 && (*tail))
	{
		len++;
		current->index = -1;
		printf("\nIndex: %d\n", current->index);
		current = current->next;
		if (current->x == (*tail)->x)
			break ;
	}
	// printf("\nLen: %d\n", len);
	return (len);
}

void	init_index(t_node **tail)
{
	t_node	*start;
	t_node	*min;
	int		i;
	int		len;
	// int		len_cpy;

	start = *tail;
	len = count_node_and_set_default_index(tail);
	// len_cpy = len;
	i = 0;
	while (i < len)
	{
		min = start;
		while (min->index != -1)
			min = min->next;
		(*tail) = start->next;
		while (42)
		{
			if (start->x == (*tail)->x)
				break ;
			if ((*tail)->index != -1)
			{
				(*tail) = (*tail)->next;
				continue ;
			}
			if (min->x > (*tail)->x)
				min = (*tail);
			(*tail) = (*tail)->next;
		}
		min->index = i + 1;
		i++;
	}
	start = *tail;
	while (1)
	{
		printf("value: %d index: %d\n", start->x, start->index);
		start = start->next;
		if (start == (*tail))
			break ;
	}
}

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
		printf("%d ", current->x);
	}
}

void	list_manager(int *array, int amount_numbers)
{
	t_node	*tail_a;
	t_node	*tail_b;
	t_node	*head_a;
	t_node	*head_b;
	int		i;

	i = 0;
	tail_a = NULL;
	tail_b = NULL;
	head_a = NULL;
	head_b = NULL;
	// tail_a = init_list(&tail_a, &head_a, array[i]);
	// i = i + 1;
	// while (i < amount_numbers)
	// 	add_begin(&tail_a, &head_a, array[i++]);
	while (i < amount_numbers)
		add_end(&tail_a, &head_a, array[i++]);
	// print_left2right(&tail_a, &head_a);
	// print_left2right(&tail_b, &head_b);
	// init_index(tail_a);
	count_node_and_set_default_index(&tail_a);
	init_index(&tail_a);
}
