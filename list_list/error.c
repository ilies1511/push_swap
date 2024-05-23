/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:47:46 by iziane            #+#    #+#             */
/*   Updated: 2024/05/22 23:16:32 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_space_checker(const char *str)
{
	int	counter;

	counter = 0;
	if (ft_strncmp(str, "", ft_strlen(str)))
		return (0);
	while (str && str[counter] && str[counter] != '\0')
	{
		if (str[counter] != ' ' || str[counter] != '\t')
			return (1);
		counter++;
	}
	return (0);
}

void	deallocate_list(t_node **tail)
{
	t_node	*current;
	int		i;
	int		len;

	if (!(*tail))
		return ;
	if (*tail == NULL)
		return ;
	len = count_node(tail);
	i = 0;
	current = *tail;
	while (i < len - 1)
	{
		current = current->next;
		free (current->prev);
		current->prev = NULL;
		i++;
	}
	free(current);
	*tail = NULL;
}

void	rm_node(t_node *node, t_node **tail)
{
	if (!(*tail))
		return ;
	else if (node == (*tail))
	{
		((*tail)->prev)->next = (*tail)->next;
		(*tail)->next->prev = ((*tail)->prev);
		*tail = node->next;
	}
	free(node);
	node = NULL;
}
// void	rm_node(t_node *node, t_node **tail, t_node **head)
// {
// 	if (!(*tail) || !(*head))
// 		return ;
// 	// if (node != *tail && node != *head)
// 	// {
// 	// 	node->prev->next = node->next;
// 	// 	node->next->prev = node->prev;
// 	// }
// 	else if (node == (*tail))
// 	{
// 		(*head)->next = node->next;
// 		node->next->prev = (*head);
// 		*tail = node->next;
// 	}
// 	// else if (node == (*head))
// 	// {
// 	// 	(*tail)->prev = (*head)->prev;
// 	// 	(*head)->prev = (*tail);
// 	// 	*head = (*head)->prev;
// 	// }
// 	free(node);
// 	node = NULL;
// }

// void	deallocate_list(t_node **tail, t_node **head)
// {
// 	t_node	*current;

// 	if (*tail == NULL || *head == NULL)
// 		return ;
// 	current = *tail;
// 	while (current != *head)
// 	{
// 		current = current->next;
// 		free (current->prev);
// 		current->prev = NULL;
// 	}
// 	free(current);
// 	*tail = NULL;
// 	*head = NULL;
// }
