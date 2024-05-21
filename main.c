/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:45:32 by iziane            #+#    #+#             */
/*   Updated: 2024/05/22 00:29:40 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void foo()
{
	system("leaks push_swap");
}

int	ft_space_checker(const char *str)
{
	int	counter;

	counter = 0;
	if (ft_strncmp(str, "", ft_strlen(str)))
	{
		return 0;
	}

	while (str && str[counter] && str[counter] != '\0')
	{
		if (str[counter] != ' ' || str[counter] != '\t')
			return (1);
		counter++;
	}
	return (0);
}

	// Fuer System- leaks atexit(foo);
int	main(int argc, char **argv)
{
	int	*array;
	int	*sorted_array;
	int	amount_words;

	if ((argc <= 1)
		|| (argc == 2 && !ft_space_checker(argv[1])))
		return (1);
	amount_words = number_counter(argv);
	parcer(argv, amount_words);
	array = make_array(&amount_words, argv);
	sorted_array = array_dub(array, amount_words);
	sort_array(sorted_array, amount_words);
	list_manager(array, amount_words, sorted_array);
	free(array);
	free(sorted_array);
	array = NULL;
	sorted_array = NULL;
	return (0);
}

// int	main(void)
// {
// 	char	*test;

// 	test = malloc(1);
// 	(void)test;
// 	test = NULL;
// 	// free(test);
// }

// ft_strncmp(argv[1], "", ft_strlen(argv[1])))))
