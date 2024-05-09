/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:04:10 by iziane            #+#    #+#             */
/*   Updated: 2024/05/09 16:11:03 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_index(t_node **tail, int *sorted_array, int len)
{
	int		i;
	t_node	*current;

	i = 0;
	current = *tail;
	while (i < len)
	{
		current = *tail;
		while (1)
		{
			if (sorted_array[i] == current->x && current->index == -1)
				break ;
			else
				current = current->next;
		}
		current->index = i + 1;
		i++;
	}
	i = 0;
}
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
	return (len);
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

void	list_manager(int *array, int amount_numbers, int *sorted_array)
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
	// init_index(&tail_a);
	init_index(&tail_a, sorted_array, amount_numbers);
}
