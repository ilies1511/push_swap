/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:10:20 by iziane            #+#    #+#             */
/*   Updated: 2024/04/28 20:17:45 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	check_duplicates(int *array, int amount_numbers)
// {
// 	int	i;
// 	int	k;

// 	i = 0;
// 	while (array && i < amount_numbers)
// 	{
// 		k = i + 1;
// 		while (k < amount_numbers)
// 		{
// 			if (array[i] == array[k])
// 				return (1);
// 			k++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int	count_word(const char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str && str[i])
	{
		if ((str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			|| (str[i] != '\t' && (i == 0 || str[i - 1] == '\t')))
			counter++;
		i++;
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
