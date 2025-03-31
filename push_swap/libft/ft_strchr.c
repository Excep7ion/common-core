/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:59:27 by meguetta          #+#    #+#             */
/*   Updated: 2024/11/21 16:09:49 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Renvoie un pointeur sur la 1ere occurance c dans la chaine s
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	char	*str = argv[1];
	int	c = ft_atoi(argv[2]);
	printf("%p ---->\n", ft_strchr(str, c));
	printf("%p ---->", strchr(str, c));
	return (0);
}*/
