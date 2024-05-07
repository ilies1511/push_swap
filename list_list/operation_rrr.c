/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 04:27:59 by iziane            #+#    #+#             */
/*   Updated: 2024/05/07 04:30:43 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_node **tail_a, t_node **tail_b, t_node **head_a, t_node **head_b)
{
	rra_or_rrb(tail_a, head_a);
	rra_or_rrb(tail_b, head_b);
}
