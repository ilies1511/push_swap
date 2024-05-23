/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 04:27:59 by iziane            #+#    #+#             */
/*   Updated: 2024/05/23 03:31:53 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	rrr(t_node **tail_a, t_node **tail_b)
{
	if (!(*tail_a) || !(*tail_b))
		return ;
	*tail_a = (*tail_a)->prev;
	*tail_b = (*tail_b)->prev;
}
