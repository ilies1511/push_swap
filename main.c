/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:05:19 by iziane            #+#    #+#             */
/*   Updated: 2024/04/27 15:40:58 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	char	*str;
	int		i;
	int		amount_numbers;
	long	number;
	char	**postsplit;
	int		*array;
	int		*new_array;

	i = 0;
	str = "-2147483648 9 8 7 6 5 4 3 2 1";
	amount_numbers = count_word(str);
	printf("Amount of numbers: %d\n", amount_numbers);
	postsplit = ft_split((const char *)str, ' ');
	i = 0;
	while (i < amount_numbers)
	{
		number = ft_atoi(postsplit[i++]);
		if (number <= INT_MIN && number >= INT_MAX)
		{
			printf("ERROR: Input has to be an Int\n");
			break ;
		}
		printf("%ld\n", number);
	}
	array = malloc(sizeof(int) * amount_numbers);
	new_array = malloc(sizeof(int) * amount_numbers);
	i = 0;
	printf("------------------------------------------------------\n");
	//filling the array
	while (i < amount_numbers)
	{
		array[i] = ft_atoi(postsplit[i]);
		new_array[i] = array[i];
		printf("%d ", array[i]);
		i++;
	}
	i = 0;
	printf("\n");
	sort_array(new_array, amount_numbers);
	i = 0;
	printf("Sorted array: ");
	while (i < amount_numbers)
		printf("%d ", new_array[i++]);
	//Implementierung von Stack
}
