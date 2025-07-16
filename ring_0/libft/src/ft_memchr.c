/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:19:08 by meguetta          #+#    #+#             */
/*   Updated: 2025/07/12 05:34:15 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Recherche un caractere dans une zone memoire
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		if (ptr[i] == (char)c)
			return ((char *)ptr + i);
		i++;
	}
	return (NULL);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
//	char	*str = argv[1];
//	char	c = argv[2][0];
//	size_t	n = ft_atoi(argv[3]);
	char	*str = "coucou";
	int	c = 2 + 256;
	size_t	n = 3;
	printf("%s\n", (char *)ft_memchr(str, c, n));
	printf("%s", (char *)memchr(str, c, n));
	return (0);
}*/
