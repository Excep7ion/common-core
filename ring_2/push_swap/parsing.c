/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:02:20 by meguetta          #+#    #+#             */
/*   Updated: 2025/04/01 06:40:18 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	parsing(int argc, char **argv)
{
	if (argc > 2)
	{
		if (check_if_digit(argv) == 1)
			return (1);
	}
	else
	{
		if (check_if_digit_2(argv) == 1)
			return (1);
	}
	if (check_overflow(argv, 0) == 1)
		return (1);
	return (0);
}

int	check_if_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' && argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9')
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_if_digit_2(char **argv)
{
	int	j;

	j = 0;
	while (argv[1][j])
	{
		if (argv[1][j + 1] == '-' && (argv[1][j] >= '0' && argv[1][j] <= '9'))
			return (1);
		if (argv[1][j] == '-' && (argv[1][j + 1] < '0' || argv[1][j + 1] > '9'))
			return (1);
		else if (argv[1][j] != '-' && ft_isdigit(argv[1][j]) == 0)
			return (1);
		j++;
	}
	return (0);
}
