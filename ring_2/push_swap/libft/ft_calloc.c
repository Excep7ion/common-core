/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:37:31 by meguetta          #+#    #+#             */
/*   Updated: 2024/11/26 08:43:51 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// alloue la memoire necessaire pour un tableau de de nmemb elements,
// cette zone est remplie de '0'
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*tab;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tab = malloc(nmemb * size);
	if (tab == NULL)
		return (NULL);
	while (i < (nmemb * size))
	{
		((char *)tab)[i] = 0;
		i++;
	}
	return (tab);
}
/*
int	main(int argc, char **argv)
{
	if (argc < 2)
		return 0;
	size_t	i;
	size_t	nmemb = ft_atoi(argv[1]);
	size_t	size = ft_atoi(argv[2]);
	char	*tab;

	tab = ft_calloc(nmemb, size);
	i = 0;

	while (i < nmemb)
	{
		printf("%p ----> %d\n", tab, tab[i]);
		i++;
	}
	return (0);
}*/
