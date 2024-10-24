/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:30:15 by meguetta          #+#    #+#             */
/*   Updated: 2024/08/28 18:12:23 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
//	if (size == dest[])
	dest[dest_len + i] = '\0';
	return (src_len + size -1);
}

int	main(void)
{
	char	dest[] = "1234";
	char	src[] = "abcd";
	unsigned int	size = 2;
//	printf("%zu", ft_strlcat(dest, src, size));
	printf("%zu", strlcat(dest, src, size));
	return (0);
}
