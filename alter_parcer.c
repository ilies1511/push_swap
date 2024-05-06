/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alter_parcer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:05:19 by iziane            #+#    #+#             */
/*   Updated: 2024/05/06 04:37:38 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	number_counter(char **argv)
// {
// 	int	i;
// 	int	substring_words;
// 	int	flag;

// 	i = 1;
// 	flag = 0;
// 	substring_words = 0;
// 	while (argv && argv[i])
// 	{
// 		if (!ft_strncmp(argv[i], "", ft_strlen(argv[i])))
// 		{
// 			i++;
// 			continue ;
// 		}
// 		if (count_word(argv[i]) > 1)
// 		{
// 			substring_words = substring_words + count_word(argv[i]);
// 			flag++;
// 		}
// 		i++;
// 	}
// 	return ((i - 1) - flag + substring_words);
// }

// 	}
// 	return (0);
// }

// size_t len_2d(char **two_d)
// {
// 	int i;

// 	i = 0;
// 	while(two_d && two_d[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

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
	// ???		return_value;

	if (argc <= 1)
		return (1);
	// retrun_value = parsing(argc, argv);
	// if (return_value == x)
	// 	return(1);
	// build_stack(retrun_value);
	// push_swap();
	i = 1;
	flag = 0;
	substring_words = 0;
	// // Counting Numbers even within substring
	// while (argv && argv[i])
	// {
	// 	// char **return_splitt;
	// 	// int word_numb;
	// 	// int k = 0;
	// 	if (count_word(argv[i]) > 1)
	// 	{
	// 		substring_words = substring_words + count_word(argv[i]);
	// 		flag++;
	// 	}
	// 	// return_splitt = ft_split(argv[i] , ' ');
	// 	// word_numb = len_2d(return_splitt);
	// 	// while (k < word_numb)
	// 	// 	check_if_number(return_splitt);
	// 	// 	k++;
	// 	// printf("words of arg [%d] = %d\n",i, word_numb);
	// 	i++;
	// }
	// amount_numbers = (i - 1) - flag + substring_words;
	amount_numbers = number_counter(argv);
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
	// parcer(argv, amount_numbers);
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
