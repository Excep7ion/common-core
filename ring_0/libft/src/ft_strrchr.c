/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:14:22 by meguetta          #+#    #+#             */
/*   Updated: 2025/07/12 05:36:08 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Renvoie un pointeur sur la 1ere occurance c dans la chaine s
// en commencant par la fin de s
char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen((char *)s);
	while (len >= 0)
	{
		if (s[len] == (unsigned char)c)
			return ((char *)(s + len));
		len--;
	}
	return (NULL);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	char	*str = argv[1];
	char	c = argv[2][0];
	printf("%s\n", ft_strrchr(str, (int)c));
	printf("%s", strrchr(str, (int)c));
	return (0);
}*/
