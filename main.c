/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:05:19 by iziane            #+#    #+#             */
/*   Updated: 2024/05/04 23:06:10 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		amount_numbers;
	int		*array;
	long	int_checker;
	int		*sorted_array;
	char	**substring_case;
	int		k;
	int		j;
	int		flag;
	int		substring_words;

	if (argc <= 1)
		return (0);
	i = 1;
	flag = 0;
	substring_words = 0;
	// Counting Numbers even within substring
	while (argv && argv[i])
	{
		if (count_word(argv[i]) > 1)
		{
			substring_words = substring_words + count_word(argv[i]);
			flag++;
		}
		i++;
	}
	amount_numbers = (i - 1) - flag + substring_words;
	printf("Amount numbers: %d\n", amount_numbers);
	array = malloc(sizeof(int) * amount_numbers);
	if (!array)
	{
		printf("Allocation failed\n");
		return (0);
	}
	sorted_array = malloc(sizeof(int) * amount_numbers);
	if (!array)
	{
		printf("Allocation failed\n");
		return (0);
	}
	i = 0;
	k = 1;
	while (i < amount_numbers && argv[k])
	{
		j = 0;
		substring_words = count_word(argv[k]);
		if (substring_words > 1)
		{
			substring_case = ft_split(argv[k], ' ');
			while (substring_words--)
			{
				int_checker = ft_atoi(substring_case[j]);
				if (int_checker <= INT_MIN || int_checker >= INT_MAX)
				{
					printf("ERROR-->Input is not in the Range of Integer\n");
					free(array);
					array = NULL;
					return (1);
				}
				else
					array[i++] = ft_atoi(substring_case[j++]);
			}
		}
		else
		{
			int_checker = ft_atoi(argv[k]);
			if (int_checker <= INT_MIN || int_checker >= INT_MAX)
			{
				printf("ERROR-->Input is not in the Range of Integer\n");
				free(array);
				array = NULL;
				return (1);
			}
			else
				array[i++] = ft_atoi(argv[k]);
		}
		k++;
	}
	i = 0;
	printf("------------------------------------------------------\n");
	while (i < amount_numbers)
		printf("%d ", array[i++]);
	i = 0;
	printf("\n------------------------------------------------------\n");
	if (check_duplicates(array, amount_numbers) == 1)
	{
		printf("ERROR--> Duplicates found");
		free(array);
		array = NULL;
		return (1);
	}
	i = 0;
	while (i < amount_numbers)
	{
		sorted_array[i] = array[i];
		i++;
	}
	sort_array(sorted_array, amount_numbers);
	printf("------------------------------------------------------\n");
	i = 0;
	printf("Sorted array: ");
	while (i < amount_numbers)
		printf("%d ", sorted_array[i++]);
	printf("\n------------------------------------------------------\n");
	//Implementierung von Stack
	fill_list(array, amount_numbers);
}
