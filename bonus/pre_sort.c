/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:22:08 by iziane            #+#    #+#             */
/*   Updated: 2024/05/21 10:24:49 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	p2b(t_node **tail_a, t_node **tail_b)
{
	int		len;
	int		median;
	int		i;
	int		pushed;

	if (!(*tail_a))
		return ;
	len = count_node(tail_a);
	median = len / 2;
	i = 0;
	pushed = 0;
	while (i < len && len > 6)
	{
		if ((*tail_a)->index <= median)
		{
			pb(tail_a, tail_b, 1);
			pushed++;
		}
		else if (pushed < median)
			ra(tail_a, 1);
		i++;
	}
	len = count_node(tail_a);
	while (len-- > 3)
		pb(tail_a, tail_b, 1);
}

void	current_position(t_node **tail)
{
	t_node	*current;
	int		len;
	int		i;

	if (!(*tail))
		return ;
	i = 0;
	len = count_node(tail);
	current = *tail;
	while (i < len)
	{
		current->pos = i;
		current = current->next;
		i++;
	}
}
