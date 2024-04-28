/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:05:19 by iziane            #+#    #+#             */
/*   Updated: 2024/04/28 20:58:44 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(int *array, int amount_numbers)
{
	int	i;
	int	k;

	i = 0;
	while (array && i < amount_numbers)
	{
		k = i + 1;
		while (k < amount_numbers)
		{
			if (array[i] == array[k])
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		amount_numbers;
	// long	number;
	// char	**postsplit;
	int		*array;
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
	// Counting Numbers even within substring
	while (argv && argv[i])
	{
		if (count_word(argv[i]) > 1)
		{
			i = i + count_word(argv[i]);
			flag++;
		}
		else
			i++;
	}
	amount_numbers = (i - 1) + flag;
	printf("Amount numbers: %d\n", amount_numbers);
	//Allocating memory for array to store the numbers of String into it
	array = malloc(sizeof(int) * amount_numbers);
	sorted_array = malloc(sizeof(int) * amount_numbers);
	//filling array with content of String
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
				array[i++] = ft_atoi(substring_case[j++]);
		}
		else
			array[i++] = ft_atoi(argv[k]);
		k++;
	}
	i = 0;
	while (i < amount_numbers)
		printf("%d ", array[i++]);
	return (0);
	// while (i < amount_numbers)
	// {
	// 	number = ft_atoi(postsplit[i++]);
	// 	if (number <= INT_MIN && number >= INT_MAX)
	// 	{
	// 		printf("ERROR: Input has to be an Int\n");
	// 		break ;
	// 	}
	// 	printf("%ld\n", number);
	// }
	i = 0;
	printf("------------------------------------------------------\n");
	//filling the array
	// while (i < amount_numbers)
	// {
	// 	array[i] = ft_atoi(postsplit[i]);
	// 	sorted_array[i] = array[i];
	// 	printf("%d ", array[i]);
	// 	i++;
	// }
	printf("\n");
	if (check_duplicates(array, amount_numbers) == 1)
	{
		printf("ERROR--> Duplicates found");
		return (1);
	}
	i = 1;
	sort_array(sorted_array, amount_numbers);
	i = 0;
	printf("Sorted array: ");
	while (i < amount_numbers)
		printf("%d ", sorted_array[i++]);
	//Implementierung von Stack
}
