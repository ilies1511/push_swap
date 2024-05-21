/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:06:43 by iziane            #+#    #+#             */
/*   Updated: 2024/05/21 13:24:06 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_checker(t_node **tail)
{
	t_node	*current;
	int		len;
	int		i;

	if ((*tail)->next == (*tail))
		return (1);
	len = count_node(tail);
	current = (*tail);
	i = 0;
	while (i < len)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
		if (current->next == (*tail))
			break ;
		i++;
	}
	return (1);
}

void	tiny_sort(t_node **tail)
{
	t_node	*current;
	t_node	*highest;

	if (!(*tail))
		return ;
	current = *tail;
	highest = find_highest(tail);
	if (highest == current)
		ra(tail, 1);
	else if (highest == current->next)
		rra(tail, 1);
	current = *tail;
	if ((*tail)->x > (*tail)->next->x)
		sa(tail, 1);
}

void	init_index(t_node **tail, int *sorted_array, int len)
{
	int		i;
	t_node	*current;

	i = 0;
	current = (*tail);
	while (i < len && (*tail))
	{
		current->index = -1;
		current = current->next;
		i++;
	}
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
		current->index = (i++) + 1;
	}
}

t_node	*find_highest(t_node **tail)
{
	t_node	*highest;
	t_node	*current;
	int		i;
	int		len;

	i = 0;
	len = count_node(tail);
	current = *tail;
	highest = *tail;
	while (i < len)
	{
		if (highest->x < current->x)
			highest = current;
		current = current->next;
		i++;
	}
	return (highest);
}

t_node	*find_lowest(t_node **tail)
{
	t_node	*current;
	t_node	*lowest;
	int		i;
	int		len;

	len = count_node(tail);
	i = 0;
	current = *tail;
	lowest = *tail;
	while (i < len)
	{
		if (current->x < lowest->x)
			lowest = current;
		current = current->next;
		i++;
	}
	return (lowest);
}
// t_node	*find_lowest(t_node **tail, int amount_numbers)
// {
// 	t_node	*current;
// 	t_node	*lowest;
// 	int		i;
// 	// int		len;

// 	// len = count_node(tail);
// 	i = 0;
// 	current = *tail;
// 	lowest = *tail;
// 	while (i < amount_numbers)
// 	{
// 		if (lowest->x > current->x)
// 			lowest = current;
// 		current = current->next;
// 		i++;
// 	}
// 	// printf("Check lowest node\nvalue:
	// %d index: %d\n", lowest->x, lowest->index);
// 	return (lowest);
// }

// t_node	*find_highest(t_node **tail, int amount_numbers)
// {
// 	t_node	*highest;
// 	t_node	*current;
// 	int		i;

// 	i = 0;
// 	current = *tail;
// 	highest = *tail;
// 	while (i < amount_numbers)
// 	{
// 		if (highest->x < current->x)
// 			highest = current;
// 		current = current->next;
// 		i++;
// 	}
// 	return (highest);
// }
