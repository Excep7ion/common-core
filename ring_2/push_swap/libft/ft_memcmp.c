/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:31:56 by meguetta          #+#    #+#             */
/*   Updated: 2024/11/21 16:23:07 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compare les n premiers octets des zones memoire de s1 et s2
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < n && ptr1[i] == ptr2[i])
		i++;
	if (i < n)
		return (ptr1[i] - ptr2[i]);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	char	*str = argv[1];
	char	*str1 = argv[2];
	size_t	n = atoi(argv[3]);
	printf("%d\n", ft_memcmp(str, str1, n));
	printf("%d", memcmp(str, str1, n));
	return (0);
}
int main(void)
{
	char s[] = {-128, 0, 127, 0};
//	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
//	char s3[] = {0, 0, 42, 0};
//	printf("%d\n", !ft_memcmp(s, sCpy, 4));
//	printf("%d\n", !ft_memcmp(s, s2, 0));
	printf("%d\n", ft_memcmp(s, s2, 1) > 0);
	printf("%d\n", memcmp(s, s2, 1) > 0);
	printf("%d\n", ft_memcmp(s2, s, 1) < 0);
	printf("%d\n", memcmp(s2, s, 1) < 0);
//	printf("%d\n", ft_memcmp(s2, s3, 4) != 0);
	write(1, "\n", 1);
	return (0);
}*/
/*
int main(void)
{
	size_t size = 10;
 	char *b1 = malloc(size);
 	char *b2 = malloc(size);

 	strcpy(b1, ".........");
 	strcpy(b2, ".........");
 	ft_memcmp(b1, b2, size);
}*/
