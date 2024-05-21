/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_pb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 01:21:36 by iziane            #+#    #+#             */
/*   Updated: 2024/05/21 21:12:59 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	pb(t_node **tail_a, t_node **tail_b, int flag)
// {
// 	t_node	*node2push;
// 	t_node	*new_tail;
// 	t_node	*end_a;

// 	new_tail = malloc(sizeof(t_node));
// 	if (!new_tail)
// 		return ;
// 	if (!(*tail_a))
// 		return ;
// 	node2push = (*tail_a);
// 	if (node2push->next == node2push)
// 		(*tail_a) = NULL;
// 	else
// 	{
// 		end_a = (*tail_a)->prev;
// 		new_tail = (*tail_a)->next;
// 		new_tail->prev = node2push->prev;
// 		end_a->next = new_tail;
// 		*tail_a = new_tail;
// 	}
// 	if ((*tail_b) == NULL)
// 	{
// 		node2push->next = node2push;
// 		node2push->prev = node2push;
// 	}
// 	else
// 	{
// 		node2push->next = (*tail_b);
// 		node2push->prev = (*tail_b)->prev;
// 		(*tail_b)->prev->next = node2push;
// 		(*tail_b)->prev = node2push;
// 	}
// 	*tail_b = node2push;
// 	if (flag == 1)
// 		write(1, "pb\n", 3);
// 	current_position(tail_a);
// 	current_position(tail_b);
// 	// free(new_tail);
// }
// void	pb(t_node **tail_a, t_node **tail_b, int flag)
// {


// 	if (!(*tail_a)) // Verifica si la pila 'a' está vacía
//         return;

//     t_node *first_a = *tail_a;
//     t_node *second_a = (*tail_a)->next;
//     t_node *last_a = (*tail_a)->prev;
//     t_node *first_b = *tail_b;
//     t_node *last_b = (*tail_b)->prev;

//     int len_a = count_node(tail_a); // Supongo que count_node() cuenta los nodos correctamente

//     if (!first_b) // Si la pila 'b' está vacía
//     {
//         first_a->next = first_a;
//         first_a->prev = first_a;
//         *tail_b = first_a;
//     }
//     else
//     {
//         first_a->next = first_b;
//         first_a->prev = last_b;
//         last_b->next = first_a;
//         first_b->prev = first_a; // Agregué esta línea para corregir la conexión con el primer nodo de 'b'
//     }

//     // Actualiza el puntero 'tail_a'
//     if (len_a > 2)
//     {
//         second_a->prev = last_a;
//         last_a->next = second_a;
//         *tail_a = second_a;
//     }
//     else if (len_a == 2)
//     {
//         last_a->next = last_a;
//         last_a->prev = last_a;
//         *tail_a = last_a;
//     }
//     else
//     {
//         *tail_a = NULL;
//     }

// 	if (flag == 1)
// 		write(1, "pb\n", 3);
// 	current_position(tail_a);
// 	current_position(tail_b);
// 	// free(new_tail);
// }

void	pb(t_node **tail_a, t_node **tail_b, int flag)
{
	t_node	*node2push;
	t_node	*end_a;
	t_node	*new_tail;

	if (!(*tail_a))
		return ;
	node2push = (*tail_a);
	if (node2push->next == node2push)
		(*tail_a) = NULL;
	else
	{
		end_a = (*tail_a)->prev;
		new_tail = (*tail_a)->next;
		new_tail->prev = node2push->prev;
		end_a->next = new_tail;
		(*tail_a) = new_tail;
	}
	if (!(*tail_b))
	{
		node2push->next = node2push;
		node2push->prev = node2push;
	}
	else
	{
		node2push->next = (*tail_b);
		node2push->prev = (*tail_b)->prev;
		(*tail_b)->prev->next = node2push;
		(*tail_b)->prev = node2push;
	}
	(*tail_b) = node2push;
	if (flag == 1)
		write(1, "pb\n", 3);
	current_position(tail_a);
	current_position(tail_b);
}


// Bevor Muhammed Fehler gefunden hat

// void	pb(t_node **tail_a, t_node **tail_b)
// {
// 	t_node	*next_tail;
// 	t_node	*end_b;

// 	next_tail = (*tail_a)->next;
// 	if (!(*tail_a))
// 		return ;
// 	(*tail_a)->next->prev = (*tail_a)->prev;
// 	(*tail_a)->prev->next = next_tail;
// 	if (!(*tail_b))
// 	{
// 		*tail_b = (*tail_a);
// 		(*tail_a)->prev = (*tail_a);
// 		(*tail_a)->next = (*tail_a);
// 	}
// 	else
// 	{
// 		end_b = (*tail_b)->prev;
// 		(*tail_a)->next = (*tail_b);
// 		(*tail_a)->prev = end_b;
// 		end_b->next = (*tail_a);
// 		*tail_b = (*tail_a);
// 	}
// 	*tail_a = next_tail;
// 	write(1, "pb\n", 3);
// }



// Wokring but too many lines
// void	pb(t_node **tail_a, t_node **tail_b)
// {
// 	t_node	*next_tail;
// 	t_node	*end_b;

// 	next_tail = (*tail_a)->next;
// 	if (!(*tail_a))
// 		return ;
// 	if (!(*tail_b))
// 	{
// 		*tail_b = (*tail_a);
// 		(*tail_a)->next->prev = (*tail_a)->prev;
// 		(*tail_a)->prev->next = next_tail;
// 		(*tail_a)->prev = (*tail_a);
// 		(*tail_a)->next = (*tail_a);
// 	}
// 	else
// 	{
// 		end_b = (*tail_b)->prev;
// 		(*tail_a)->next->prev = (*tail_a)->prev;
// 		(*tail_a)->prev->next = next_tail;
// 		(*tail_a)->next = (*tail_b);
// 		(*tail_a)->prev = end_b;
// 		end_b->next = (*tail_a);
// 		*tail_b = (*tail_a);
// 	}
// 	*tail_a = next_tail;
// 	write(1, "pb\n", 3);
// }


//Dieser Block funktioniert wie er sollte‚
	// if (!(*tail_b))
	// {
	// 	*tail_b = (*tail_a);
	// 	(*tail_a)->next->prev = (*tail_a)->prev;
	// 	(*tail_a)->prev->next = next_tail;
	// 	(*tail_a)->prev = (*tail_a);
	// 	(*tail_a)->next = (*tail_a);
	// 	*tail_a = next_tail;
	// }
