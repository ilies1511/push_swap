/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 01:49:07 by iziane            #+#    #+#             */
/*   Updated: 2024/05/23 02:06:03 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

int	sort_checker_bonus(t_node **tail)
{
	t_node	*current;
	int		len;
	int		i;

	if ((*tail)->next == (*tail))
		return (1);
	len = count_node(tail);
	current = (*tail);
	i = 0;
	while (i < len)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
		if (current->next == (*tail))
			break ;
		i++;
	}
	return (1);
}

static int	cmp_operations(char *line, t_node **tail_a, t_node **tail_b)
{
	if (!ft_strncmp(line, "sa", ft_strlen(line)))
		sa(tail_a, 0);
	else if (!ft_strncmp(line, "sa", ft_strlen(line)))
		sb(tail_b, 0);
	else if (!ft_strncmp(line, "sa", ft_strlen(line)))
		pa(tail_a, tail_b, 0);
	else if (!ft_strncmp(line, "sa", ft_strlen(line)))
		pb(tail_a, tail_b, 0);
	else if (!ft_strncmp(line, "sa", ft_strlen(line)))
		ss(tail_a, tail_b);
	else if (!ft_strncmp(line, "sa", ft_strlen(line)))
		ra(tail_a, 0);
	else if (!ft_strncmp(line, "sa", ft_strlen(line)))
		rb(tail_b, 0);
	else if (!ft_strncmp(line, "sa", ft_strlen(line)))
		rr(tail_a, tail_b);
	else if (!ft_strncmp(line, "sa", ft_strlen(line)))
		rra(tail_a, 0);
	else if (!ft_strncmp(line, "sa", ft_strlen(line)))
		rrb(tail_b, 0);
	else if (!ft_strncmp(line, "sa", ft_strlen(line)))
		rrr(tail_b, 0);
	else
		return (0);
	return (1);
}

int	reader(t_node	**tail_a, t_node **tail_b)
{
	char	*operation_line;

	while (1)
	{
		operation_line = get_next_line(0);
		if (!operation_line)
			break ;
		if (!cmp_operations(operation_line, tail_a, tail_b))
		{
			write (1, "Error\n", 6);
			free(operation_line);
			return (1);
		}
		else
			free(operation_line);
	}
	return (1);
}

void	check(t_node	**tail_a, t_node	**tail_b)
{
	if (reader(tail_a, tail_b))
	{
		if (sort_checker_bonus(tail_a))
			write (1, "OK\n", 3);
		else
			write (1, "KO\n", 3);
	}
}

void	list_manager(int *array, int amount_numbers, int *sorted_array, int e)
{
	t_node	*tail_a;
	t_node	*tail_b;
	int		i;

	i = 0;
	tail_a = NULL;
	tail_b = NULL;
	while (i < amount_numbers)
		add_end(&tail_a, array[i++]);
	init_index(&tail_a, sorted_array, amount_numbers);
	if (sort_checker_bonus(&tail_a))
	{
		deallocate_list(&tail_a);
		free(array);
		free(sorted_array);
		exit (0);
	}
	if (e == 0)
		check(&tail_a, &tail_b);
}