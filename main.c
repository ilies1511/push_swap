/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:45:32 by iziane            #+#    #+#             */
/*   Updated: 2024/05/06 16:04:32 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*array;
	int	*sorted_array;
	int	amount_words;

	if ((argc <= 1)
		|| ((argc == 2) && (!ft_strncmp(argv[1], "", ft_strlen(argv[1])))))
	{
		write (2, "Error\n", 6);
		return (1);
	}
	amount_words = number_counter(argv);
	parcer(argv, amount_words);
	array = make_array(&amount_words, argv);
	sorted_array = array_dub(array, amount_words);
	sort_array(sorted_array, amount_words);
	print_array(sorted_array, amount_words);
	fill_list(sorted_array, amount_words);
}

