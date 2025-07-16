/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:07:13 by meguetta          #+#    #+#             */
/*   Updated: 2025/07/12 05:36:01 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Localiser la sous chaine dans la chaine dans les len caracteres
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	i = 0;
	j = 0;
	little_len = ft_strlen((char *)little) - 1;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && len > i)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && (i + j) < len)
			{
				if (j == little_len)
					return ((char *)big + (i));
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
//	char	*src = argv[1];
//	char	*find = argv[2];
//	size_t	len = atoi(argv[3]);

//	printf("%s\n", strnstr(src, find, len));
//	printf("%s", ft_strnstr(src, find, len));
//
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
//	char haystack[30] = "alors_tet";
//	char needle[10] = "test";
	printf("%s\n", strnstr(haystack, needle, -1));
	printf("%s", ft_strnstr(haystack, needle, -1));
	return (0);
}*/
