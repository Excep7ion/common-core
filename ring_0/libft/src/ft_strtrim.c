/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:57:28 by meguetta          #+#    #+#             */
/*   Updated: 2025/07/12 05:36:14 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

//Supprime les caracteres de set au debut et a la fin de s1
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		s1_len;
	char	*trim;

	start = 0;
	end = ft_strlen((char *)s1);
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] && check_set(s1[start], set) == 1)
		start++;
	while (end > start && check_set(s1[end - 1], set) == 1)
		end--;
	s1_len = end - start;
	trim = malloc(sizeof(char) * s1_len + 1);
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, (s1 + start), (s1_len + 1));
	return (trim);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	char	*s1 = argv[1];
	char	*set = argv[2];
	printf("%s", ft_strtrim(s1, set));
	return (0);
}*/
