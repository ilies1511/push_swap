/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:10:20 by iziane            #+#    #+#             */
/*   Updated: 2024/05/21 21:28:18 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	number_counter(char **argv)
{
	int	i;
	int	substring_words;
	int	flag;

	i = 0;
	flag = 0;
	substring_words = 0;
	while (argv && argv[i])
	{
		if (count_word(argv[i]) > 1)
		{
			substring_words = substring_words + count_word(argv[i]);
			flag++;
		}
		i++;
	}
	return ((i - 1) - flag + substring_words);
}

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		write (1, &str[i++], 1);
}

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
			{
				write (1, "Error\n", 6);
				exit(1);
			}
			k++;
		}
		i++;
	}
	return (0);
}

int	count_word(const char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (!ft_strncmp(str, "", ft_strlen(str)))
		return (0);
	while (str && str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i])
		{
			i++;
			if (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
			{
				counter++;
				continue ;
			}
		}
	}
	return (counter);
}

void	sort_array(int *array, int len)
{
	int	temp;
	int	i;
	int	k;
	int	flag;

	i = 0;
	while (i < len)
	{
		flag = 1;
		k = 0;
		while (k < (len - 1 - i))
		{
			if (array[k] > array[k + 1])
			{
				temp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = temp;
				flag = 0;
			}
			k++;
		}
		if (flag == 1)
			return ;
		i++;
	}
}

// int	number_counter(char **argv)
// {
// 	int	i;
// 	int	substring_words;
// 	int	flag;

// 	i = 0;
// 	flag = 0;
// 	substring_words = 0;
// 	while (argv && argv[i])
// 	{
// 		// if (!ft_strncmp(argv[i], "", ft_strlen(argv[i])))
// 		// {
// 		// 	i++;
// 		// 	flag++;
// 		// 	continue ;
// 		// }
// 		if (count_word(argv[i]) > 1)
// 		{
// 			substring_words = substring_words + count_word(argv[i]);
// 			flag++;
// 		}
// 		i++;
// 	}
// 	return ((i - 1) - flag + substring_words);
// }
