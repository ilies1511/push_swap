/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrayz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:01:26 by iziane            #+#    #+#             */
/*   Updated: 2024/05/18 19:55:40 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*array_dub(int *array, int amount_numbers)
{
	int	*array_cpy;
	int	i;

	i = 0;
	array_cpy = malloc(sizeof(int) * amount_numbers);
	if (!array_cpy)
		exit (1);
	while (i < amount_numbers && array)
	{
		array_cpy[i] = array[i];
		i++;
	}
	return (array_cpy);
}

void	print_array(int *array, int amount_numbers)
{
	int	i;

	i = 0;
	while (i < amount_numbers && array)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}

int	*array_filler(int *amount_numbers, char **argv, int *array)
{
	int		i;
	int		k;
	int		substring_words;
	char	**substring_case;
	int		j;

	i = 0;
	k = 1;
	while (i < (*amount_numbers) && argv[k])
	{
		substring_words = count_word(argv[k]);
		if (substring_words == 0)
		{
			k++;
			(*amount_numbers)--;
			continue ;
		}
		if (substring_words > 1)
		{
			j = 0;
			substring_case = ft_split(argv[k], ' ');
			while (substring_words--)
				array[i++] = ft_atoi(substring_case[j++]);
		}
		else
			array[i++] = ft_atoi(argv[k]);
		k++;
	}
	return (array);
}

int	*make_array(int *amount_numbers, char **argv)
{
	int	*array;
	int	*sorted_array;

	array = malloc(sizeof(int) * (*amount_numbers));
	if (!array)
		exit(1);
	array = array_filler(amount_numbers, argv, array);
	if (check_duplicates(array, *amount_numbers) == 1)
	{
		write(2, "Error\n", 6);
		free (array);
		exit (1);
	}
	sorted_array = malloc(sizeof(int) * (*amount_numbers));
	if (!sorted_array)
	{
		free(array);
		exit (1);
	}
	// sorted_array = array_dub(array, *amount_numbers);
	// sort_array(sorted_array, *amount_numbers);
	// print_array(array, *amount_numbers);
	return (array);
}
