/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 01:04:03 by iziane            #+#    #+#             */
/*   Updated: 2024/05/14 02:06:06 by iziane           ###   ########.fr       */
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

void	helper_ftp(t_node *cur_a, t_node *cur_b, t_target *data, t_node **t_a)
{
	while (data->i++ < data->len_b)
	{
		data->k = 0;
		if (cur_a->index - cur_b->index >= 0)
			data->delta_index = cur_a->index - cur_b->index;
		cur_a = *t_a;
		while (data->k++ < data->len_a)
		{
			if (cur_b->index > find_highest(t_a)->index)
			{
				cur_b->target_pos = find_lowest(t_a)->pos;
				break ;
			}
			else if (cur_b->index < find_lowest(t_a)->index)
			{
				cur_b->target_pos = find_highest(t_a)->pos;
				break ;
			}
			else if (cur_a->index - cur_b->index >= 0
				&& cur_a->index - cur_b->index < data->delta_index)
				cur_b->target_pos = cur_a->pos;
			cur_a = cur_a->next;
		}
		cur_b = cur_b->next;
	}
}

void	find_target_pos(t_node **t_a, t_node **t_b)
{
	t_target	*data;
	t_node		*current_b;
	t_node		*current_a;

	if (!(*t_a) || !(*t_b))
		return ;
	data = (t_target *)malloc(sizeof(t_target));
	if (!data)
		exit (1);
	data->len_a = count_node(t_a);
	data->len_b = count_node(t_b);
	data->i = 0;
	current_b = *t_b;
	current_a = *t_a;
	helper_ftp(current_a, current_b, data, t_a);
}

//working function but no norm
// void	find_target_pos(t_node **t_a, t_node **t_b)
// {
// 	t_node	*current_b;
// 	t_node	*current_a;
// 	int		delta_index;
// 	int		len_a;
// 	int		len_b;
// 	int		k;
// 	int		i;
// 	// int		var[5];

// 	if (!(*t_a) || !(*t_b))
// 		return ;
// 	len_a = count_node(t_a);
// 	len_b = count_node(t_b);
// 	current_b = *t_b;
// 	current_a = *t_a;

// 	i = 0;
// 	while (i < len_b)
// 	{
// 		k = 0;
// 		if (current_a->index - current_b->index > 0)
// 			delta_index = current_a->index - current_b->index;
// 		current_a = *t_a;
// 		while (k < len_a)
// 		{
// 			if (current_b->index > find_highest(t_a)->index)
// 			{
// 				current_b->target_pos = find_lowest(t_a)->pos;
// 				break ;
// 			}
// 			else if (current_a->index - current_b->index > 0
// 				&& current_a->index - current_b->index < delta_index)
// 				current_b->target_pos = current_a->pos;
// 			current_a = current_a->next;
// 			k++;
// 		}
// 		current_b = current_b->next;
// 		i++;
// 	}
// }


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
