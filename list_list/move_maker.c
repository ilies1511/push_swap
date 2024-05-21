/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:52:56 by iziane            #+#    #+#             */
/*   Updated: 2024/05/21 13:21:11 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rot_stack_a(t_node **tail, int *cost)
{
	if ((*cost) > 0)
	{
		while ((*cost)--)
			ra(tail, 1);
	}
	else
	{
		while ((*cost)++)
			rra(tail, 1);
	}
}

void	rot_stack_b(t_node **tail, int *cost)
{
	if ((*cost) > 0)
	{
		while ((*cost)--)
			rb(tail, 1);
	}
	else
	{
		while ((*cost)++)
			rrb(tail, 1);
	}
}

void	do_cheapest_moves(t_node **tail_a, t_node **tail_b, t_node *cheapest)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		rr(tail_a, tail_b);
		cheapest->cost_b--;
		cheapest->cost_a--;
	}
	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		rrr(tail_a, tail_b);
		cheapest->cost_a++;
		cheapest->cost_b++;
	}
	rot_stack_a(tail_a, &(cheapest->cost_a));
	rot_stack_b(tail_b, &(cheapest->cost_b));
	pa(tail_a, tail_b, 1);
}

int	absoluter(int number)
{
	if (number < 0)
		number = number * (-1);
	return (number);
}
