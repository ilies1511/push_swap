/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:17:46 by iziane            #+#    #+#             */
/*   Updated: 2024/05/23 02:15:19 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	shifter(t_node **tail_a)
{
	int		len;

	current_position(tail_a);
	len = count_node(tail_a);
	if (find_highest(tail_a)->pos > len / 2)
	{
		while (!sort_checker_bonus(tail_a))
			rra(tail_a, 1);
	}
	else
	{
		while (!sort_checker_bonus(tail_a))
			ra(tail_a, 1);
	}
}
