/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rra_or_rrb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 04:13:32 by iziane            #+#    #+#             */
/*   Updated: 2024/05/09 21:22:05 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_node **tail, t_node **head, int flag)
{
	if (!(*tail) || !(*head))
		return ;
	*tail = (*head);
	*head = (*head)->prev;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_node **tail, t_node **head, int flag)
{
	if (!(*tail) || !(*head))
		return ;
	*tail = (*head);
	*head = (*head)->prev;
	if (flag == 1)
		write(1, "rrb\n", 4);
}
