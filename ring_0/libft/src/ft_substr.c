/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:31:24 by meguetta          #+#    #+#             */
/*   Updated: 2025/07/12 05:36:18 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;
	unsigned int	src_len;

	i = 0;
	src_len = ft_strlen((char *)s);
	if (s == NULL)
		return (NULL);
	if (start >= src_len)
		len = 0;
	if (len > src_len - start)
		len = ft_strlen((char *)s + start);
	sub = malloc(sizeof(char) * len + 1);
	if (sub == NULL)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	char	*str = argv[1];
	unsigned int	start = ft_atoi(argv[2]);
	size_t	len = ft_atoi(argv[3]);
	printf("%s", ft_substr(str, start, len));
	return (0);
}*/
