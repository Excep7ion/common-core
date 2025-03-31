/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:28:21 by meguetta          #+#    #+#             */
/*   Updated: 2025/01/23 14:26:54 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// check si s[i] est un separateur ou non
static int	check_sep(char a, char c)
{
	if (a == c)
		return (1);
	return (0);
}

// Compte la taille des mots
static int	ft_strlen_2(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && check_sep(s[i], c) == 0)
		i++;
	return (i);
}

// duplicate
static char	*ft_strdup_2(const char *s, char c, int i)
{
	char	*dup;
	int		j;

	dup = malloc(sizeof(char) * (ft_strlen_2(s + i, c) + 1));
	j = 0;
	if (dup == NULL)
		return (NULL);
	while (s[i] && check_sep(s[i], c) == 0)
	{
		dup[j] = s[i];
		i++;
		j++;
	}
	dup[j] = '\0';
	return (dup);
}

// compte le nombre de mots
static int	count_word(const char *s, char c)
{
	int	i;
	int	ok;
	int	count;

	i = 0;
	ok = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && check_sep(s[i], c) == 0)
		{
			i++;
			ok++;
		}
		while (s[i] && check_sep(s[i], c) == 1)
			i++;
		if (ok > 0)
			count++;
		ok = 0;
	}
	return (count);
}

// separe les mots
char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] && check_sep(s[i], c) == 1)
			i++;
		if (s[i] && check_sep(s[i], c) == 0)
		{
			tab[j++] = ft_strdup_2(s, c, i);
			while (s[i] && check_sep(s[i], c) == 0)
				i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int	i;
	char	**tab;
	//char	str[] ="   lorem   ipsum dolor     sit amet, consectetur   adipis";
	char	c;

	i = 0;
	c = ' ';
	tab = ft_split("lorem ipsum dolor sit amet, consectetur adipis", ' ');
	while (tab[i])
	{
		printf("%p ----> %s\n", tab[i], tab[i]);
		i++;
	}
	printf("%p ----> %s\n", tab[i], tab[i]);
	i = 0;
	while (tab[i])
	{
		free(tab[i++]);
	}
	free(tab);
	return (0);
}
*/
/*
int	main(int argc, char **argv)
{
	(void)argc;
	int	i;
	char	**tab;

	i = 0;
	tab = ft_split(argv[1], argv[2][0]);
	while (tab[i])
	{
		printf("%p ----> %s\n", tab[i], tab[i]);
		i++;
	}
	printf("%p ----> %s\n", tab[i], tab[i]);
	i = 0;
	while (tab[i])
	{
		free(tab[i++]);
	}
	free(tab);
	return (0);
}*/
