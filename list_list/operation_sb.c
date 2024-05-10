/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 01:14:22 by iziane            #+#    #+#             */
/*   Updated: 2024/05/09 21:21:23 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_node **tail_b, int flag)
{
	int	temp;

	if (*tail_b == NULL || (*tail_b)->next == NULL)
		return ;
	temp = (*tail_b)->x;
	(*tail_b)->x = (*tail_b)->next->x;
	(*tail_b)->next->x = temp;
	if (flag == 1)
		write(1, "sb\n", 3);
}
