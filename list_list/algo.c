/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 01:04:03 by iziane            #+#    #+#             */
/*   Updated: 2024/05/10 23:33:41 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	current_position(t_node **tail, t_node **head)
{
	t_node	*current;
	int		len;
	int		i;

	if (!(*tail) || !(*head))
		return ;
	i = 0;
	len = count_node(tail, head);
	current = *tail;
	while (i < len)
	{
		current->pos = i;
		current = current->next;
		i++;
	}
}

void	p2b(t_node **tail_a, t_node **head_a, t_node **tail_b, t_node **head_b)
{
	int	len;

	len = count_node(tail_a, head_a);
	while (len > 3)
	{
		pb(tail_a, tail_b, head_a, head_b);
		len--;
	}
}

void	find_target_pos(t_node **t_a, t_node **h_a, t_node **t_b, t_node **h_b)
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

	len_a = count_node(t_a, h_a);
	len_b = count_node(t_b, h_b);
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
