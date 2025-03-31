/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:41:09 by meguetta          #+#    #+#             */
/*   Updated: 2024/11/21 16:15:15 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	i = 0;
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	while (ptr_s1[i] && ptr_s2[i] && ptr_s1[i] == ptr_s2[i] && i < n)
	{
		i++;
	}
	if (i < n)
		return (ptr_s1[i] - ptr_s2[i]);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	char	*str = argv[1];
	char	*str1 = argv[2];
	size_t	n = ft_atoi(argv[3]);
	printf("%d", ft_strncmp(str, str1, n));
	return (0);
}*/
