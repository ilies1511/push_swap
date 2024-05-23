/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:24:38 by iziane            #+#    #+#             */
/*   Updated: 2024/05/23 02:12:27 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	ss(t_node **tail_a, t_node **tail_b)
{
	sa(tail_a, 0);
	sb(tail_b, 0);
	write(1, "ss\n", 3);
	current_position(tail_a);
	current_position(tail_b);
}
