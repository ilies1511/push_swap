/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:57:31 by iziane            #+#    #+#             */
/*   Updated: 2024/05/06 04:58:39 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			write (2, "Error\n", 6);
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
			write (2, "Error\n", 6);
			exit (1);
		}
		j++;
	}
	ft_free_2d(substring_case);
}

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
		else if (ft_atoi(argv[k]) <= INT_MIN || ft_atoi(argv[k]) >= INT_MAX)
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		k++;
		i++;
	}
}

// int	pre_atoi(char *str)
// {
// 	int	k;

// 	k = 0;
// 	if (str[0] == '-')
// 		k++;
// 	while (str && str[k])
// 	{
// 		if (!ft_isdigit(str[k]))
// 			return (1);
// 		k++;
// 	}
// 	return (0);
// }

int	pre_atoi(char *str)
{
	int	k;

	k = 0;
	if (str[0] == '-' && !str[k + 1])
	{
		write (2, "Error\n", 6);
		exit (1);
	}
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
		// if (substring_words == 0)
		// {
		// 	k++;
		// 	i++;
		// 	continue ;
		// }
		if (substring_words > 1)
			substring_case_function_preatoi(substring_words, argv, &k);
		else if (pre_atoi(argv[k]) != 0)
		{
			write (2, "Error\n", 6);
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
