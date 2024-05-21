/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:04:10 by iziane            #+#    #+#             */
/*   Updated: 2024/05/21 14:36:49 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
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

void	list_manager(int *array, int amount_numbers, int *sorted_array)
{
	t_node	*tail_a;
	t_node	*tail_b;
	t_node	*head_a;
	t_node	*head_b;
	int		i;

	i = 0;
	tail_a = NULL;
	tail_b = NULL;
	head_a = NULL;
	head_b = NULL;
	(void)head_a;
	(void)head_b;
	while (i < amount_numbers)
		add_end(&tail_a, array[i++]);
	init_index(&tail_a, sorted_array, amount_numbers);
	if (sort_checker(&tail_a))
		exit (1);
	p2b(&tail_a, &tail_b);
	tiny_sort(&tail_a);
	izi_sort(&tail_a, &tail_b);
	deallocate_list(&tail_a);
	deallocate_list(&tail_b);
}
// void	list_manager(int *array, int amount_numbers, int *sorted_array)
// {
// 	t_node	*tail_a;
// 	t_node	*tail_b;
// 	t_node	*head_a;
// 	t_node	*head_b;
// 	int		i;
// 	t_node	*current;

// 	i = 0;
// 	tail_a = NULL;
// 	tail_b = NULL;
// 	head_a = NULL;
// 	head_b = NULL;
// 	(void)head_a;
// 	(void)head_b;
// 	while (i < amount_numbers)
// 	{
// 		add_begin(&tail_a, array[i]);
// 		i++;
// 	}
// 	// if (sort_checker(&tail_a, &head_a))
// 	// {
// 	// 	printf("sorted\n");
// 	// 	exit(0);
// 	// }
// 	init_index(&tail_a, sorted_array, amount_numbers);
// 	i = 0;
// 	current = tail_a;
// 	printf("Amount Nodes: %d\n", count_node(&tail_a));
// 	current_position(&tail_a);
// 	current_position(&tail_b);
// 	// sa(&tail_a, 1);
// 	// rra(&tail_a, 1);
// 	// rra(&tail_a, 1);
// 	// rrb(&tail_b, 1);
// 	// ra(&tail_a, 1);
// 	current = tail_a;
// 	printf("\nPrint array of stack a before p2b: \n");
// 	while (1 && tail_a)
// 	{
// 		printf("value: %d index: %d current pos: %d\n", current->x, current->index, current->pos);
// 		current = current->next;
// 		if (current == tail_a)
// 			break ;
// 	}
// 	p2b(&tail_a, &tail_b);
// 	pa(&tail_a, &tail_b);
// 	// pb(&tail_a, &tail_b);
// 	// pb(&tail_a, &tail_b);
// 	// pb(&tail_a, &tail_b);
// 	printf("\nPrint array of stack a: \n");
// 	current_position(&tail_a);
// 	current = tail_a;
// 	while (1 && tail_a)
// 	{
// 		printf("value: %d index: %d current pos: %d\n", current->x, current->index, current->pos);
// 		current = current->next;
// 		if (current == tail_a)
// 			break ;
// 	}
// 	current_position(&tail_b);
// 	printf("\nPrint array of stack b: \n");
// 	current = tail_b;
// 	while (1 && tail_b)
// 	{
// 		printf("value: %d index: %d current pos: %d\n", current->x, current->index, current->pos);
// 		current = current->next;
// 		if (current == tail_b)
// 			break ;
// 	}

// 	// pa(&tail_a, &tail_b);
// 	// printf("\nPrint array of stack a after pa: \n");
// 	// current = tail_a;
// 	// while (1 && tail_a)
// 	// {
// 	// 	printf("value: %d index: %d current pos: %d\n", current->x, current->index, current->pos);
// 	// 	current = current->next;
// 	// 	if (current == tail_a)
// 	// 		break ;
// 	// }
// 	current_position(&tail_a);
// 	current_position(&tail_b);
// 	find_target_pos(&tail_a, &tail_b);
// 	printf("\nPost Targe Position, stack B\n");
// 	current = tail_b;
// 	while (1 && tail_b)
// 	{
// 		printf("value: %d index: %d current pos: %d target_pos: %d\n", current->x, current->index, current->pos, current->target_pos);
// 		current = current->next;
// 		if (current == tail_b)
// 			break ;
// 	}
// 	// printf("\nPrint array of stack a: \n");
// 	// current = tail_a;
// 	// while (1 && tail_a)
// 	// {
// 	// 	printf("value: %d index: %d current pos: %d\n", current->x, current->index, current->pos);
// 	// 	current = current->next;
// 	// 	if (current == tail_a)
// 	// 		break ;
// 	// }
// }
