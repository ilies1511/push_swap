/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:04:10 by iziane            #+#    #+#             */
/*   Updated: 2024/05/23 04:10:56 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"
// Backup Stand: 17.05 00:35
// int	count_node(t_node **tail)
// {
// 	t_node	*current;
// 	int		len;

// 	if (!(*tail))
// 		return (0);
// 	len = 0;
// 	current = *tail;
// 	while (current->next != *tail)
// 	{
// 		len++;
// 		current = current->next;
// 	}
// 	return (len + 1);
// }

// int	count_node(t_node **tail)
// {
// 	t_node	*current;
// 	int		len;

// 	if (!(*tail))
// 		return (0);
// 	len = 0;
// 	current = *tail;
// 	while (current->next != *tail)
// 	{
// 		len++;
// 		current = current->next;
// 	}
// 	return (len + 1);
// }

//TODO:
// void	izi_sort(t_node **tail_a, t_node **tail_b)
// {
// 	int		i;
// 	int		len_b;

// 	len_b = count_node(tail_b);
// 	i = 0;
// 	while (i < len_b)
// 	{
// 		current_position(tail_b);
// 		current_position(tail_a);
// 		find_target_pos(tail_a, tail_b);
// 		current_position(tail_b);
// 		current_position(tail_a);
// 		travel_costs(tail_a, tail_b);
// 		current_position(tail_b);
// 		current_position(tail_a);
// 		find_cheapest(tail_a, tail_b);
// 		current_position(tail_b);
// 		current_position(tail_a);
// 		i++;
// 	}
// 	if (!sort_checker_bonus(tail_a))
// 		shifter(tail_a);
// }

void	list_manager(int *array, int amount_numbers, int *sorted_array)
{
	t_node	*tail_a;
	t_node	*tail_b;
	int		i;

	i = 0;
	tail_a = NULL;
	tail_b = NULL;
	while (i < amount_numbers)
		add_end(&tail_a, array[i++]);
	init_index(&tail_a, sorted_array, amount_numbers);
	if (sort_checker_bonus(&tail_a))
	{
		deallocate_list(&tail_a);
		free(array);
		free(sorted_array);
		exit (0);
	}
}
// void	list_manager(int *array, int amount_numbers, int *sorted_array)
// {
// 	t_node	*tail_a;
// 	t_node	*tail_b;
// 	int		i;

// 	i = 0;
// 	tail_a = NULL;
// 	tail_b = NULL;
// 	while (i < amount_numbers)
// 		add_end(&tail_a, array[i++]);
// 	init_index(&tail_a, sorted_array, amount_numbers);
// 	if (sort_checker(&tail_a))
// 	{
// 		deallocate_list(&tail_a);
// 		free(array);
// 		free(sorted_array);
// 		exit (0);
// 	}
// 	p2b(&tail_a, &tail_b);
// 	tiny_sort(&tail_a);
// 	izi_sort(&tail_a, &tail_b);
// 	deallocate_list(&tail_a);
// 	deallocate_list(&tail_b);
// }
