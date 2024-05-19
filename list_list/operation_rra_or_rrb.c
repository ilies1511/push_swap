/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rra_or_rrb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 04:13:32 by iziane            #+#    #+#             */
/*   Updated: 2024/05/19 06:40:28 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_node **tail, int flag)
{
	//  printf("\033[1;31m");

    // // Tu mensaje
    // printf("vor rra *********************************************************\n");

    // // Restablecer el color a predeterminado

	// printf("tail position is = %d ; tail  prev is = %d \n", (*tail)->pos, (*tail)->prev->pos);
	// printf("tail value is = %d ; tail  prev value is = %d \n", (*tail)->x, (*tail)->prev->x);
	// printf("*********************************************************\n");
    // printf("\033[0m");
	if (!(*tail))
		return ;
	// (*tail)->prev->next = (*tail);
	// (*tail)->prev->prev = (*tail)->prev->prev;
	// t_node *current = *tail;
	// // while(current && current->prev)
	// // {
	// // 	printf("current position is = %d ; current  prev is = %d \n", (current)->pos, (current)->prev->pos);
	// // printf("current value is = %d ; current  prev value is = %d \n", (current)->x, (current)->prev->x);
	// // current = current->prev;
	// // if (current == (*tail))
	// // {
	// // 	printf("tail ereicht \n");
	// // 	printf("fake teil position is = %d ; current  prev is = %d \n", (current)->pos, (current)->prev->pos);
	// // printf("faek teil value is = %d ; current  prev value is = %d \n", (current)->x, (current)->prev->x);
	// // 	break;
	// // }
	// // }
	// current = *tail;
	// while(current && current->next)
	// {
	// 	printf("current position is = %d ; current  prev is = %d \n", (current)->pos, (current)->prev->pos);
	// printf("current value is = %d ; current  prev value is = %d \n", (current)->x, (current)->prev->x);
	// current = current->next;
	// if (current == (*tail))
	// {
	// 	printf("tail ereicht \n");
	// 	printf("fake teil position is = %d ; current  prev is = %d \n", (current)->pos, (current)->prev->pos);
	// printf("faek teil value is = %d ; current  prev value is = %d \n", (current)->x, (current)->prev->x);
	// 	break;
	// }
	// }
	*tail = (*tail)->prev;
	if (flag == 1)
		write(1, "rra\n", 4);
	// 	printf("tail position is = %d ; tail  prev is = %d \n", (*tail)->pos, (*tail)->prev->pos);
	// printf("tail value is = %d ; tail  prev value is = %d \n", (*tail)->x, (*tail)->prev->x);
	current_position(&(*tail));
	//  printf("\033[1;31m");
	// printf("nach rra *********************************************************\n");
	// printf("tail position is = %d ; tail  prev is = %d \n", (*tail)->pos, (*tail)->prev->pos);
	// printf("tail value is = %d ; tail  prev value is = %d \n", (*tail)->x, (*tail)->prev->x);
	// printf("*********************************************************\n");
	//    printf("\033[0m");

}

void	rrb(t_node **tail, int flag)
{
	if (!(*tail))
		return ;
	*tail = (*tail)->prev;
	if (flag == 1)
		write(1, "rrb\n", 4);
	current_position(tail);
}
// void	rra(t_node **tail, t_node **head, int flag)
// {
// 	if (!(*tail) || !(*head))
// 		return ;
// 	*tail = (*head);
// 	*head = (*head)->prev;
// 	if (flag == 1)
// 		write(1, "rra\n", 4);
// }

// void	rrb(t_node **tail, t_node **head, int flag)
// {
// 	if (!(*tail) || !(*head))
// 		return ;
// 	*tail = (*head);
// 	*head = (*head)->prev;
// 	if (flag == 1)
// 		write(1, "rrb\n", 4);
// }
