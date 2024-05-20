/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:04:10 by iziane            #+#    #+#             */
/*   Updated: 2024/05/20 20:16:55 by iziane           ###   ########.fr       */
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
void	shifter(t_node **tail_a)
{
	int		len;
	int		i;

	current_position(tail_a);
	i = 0;
	len = count_node(tail_a);
	if (find_highest(tail_a)->pos > len / 2)
	{
		while (!sort_checker(tail_a))
			rra(tail_a, 1);
	}
	else
	{
		while (!sort_checker(tail_a))
			ra(tail_a, 1);
	}
}

int	count_node(t_node **tail)
{
	t_node	*current;
	int		len;

	if (!(*tail))
		return (0);
	len = 0;
	current = *tail;

		// printf("count node starts ************************************************************* \n");
	while (current->next && current->next != *tail)
	{
		// printf("tail position is = %d ; tail  prev is = %d \n", (*tail)->pos, (*tail)->prev->pos);
		// printf("tail value is = %d ; tail  prev value is = %d \n", (*tail)->x, (*tail)->prev->x);
		// printf("my position is = %d ; my  next is = %d \n", current->pos, current->next->pos);
		// printf("my value is = %d ; my  next value is = %d \n", current->x, current->next->x);
		len++;
		current = current->next;
		// if(!(current->next))
		// {
		// 	printf("there is no next \n");
		// }
		// if (current == *tail)
		// {
		// 	printf("tail erreicht\n");
		// 	printf("tail position is = %d ; tail  next is = %d \n", current->pos, current->next->pos);
		// printf("tail value is = %d ; tail  next value is = %d \n", current->x, current->next->x);
		// }
	}
	// while (current) //&& current->next)
	// {
	// 	len++;
	// 	current = current->next;
	// 	if (current == *tail)
	// 		break;

	// }
	return (len + 1);
}
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

void	print_left2right(t_node **tail, t_node **head)
{
	t_node	*current;

	current = *tail;
	if (!(*tail))
		return ;
	while (1)
	{
		printf("%d ", current->x);
		if (current == *head)
			break ;
		current = current->next;
	}
}

int target_value(t_node *a, int i)
{
	while(a->pos != i)
		a = a->next;
	return (a->index);
}
void	out_put_a(t_node *a)
{
	int	i;
	int	len;
	// while (i < 7)
	// {
	// 	printf("%i ", a->x);
	// 	a = a->next;
	// 	i++;
	// }
	// printf("\n");
	// while (a->pos != 0)
	// 	a = a->next;
	i = 0;
	len = count_node(&a);
	while (i < len)
	{
		// printf("value: %d index: %d current pos: %d target_pos: %d\n", a->x, a->index, a->pos, a->target_pos);
		printf("%i ", a->x);
		a = a->next;
		i++;
	}
	// printf("\n");
	printf("\n");
}

void	list_manager(int *array, int amount_numbers, int *sorted_array)
{
	t_node	*tail_a;
	t_node	*tail_b;
	t_node	*head_a;
	t_node	*head_b;
	int		i;
	// int		k;
	int		len_b;
	t_node	*current;

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
	{
		// printf("Im already sorted\n");
		exit (1);
	}
	p2b(&tail_a, &tail_b);
	current = tail_a;
	tiny_sort(&tail_a);
	len_b = count_node(&tail_b);
	i = 0;
	while (i < len_b)
	{

		current_position(&tail_b);
		current_position(&tail_a);
		find_target_pos(&tail_a, &tail_b);

		// ft_putstr_fd("my target position = ", 2);
		// ft_putstr_fd(ft_itoa(tail_b->target_pos), 2);
		// ft_putstr_fd("\n", 2);

		// ft_putstr_fd("len b au$er = ", 2);
		// ft_putstr_fd(ft_itoa(count_node(&tail_b)), 2);
		// ft_putstr_fd("\n", 2);

		// ft_putstr_fd("value tail a = ", 2);
		// ft_putstr_fd(ft_itoa((tail_a)->x), 2);
		// ft_putstr_fd("\n", 2);

		// ft_putstr_fd("len a au$er = ", 2);
		// ft_putstr_fd(ft_itoa(count_node(&tail_a)), 2);
		// ft_putstr_fd("\n", 2);
		// // printf("\nPrint array of stack b: \n");
		// current = tail_b;
		// k = 0;
		// while (k < len_b)
		// {
			// printf("value: %d index: %d current pos: %d target_pos: %d\n", current->x, current->index, current->pos, current->target_pos);
		// 	current = current->next;
		// 	k++;
		// }
		current_position(&tail_b);
		current_position(&tail_a);
		travel_costs(&tail_a, &tail_b);
		current_position(&tail_b);
		current_position(&tail_a);
		find_cheapest(&tail_a, &tail_b);
		current_position(&tail_b);
		current_position(&tail_a);
		// current_position(&tail_a);
		// current_position(&tail_b);
		// out_put_a(tail_a);
		// out_put_a(tail_b);
		i++;
	}
	if (!sort_checker(&tail_a))
	{
		shifter(&tail_a);
		// printf("Im Here\n");
	}
	// if (sort_checker(&tail_a))
	// {
	// 	printf("Im Sorted\n");
	// }
	// out_put_a(tail_a);
	// if (!sort_checker(&tail_a))
	// {
	// 	printf("\nEvertythin is sorted...\n");
	// 	return ;
	// }
	// deallocate_list(&tail_a,);
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
