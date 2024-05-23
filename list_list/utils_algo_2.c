/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:07:06 by iziane            #+#    #+#             */
/*   Updated: 2024/05/22 19:29:14 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_node(t_node **tail)
{
	t_node	*current;
	int		len;

	if (!(*tail))
		return (0);
	len = 0;
	current = *tail;
	while (current->next && current->next != *tail)
	{
		len++;
		current = current->next;
	}
	return (len + 1);
}

void	out_put_a(t_node *a)
{
	int	i;
	int	len;

	i = 0;
	len = count_node(&a);
	while (i < len)
	{
		printf("%i ", a->x);
		a = a->next;
		i++;
	}
	printf("\n");
}

int	target_value(t_node *a, int i)
{
	while (a->pos != i)
		a = a->next;
	return (a->index);
}

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
