/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:04:10 by iziane            #+#    #+#             */
/*   Updated: 2024/05/07 04:48:36 by iziane           ###   ########.fr       */
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
	tail_b = NULL;
	head_b = NULL;
	// tail_a = init_list(&tail_a, &head_a, array[i]);
	// i = i + 1;
	while (i < amount_numbers)
		add_begin(&tail_a, &head_a, array[i++]);
	print_left2right(&tail_a, &head_b);
}
