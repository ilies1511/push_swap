/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 00:57:53 by iziane            #+#    #+#             */
/*   Updated: 2024/05/06 17:19:58 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node **tail_a)
{
	int	temp;

	if (!(*tail_a))
		return ;
	temp = (*tail_a)->x;
	(*tail_a)->x = (*tail_a)->next->x;
	(*tail_a)->next->x = temp;
}
