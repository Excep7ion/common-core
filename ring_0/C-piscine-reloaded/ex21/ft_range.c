/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:01:58 by meguetta          #+#    #+#             */
/*   Updated: 2024/11/06 19:05:32 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*tab;

	i = 0;
	size = max - min;
	tab = malloc((sizeof(int)) * size);
	if (tab == NULL)
		return (NULL);
	if (min >= max)
		return (0);
	while (i < size)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	int	i;
	int	min;
	int	max;
	int	*t;

	(void)argc;
	i = 0;
	min = atoi(argv[1]);
	max = atoi(argv[2]);
	t = ft_range(min, max);
	while (i < max - min)
	{
		printf("%d", t[i]);
		printf("\n");
		i++;
	}
	return (0);
}
