/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilies1511 <ilies1511@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 01:04:03 by iziane            #+#    #+#             */
/*   Updated: 2024/05/12 02:03:29 by ilies1511        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	p2b(t_node **tail_a, t_node **tail_b)
{
	int	len;

	if (!(*tail_a))
		return ;
	len = count_node(tail_a);
	while (len > 3)
	{
		pb(tail_a, tail_b);
		len--;
	}
}

void	find_target_pos(t_node **t_a, t_node **t_b)
{
	int		best_target_pos;
	int		delta_index;
	t_node	*current_b;
	t_node	*current_a;
	int		len_a;
	int		len_b;
	int		k;
	int		i;
	// int		var[5];

	if (!(*t_a) || !(*t_b))
		return ;
	len_a = count_node(t_a);
	len_b = count_node(t_b);
	current_b = *t_b;
	current_a = *t_a;
	if (current_a->index - current_b->index > 0)
		delta_index = current_a->index - current_b->index;
	else
		delta_index = 0;
	i = 0;
	while (i < len_b)
	{
		k = 0;
		if (current_a->index - current_b->index > 0)
			delta_index = current_a->index - current_b->index;
		while (k < len_a)
		{
			if (current_a->index - current_b->index > 0
				&& current_a->index - current_b->index < delta_index)
				best_target_pos = current_a->pos;
			current_a = current_a->next;
			k++;
		}
		current_b->target_pos = best_target_pos;
		current_b = current_b->next;
		i++;
	}
	// while (i < len_b)
	// {
	// 	current_b = current_b->next;
	// 	i++;
	// }
}
// void	find_target_pos(t_node **t_a, t_node **h_a, t_node **t_b, t_node **h_b)
// {
// 	int		best_target_pos;
// 	int		delta_index;
// 	t_node	*current_b;
// 	t_node	*current_a;
// 	int		len_a;
// 	int		len_b;
// 	int		k;
// 	int		i;
// 	// int		var[5];

// 	len_a = count_node(t_a, h_a);
// 	len_b = count_node(t_b, h_b);
// 	current_b = *t_b;
// 	current_a = *t_a;
// 	// delta_index = current_a->index - current_b->index;
// 	i = 0;
// 	while (i < len_b)
// 	{
// 		k = 0;
// 		if (current_a->index - current_b->index > 0)
// 			delta_index = current_a->index - current_b->index;
// 		while (k < len_a)
// 		{
// 			if (current_a->index - current_b->index > 0
// 				&& current_a->index - current_b->index < delta_index)
// 				best_target_pos = current_a->pos;
// 			current_a = current_a->next;
// 			k++;
// 		}
// 		current_b->target_pos = best_target_pos;
// 		current_b = current_b->next;
// 		i++;
// 	}
// 	i = 0;
// 	len_b = count_node(t_b, h_b);
// 	while (i < len_b)
// 	{
// 		current_b = current_b->next;
// 		i++;
// 	}
// }
