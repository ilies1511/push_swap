/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 03:57:52 by iziane            #+#    #+#             */
/*   Updated: 2024/05/07 04:01:47 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_node **tail_a, t_node **tail_b, t_node **head_a, t_node **head_b)
{
	ra_or_rb(tail_a, head_a);
	ra_or_rb(tail_b, head_b);
}
