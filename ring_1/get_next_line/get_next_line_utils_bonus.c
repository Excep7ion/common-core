/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:54:52 by meguetta          #+#    #+#             */
/*   Updated: 2024/12/25 15:19:29 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*tab;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tab = malloc(nmemb * size);
	if (tab == NULL)
		return (NULL);
	while (i < (nmemb * size))
	{
		((char *)tab)[i] = 0;
		i++;
	}
	return (tab);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	if (s == NULL)
		return (NULL);
	dup = malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (dup == NULL)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*join;

	i = 0;
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	join = malloc(sizeof(char) * ((s1_len + s2_len) + 1));
	if (join == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		join[s1_len + i] = s2[i];
		i++;
	}
	join[s1_len + i] = '\0';
	return (join);
}
