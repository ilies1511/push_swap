/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilies1511 <ilies1511@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 03:57:52 by iziane            #+#    #+#             */
/*   Updated: 2024/05/13 15:13:56 by ilies1511        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_node **tail_a, t_node **tail_b)
{
	ra(tail_a, 0);
	rb(tail_b, 0);
	write(1, "rr\n", 3);
}
