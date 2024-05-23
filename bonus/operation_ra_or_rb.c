/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ra_or_rb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:38:13 by iziane            #+#    #+#             */
/*   Updated: 2024/05/23 02:12:27 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

// void	ra(t_node **tail, t_node **head, int flag)
// {
// 	if (!(*tail) || !(*head))
// 		return ;
// 	*head = (*tail);
// 	*tail = (*tail)->next;
// 	if (flag == 1)
// 		write(1, "ra\n", 3);
// }

// void	rb(t_node **tail, t_node **head, int flag)
// {
// 	if (!(*tail) || !(*head))
// 		return ;
// 	*head = (*tail);
// 	*tail = (*tail)->next;
// 	if (flag == 1)
// 		write(1, "rb\n", 3);
// }
void	rb(t_node **tail, int flag)
{
	if (!(*tail))
		return ;
	*tail = (*tail)->next;
	if (flag == 1)
		write (1, "rb\n", 3);
	current_position(tail);
}

void	ra(t_node **tail, int flag)
{
	if (!(*tail))
		return ;
	*tail = (*tail)->next;
	if (flag == 1)
		write(1, "ra\n", 3);
	current_position(tail);
}
// void	ra(t_node **tail, t_node **head, int flag)
// {
// 	t_node	*temp;

// 	if (!(*tail) || !(*head))
// 		return ;
// 	temp = (*tail);
// 	rm_node((*tail), tail);
// 	add_end(tail, head, temp->x);
// 	if (flag == 1)
// 		write(1, "ra\n", 3);
// }
