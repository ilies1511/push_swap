/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:47:36 by iziane            #+#    #+#             */
/*   Updated: 2024/05/23 02:30:22 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

// int	sort_checker_bonus(t_node **tail)
// {
// 	t_node	*current;
// 	int		len;
// 	int		i;

// 	if ((*tail)->next == (*tail))
// 		return (1);
// 	len = count_node(tail);
// 	current = (*tail);
// 	i = 0;
// 	while (i < len)
// 	{
// 		if (current->index > current->next->index)
// 			return (0);
// 		current = current->next;
// 		if (current->next == (*tail))
// 			break ;
// 		i++;
// 	}
// 	return (1);
// }

// void	check(t_node **tail_a, t_node **tail_b)
// {
// 	(void)tail_a;
// 	(void)tail_b;
// 	printf("IM here");
// }

int	main(int argc, char **argv)
{
	int	*array;
	int	*sorted_array;
	int	amount_words;

	if (argc == 2 && !ft_isdigit(ft_atoi(argv[1])))
	{
		write (2, "Error\n", 6);
		return (1);
	}
	if ((argc <= 1)
		|| ((argc == 2 && !ft_space_checker(argv[1]))))
		return (0);
	amount_words = number_counter(argv);
	parcer(argv, amount_words);
	array = make_array(&amount_words, argv);
	sorted_array = array_dub(array, amount_words);
	sort_array(sorted_array, amount_words);
	list_manager(array, amount_words, sorted_array, 0);
}
