/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 01:04:03 by iziane            #+#    #+#             */
/*   Updated: 2024/05/21 13:37:01 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_cost(t_node *cheapest_node)
{
	if ((cheapest_node->cost_a >= 0 && cheapest_node->cost_b >= 0)
		|| (cheapest_node->cost_a < 0 && cheapest_node->cost_b < 0))
	{
		if (absoluter(cheapest_node->cost_a) > absoluter(cheapest_node->cost_b))
			return (absoluter(cheapest_node->cost_a));
		else
			return (absoluter(cheapest_node->cost_b));
	}
	else
		return (absoluter(cheapest_node->cost_a)
			+ absoluter(cheapest_node->cost_b));
}

void	find_cheapest(t_node **tail_a, t_node **tail_b)
{
	t_node	*current_b;
	int		cheapest;
	int		len_b;
	int		i;
	t_node	*cheapest_node;

	i = 0;
	len_b = count_node(tail_b);
	current_b = *tail_b;
	cheapest = INT_MAX;
	cheapest_node = current_b;
	while (i < len_b)
	{
		if (get_cost(current_b) < cheapest)
		{
			cheapest = get_cost(current_b);
			cheapest_node = current_b;
		}
		current_b = current_b->next;
		i++;
	}
	do_cheapest_moves(tail_a, tail_b, cheapest_node);
}

void	travel_costs(t_node **tail_a, t_node **tail_b)
{
	int		len_b;
	int		len_a;
	int		i;
	t_node	*current_b;

	len_b = count_node(tail_b);
	len_a = count_node(tail_a);
	i = 0;
	current_b = *tail_b;
	while (i < len_b)
	{
		current_b->cost_b = current_b->pos;
		if (current_b->pos > len_b / 2)
			current_b->cost_b = (len_b - current_b->pos) * (-1);
		current_b->cost_a = current_b->target_pos;
		if (current_b->target_pos >= len_a / 2)
			current_b->cost_a = (len_a - current_b->target_pos) * (-1);
		current_b = current_b->next;
		i++;
	}
}
// Call find_cheapest(tail_a, tail_b) nach travel_cost

void	helper_ftp(t_node *cur_a, t_node *cur_b, t_target *data, t_node **t_a)
{
	while (data->i < data->len_b)
	{
		data->k = 0;
		data->delta_index = INT_MAX;
		cur_a = *t_a;
		while (data->k < data->len_a)
		{
			if (cur_b->index < cur_a->index
				&& cur_a->index < data->delta_index)
			{
				cur_b->target_pos = cur_a->pos;
				data->delta_index = cur_a->index;
			}
			cur_a = cur_a->next;
			data->k++;
		}
		if (data->delta_index == INT_MAX)
			cur_b->target_pos = (find_lowest(&cur_a))->pos;
		data->i++;
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
// void	current_position(t_node **tail)
// {
// 	t_node	*current;
// 	int		len;
// 	int		i;

// 	if (!(*tail))
// 		return ;
// 	i = 0;
// 	len = count_node(tail);
// 	current = *tail;
// 	// while(current && current->next)
// 	// {
// 	// 	current->pos = i;
// 	// 	i++;
// 	// 	current = current->next;
// 	// 	if (current == *tail)
// 	// 		break;
// 	// }
// 	while (i < len)
// 	{
// 		//  printf("\033[1;33m");
// 		// printf("tail position is = %d ; tail  prev is
			//= %d \n", (*tail)->pos, (*tail)->prev->pos);
// 		// printf("tail value is = %d ; tail  prev value is = %d \n"
			//, (*tail)->x, (*tail)->prev->x);
// 		//  printf("\033[0m");
// 		current->pos = i;
// 		// 	printf("i = %d\n", i);
// 		// printf("current value = %d ; current position = %d \n"
		//, current->x, current->pos);
// 		current = current->next;
// 		i++;
// 	}
// }

//TODO: Working
// void	current_position(t_node **tail)
// {
// 	t_node	*current;
// 	int		len;
// 	int		i;

// 	if (!(*tail))
// 		return ;
// 	i = 0;
// 	len = count_node(tail);
// 	current = *tail;
// 	while (i < len)
// 	{
// 		current->pos = i;
// 		current = current->next;
// 		i++;
// 	}
// }

//TODO: Working
// void	p2b(t_node **tail_a, t_node **tail_b)
// {
// 	int		len;
// 	int		median;
// 	int		i;
// 	int		pushed;

// 	if (!(*tail_a))
// 		return ;
// 	len = count_node(tail_a);
// 	median = len / 2;
// 	i = 0;
// 	pushed = 0;
// 	while (i < len && len > 6)
// 	{
// 		if ((*tail_a)->index <= median)
// 		{
// 			pb(tail_a, tail_b, 1);
// 			pushed++;
// 		}
// 		else if (pushed < median)
// 			ra(tail_a, 1);
// 		i++;
// 	}
// 	len = count_node(tail_a);
// 	while (len-- > 3)
// 		pb(tail_a, tail_b, 1);
// }

// void	p2b(t_node **tail_a, t_node **tail_b)
// {
// 	int	len;

// 	if (!(*tail_a))
// 		return ;
// 	len = count_node(tail_a);
// 	while (len > 3)
// 	{
// 		pb(tail_a, tail_b);
// 		len--;
// 	}
// }

// int	find_cost_a(t_node *node_a)
// {
// 	int		len;
// 	int		middle_b;
// 	t_node	*current;
// 	int		flag;

// 	flag = 0;
// 	if (node_a->pos * 2 > len)
// 		node_a->cost_a = len - node_a->pos;
// 	else if (node_a->pos * 2 < len)
// 	{
// 		node_a->cost_a = node_a->pos;
// 		flag = 1;
// 	}
// 	return (flag);
// }

// int	find_cost_b(t_node *node_b)
// {
// 	int		len;
// 	int		middle_b;
// 	t_node	*current;
// 	int		flag;

// 	flag = 0;
// 	if (node_b->pos * 2 > len)
// 		node_b->cost_b = len - node_b->pos;
// 	else if (node_b->pos * 2 < len)
// 	{
// 		node_b->cost_b = node_b->pos;
// 		flag = 1;
// 	}
// 	return (flag);
// }

// //TODO:Bevore ich meinen Code saubergeamcht habe
// void	rot_stack_b(t_node **tail, int *cost)
// {
// 	if ((*cost) > 0)
// 	{
// 		while ((*cost)--)
// 			rb(tail, 1);
// 	}
// 	else
// 	{
// 		while ((*cost)++)
// 			rrb(tail, 1);
// 	}
// }

// Richtige Funktionsweise + HowTo debug
// void	rot_stack_a(t_node **tail, int *cost)
// {
// 	if ((*cost) > 0)
// 	{
// 		while ((*cost)--)
// 			ra(tail, 1);
// 	}
// 	else
// 	{
// 		while ((*cost)++)
// 		{
// 			rra(tail, 1);
// 		// 	ft_putstr_fd("Im here\n" ,2);
// 		// 	ft_putstr_fd("len a  / 2 = " ,2);
// 		// 	ft_putstr_fd(ft_itoa(count_node(tail) / 2) ,2);
// 		// 	ft_putstr_fd("\n" ,2);
// 		// 	ft_putstr_fd("index = " ,2);

// 		// 	ft_putstr_fd(ft_itoa((*tail)->index) ,2);
// 		// 	ft_putstr_fd("\n" ,2);
// 		}
// 	}
// }

// //TODO:Bevore ich meinen Code saubergeamcht habe
// void	rot_stack_a(t_node **tail, int *cost)
// {
// 	if ((*cost) > 0)
// 	{
// 		while ((*cost)--)
// 			ra(tail, 1);
// 	}
// 	else
// 	{
// 		while ((*cost)++)
// 			rra(tail, 1);
// 	}
// }

// void	do_cheapest_moves(t_node **tail_a, t_node **tail_b, t_node *cheapest)
// {
// 	t_node	*current_a;
// 	t_node	*current_b;

// 	current_a = *tail_a;
// 	current_a = *tail_b;
// 	while (cheapest->cost_a-- > 0 && cheapest->cost_b-- > 0)
// 		rr(tail_a, tail_b);
// 	while (cheapest->cost_a++ < 0 && cheapest->cost_b++ < 0)
// 		rrr(tail_a, tail_b);
// 	// if (cheapest->cost_a > 0)
// 	// {
// 	// 	while (cheapest->cost_a--)
// 	// 		ra(tail_a, 1);
// 	// }
// 	// else
// 	// {
// 	// 	while (cheapest->cost_a++)
// 	// 		rra(tail_a, 1);
// 	// }
// 	rot_stack(tail_a, cheapest->cost_a);
// 	rot_stack(tail_b, cheapest->cost_b);
// 	// if (cheapest->cost_b > 0)
// 	// {
// 	// 	while (cheapest->cost_b--)
// 	// 		rb(tail_b, 1);
// 	// }
// 	// else
// 	// 	while (cheapest->cost_b++)
// 	// 		rrb(tail_b, 1);
// 	pa(tail_a, tail_b);
// }

// //TODO: Befor ich Funktion aufgesplittet habe
// void	do_cheapest_moves(t_node **tail_a, t_node **tail_b, t_node *cheapest)
// {
// 	t_node	*current_a;
// 	t_node	*current_b;

// 	current_a = *tail_a;
// 	current_b = *tail_b;
// 	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
// 	{
// 		rr(tail_a, tail_b);
// 		cheapest->cost_b--;
// 		cheapest->cost_a--;
// 	}
// 	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
// 	{
// 		rrr(tail_a, tail_b);
// 		cheapest->cost_a++;
// 		cheapest->cost_b++;
// 	}
// 	rot_stack_a(tail_a, &(cheapest->cost_a));
// 	rot_stack_b(tail_b, &(cheapest->cost_b));
// 	pa(tail_a, tail_b, 1);
// }

// // //TODO: Befor ich Funktion aufgesplittet habe
// int	absoluter(int number)
// {
// 	if (number < 0)
// 		number = number * (-1);
// 	return (number);
// }

// void	find_cheapest(t_node **tail_a, t_node **tail_b)
// {
// 	t_node	*current_b;
// 	int		cheapest;
// 	int		len_b;
// 	int		i;
// 	t_node	*cheapest_node;

// 	i = 0;
// 	len_b = count_node(tail_b);
// 	current_b = *tail_b;
// 	cheapest = INT_MAX;
// 	cheapest_node = current_b;
// 	while (i < len_b)
// 	{

// 		if ((absoluter(current_b->cost_a)
// 			+ absoluter(current_b->cost_b)) < cheapest)
// 		{
// cheapest = absoluter(current_b->cost_a) + absoluter(current_b->cost_b);
// 			cheapest_node = current_b;
// 			// sleep(5);
// 		}
// 		current_b = current_b->next;
// 		i++;
// 	}
// 			// exit(1);
// 	do_cheapest_moves(tail_a, tail_b, cheapest_node);
// }

//TODO: Funktion funktiniert, Debug Maßnahmen noch drin
// void	travel_costs(t_node **tail_a, t_node **tail_b)
// {
// 	int		len_b;
// 	int		len_a;
// 	int		i;
// 	t_node	*current_b;
// 	t_node	*current_a;

// 	current_position(tail_a);
// 	current_position(tail_b);
// 	len_b = count_node(tail_b);
// 	len_a = count_node(tail_a);
// 	i = 0;
// 	current_a = *tail_a;
// 	current_b = *tail_b;
// 	while (i < len_b)
// 	{

// 		current_b->cost_b = current_b->pos;
// 		if (current_b->pos > len_b / 2)
// 			current_b->cost_b = (len_b - current_b->pos) * (-1);
// 		current_b->cost_a = current_b->target_pos;
// 		if (current_b->target_pos >= len_a / 2)
// 			current_b->cost_a = (len_a - current_b->target_pos) * (-1);
// 		// ft_putstr_fd("len b = ", 2);
// 		// ft_putstr_fd(ft_itoa(len_b), 2);
// 		// ft_putstr_fd("\n", 2);
// 		// ft_putstr_fd("cost b = ", 2);
// 		// ft_putstr_fd(ft_itoa(current_b->cost_b), 2);
// 		// ft_putstr_fd("\n", 2);

// 	//  printf("\033[1;32m");
// 	//  printf("len a = %d\n", len_a);
// 		// ft_putstr_fd("len a = ", 2);
// 		// ft_putstr_fd(ft_itoa(len_a), 2);
// 		// ft_putstr_fd("\n", 2);
// 		//  printf("\033[0m");
// 		// ft_putstr_fd("cost a = ", 2);
// 		// ft_putstr_fd(ft_itoa(current_b->cost_a), 2);
// 		// ft_putstr_fd("\n", 2);
// 		current_b = current_b->next;
// 		i++;
// 	}
// 	// find_cheapest(tail_a, tail_b);

// void	travel_costs(t_node **tail_a, t_node **tail_b)
// {
// 	// int		cheapest;
// 	int		len_b;
// 	int		len_a;
// 	int		i;
// 	int		middle_a;
// 	int		middle_b;
// 	t_node	*current_b;
// 	t_node	*current_a;

// 	current_position(tail_a);
// 	current_position(tail_b);
// 	len_b = count_node(tail_b);
// 	len_a = count_node(tail_a);
// 	i = 0;
// 	current_a = *tail_a;
// 	current_b = *tail_b;
// 	while (i < len_b)
// 	{
// 		if (current_b->pos * 2 > len_b)
// 			current_b->cost_b = len_b - current_b->pos;
// 		else if (current_b->pos * 2 < len_b)
// 			current_b->cost_b = current_b->pos;
// 		//Now for b
// 		if (current_b->target_pos * 2 > len_b)
// 			current_b->cost_a = len_b - current_b->target_pos;
// 		else if (current_b->target_pos * 2 < len_b)
// 			current_b->cost_a = current_b->target_pos;
// 		if (current_b->cost_a < 0)
// 			current_b->cost_a = current_b->cost_a * (-1);
// 		if (current_b->cost_b < 0)
// 			current_b->cost_b = current_b->cost_b * (-1);
// 		cheapest = current_b->cost_a + current_b->cost_b;
// 	}
// }

//TODO: Working and Very Good version of that
// void helper_ftp(t_node *cur_a, t_node *cur_b, t_target *data, t_node **t_a)
// {
// 	t_a += 0;
// 	t_node	*max_node = find_highest(&cur_a);
// 	int		max = max_node->index;
// 	t_node	*min_node = find_lowest(&cur_a);
// 	int		min = min_node->index;

// 	int	i = 0;
// 	int	e = 0;

// 	while (e < data->len_b)
// 	{
// 		if (cur_b->index > max || cur_b->index < min)
// 		{
// 			cur_b->target_pos = min_node->pos;
// 			e++;
// 			cur_b = cur_b->next;
// 			continue ;
// 		}
// 		t_node *perfrect = max_node;
// 		i = 0;
// 		while (i < data->len_a)
// 		{
// 			if (cur_a->index < perfrect->index && cur_a->index > cur_b->index)
// 				perfrect = cur_a;
// 			cur_a = cur_a->next;
// 			i++;
// 		}
// 		cur_b->target_pos = perfrect->pos;
// 		e++;
// 		cur_b = cur_b->next;
// 	}

// }

//TODO: Workink function
// void	helper_ftp(t_node *cur_a, t_node *cur_b, t_target *data, t_node **t_a)
// {
// 	while (data->i < data->len_b)
// 	{
// 		data->k = 0;
// 		data->delta_index = INT_MAX;
// 		cur_a = *t_a;
// 		while (data->k < data->len_a)
// 		{
// 			if (cur_b->index < cur_a->index
// 				&& cur_a->index < data->delta_index)
// 			{
// 				// printf("index = %d\n", cur_a->index);
// 				// printf("pos = %d\n", cur_a->pos);
// 				cur_b->target_pos = cur_a->pos;
// 				cur_b->target_x = cur_a->x;
// 				cur_b->target_index = cur_a->index;
// 				data->delta_index = cur_a->index;
// 			}
// 			cur_a = cur_a->next;
// 			data->k++;
// 		}
// 		// printf("while loop endet\n");
// 		if (data->delta_index == INT_MAX)
// 		{
// 			cur_b->target_pos = (find_lowest(&cur_a))->pos;
// 			cur_b->target_index = (find_lowest(&cur_a))->index;

// 				cur_b->target_x = cur_a->x;
// 		}
// 		// printf("my target index = %d\n", 	cur_b->target_pos);
// 		// ft_putstr_fd("my target position = ", 2);
// 		// ft_putstr_fd(ft_itoa(cur_b->target_pos), 2);
// 		// ft_putstr_fd("\n", 2);
// 		data->i++;
// 		cur_b = cur_b->next;
// 	}
// }

//Stand 17.05.2024 21:05
// void	helper_ftp(t_node *cur_a, t_node *cur_b, t_target *data, t_node **t_a)
// {
// 	while (data->i < data->len_b)
// 	{
// 		data->k = 0;
// 		data->delta_index = INT_MAX;
// 		cur_a = *t_a;
// 		while (data->k < data->len_a)
// 		{
//// if (find_highest(&cur_b)->index > find_highest(t_a)->index) //|| cur_b->index < find_lowest(t_a)->index)
// 			// {
// 			// 	cur_b->target_pos = find_lowest(t_a)->pos;
// 			// 	break ;
// 			// }
// 			if (cur_a->index > cur_b->index
// 				&& cur_a->index - cur_b->index < data->delta_index)
// 			{
// 				cur_b->target_pos = cur_a->pos;
//data->delta_index = cur_a->index; //data->delta_index = cur_a->index - cur_b->index;
// 			}
// 			cur_a = cur_a->next;
// 			data->k++;
// 		}
// 		if (data->delta_index != INT_MAX)
// 			break ;
// 		data->k = 0;
// 		cur_a = *t_a;
// 		while (data->k < data->len_a)
// 		{
// 			if (cur_a->index < data->delta_index)
// 			{
// 				data->delta_index = cur_a->index;
// 				cur_b->target_pos = cur_a->pos;
// 			}
// 			cur_a = cur_a->next;
// 			data->k++;
// 		}
// 		data->i++;
// 		cur_b = cur_b->next;
// 	}
// }

// void	helper_ftp(t_node *cur_a, t_node *cur_b, t_target *data, t_node **t_a)
// {
// 	while (data->i++ < data->len_b)
// 	{
// 		data->k = 0;
// 		if (cur_a->index - cur_b->index >= 0)
// 			data->delta_index = cur_a->index - cur_b->index;
// 		cur_a = *t_a;
// 		while (data->k++ < data->len_a)
// 		{
// 			if (cur_b->index > find_highest(t_a)->index)
// 			{
// 				cur_b->target_pos = find_lowest(t_a)->pos;
// 				break ;
// 			}
// 			else if (cur_b->index < find_lowest(t_a)->index)
// 			{
// 				cur_b->target_pos = find_highest(t_a)->pos;
// 				break ;
// 			}
// 			else if (cur_a->index - cur_b->index >= 0
// 				&& cur_a->index - cur_b->index < data->delta_index)
// 				cur_b->target_pos = cur_a->pos;
// 			cur_a = cur_a->next;
// 		}
// 		cur_b = cur_b->next;
// 	}
// }

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
