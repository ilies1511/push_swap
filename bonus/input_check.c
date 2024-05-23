/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:57:31 by iziane            #+#    #+#             */
/*   Updated: 2024/05/23 02:12:27 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	int_range_check(char **argv, int amount_numbers)
{
	int		substring_words;
	int		k;
	int		i;

	i = 0;
	k = 1;
	while (i < amount_numbers && argv[k])
	{
		substring_words = count_word(argv[k]);
		if (substring_words == 0)
		{
			k++;
			i++;
			continue ;
		}
		if (substring_words > 1)
			substring_case_function(substring_words, argv, &k);
		else if (ft_atoi(argv[k]) < INT_MIN || ft_atoi(argv[k]) > INT_MAX)
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		k++;
		i++;
	}
}

int	pre_atoi(char *str)
{
	int	k;

	k = 0;
	if (str[0] == '-' && !str[k + 1])
		return (1);
	if (str[0] == '-' && str[k + 1])
		k++;
	while (str && str[k])
	{
		if (!ft_isdigit(str[k]))
			return (1);
		k++;
	}
	return (0);
}

void	central(int amount_numbers, char **argv)
{
	int		substring_words;
	int		k;
	int		i;

	i = 0;
	k = 1;
	while (i < amount_numbers && argv[k])
	{
		substring_words = count_word(argv[k]);
		if (substring_words > 1)
			substring_case_function_preatoi(substring_words, argv, &k);
		else if (pre_atoi(argv[k]) != 0)
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		i++;
		k++;
	}
}

void	parcer(char **argv, int amount_numbers)
{
	central(amount_numbers, argv);
	int_range_check(argv, amount_numbers);
}

// void	central(int amount_numbers, char **argv)
// {
// 	int		substring_words;
// 	int		k;
// 	int		i;

// 	i = 0;
// 	k = 1;
// 	while (i < amount_numbers && argv[k])
// 	{
// 		substring_words = count_word(argv[k]);
// 		// if (substring_words == 0)
// 		// {
// 		// 	k++;
// 		// 	i++;
// 		// 	continue ;
// 		// }
// 		if (substring_words > 1)
// 			substring_case_function_preatoi(substring_words, argv, &k);
// 		else if (pre_atoi(argv[k]) != 0)
// 		{
// 			write (2, "Error\n", 6);
// 			exit (1);
// 		}
// 		i++;
// 		k++;
// 	}
// }
