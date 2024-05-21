/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substring_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 05:35:51 by iziane            #+#    #+#             */
/*   Updated: 2024/05/21 21:28:06 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	substring_case_function_preatoi(int words, char **argv, int *k)
{
	int		j;
	char	**substring_case;

	substring_case = ft_split(argv[*k], ' ');
	j = 0;
	while (words--)
	{
		if (pre_atoi(substring_case[j]) != 0)
		{
			write (1, "Error\n", 6);
			exit (1);
		}
		j++;
	}
	ft_free_2d(substring_case);
}

void	substring_case_function(int substring_words, char **argv, int *k)
{
	char	**substring_case;
	int		j;

	substring_case = ft_split(argv[*k], ' ');
	j = 0;
	while (substring_words--)
	{
		if (ft_atoi(substring_case[j]) <= INT_MIN
			|| ft_atoi(substring_case[j]) >= INT_MAX)
		{
			write (1, "Error\n", 6);
			exit (1);
		}
		j++;
	}
	ft_free_2d(substring_case);
}
