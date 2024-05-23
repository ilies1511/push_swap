/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 03:57:52 by iziane            #+#    #+#             */
/*   Updated: 2024/05/23 02:12:27 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	rr(t_node **tail_a, t_node **tail_b)
{
	ra(tail_a, 0);
	rb(tail_b, 0);
	write(1, "rr\n", 3);
	current_position(tail_a);
	current_position(tail_b);
}
