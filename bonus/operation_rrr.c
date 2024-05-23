/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 04:27:59 by iziane            #+#    #+#             */
/*   Updated: 2024/05/23 02:12:27 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	rrr(t_node **tail_a, t_node **tail_b)
{
	rra(tail_a, 0);
	rrb(tail_b, 0);
	write(1, "rrr\n", 4);
	current_position(tail_a);
	current_position(tail_b);
}
