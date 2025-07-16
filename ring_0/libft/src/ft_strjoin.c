/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:07:54 by meguetta          #+#    #+#             */
/*   Updated: 2025/07/12 05:35:21 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*join;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	join = malloc(sizeof(char) * ((s1_len + s2_len) + 1));
	if (join == NULL)
		return (NULL);
	ft_strlcpy(join, (char *)s1, s1_len + 1);
	ft_strlcat(join, (char *)s2, s1_len + s2_len + 1);
	return (join);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	char	*s1 = argv[1];
	char	*s2 = argv[2];

	printf("%s", ft_strjoin(s1, s2));
	return (0);
}*/
