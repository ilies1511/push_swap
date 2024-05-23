/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go2algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:12:37 by iziane            #+#    #+#             */
/*   Updated: 2024/05/23 00:26:20 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	izi_sort(t_node **tail_a, t_node **tail_b)
{
	int		i;
	int		len_b;

	len_b = count_node(tail_b);
	i = 0;
	while (i < len_b)
	{
		current_position(tail_b);
		current_position(tail_a);
		find_target_pos(tail_a, tail_b);
		current_position(tail_b);
		current_position(tail_a);
		travel_costs(tail_a, tail_b);
		current_position(tail_b);
		current_position(tail_a);
		find_cheapest(tail_a, tail_b);
		current_position(tail_b);
		current_position(tail_a);
		i++;
	}
	if (!sort_checker(tail_a))
		shifter(tail_a);
}

void	go_2_algo(t_node *tail_a, t_node *tail_b)
{
	p2b(&tail_a, &tail_b);
	tiny_sort(&tail_a);
	izi_sort(&tail_a, &tail_b);
	deallocate_list(&tail_a);
	deallocate_list(&tail_b);
}
