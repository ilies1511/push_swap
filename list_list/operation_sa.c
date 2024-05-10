/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 00:57:53 by iziane            #+#    #+#             */
/*   Updated: 2024/05/09 21:21:36 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node **tail, int flag)
{
	int	temp;

	if (!(*tail))
		return ;
	temp = (*tail)->x;
	(*tail)->x = (*tail)->next->x;
	(*tail)->next->x = temp;
	if (flag == 1)
		write(1, "sa\n", 3);
}
