/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 03:57:52 by iziane            #+#    #+#             */
/*   Updated: 2024/05/09 21:24:37 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_node **tail_a, t_node **tail_b, t_node **head_a, t_node **head_b)
{
	ra(tail_a, head_a, 0);
	rb(tail_b, head_b, 0);
	write(1, "rr\n", 3);
}
