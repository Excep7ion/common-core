/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:11:22 by meguetta          #+#    #+#             */
/*   Updated: 2024/09/05 12:10:22 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int	ft_strlen(char *str, char *charset);
int	check_sep(char c, char *charset);
int	count_word(char *str, char *charset);
char	**ft_split(char *str, char *charset);

// duplicate
char	*ft_strdup(char *str, char *charset, int i)
{
	int	j;
	char *dest;

	dest = malloc(sizeof(char) * (ft_strlen(str, charset) + 1));
	j = 0;
	while (str[i] && check_sep(str[i], charset) == 0)
	{
		dest[j] = str[i];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// check si c'est  un separateur ou non
int	check_sep(char c, char *charset)
{
	int	j;

	j = 0;
	while (charset[j])
	{
		if ( c == charset[j])
		{
			return (1);
		}
		j++;
	}
	return (0);
}

// compteur de mots
int	count_word(char *str, char *charset)
{
	int	i;
	int	count;
	int ok;

	i = 0;
	count = 0;
	ok = 0;
	while (str[i])
	{
		while (check_sep(str[i], charset) == 0 && str[i]) // mots
		{
			i++;
			ok++;
		}
		while (check_sep(str[i], charset) == 1) // seps
		{
			i++;
		}
		if (ok > 0)
			count++;
		ok = 0;
	}
	printf("\n%d\n", count);
	return (count);
}

// compte la taille
int	ft_strlen(char *str,char *charset)
{
	int	i;

	i = 0;
	while (str[i] && check_sep(str[i], charset) == 0) // mots
		i++;
	return(i);
}

// Split
char	**ft_split(char *str, char *charset)
{
	int	i;
	int	j;
	char **tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char*) * (count_word(str, charset) + 1));
	if (tab == NULL)
		return (NULL);
	while (str[i])
	{
		while (str[i] && check_sep(str[i], charset) == 1)
		{
			i++;
		}
		if (check_sep(str[i], charset) == 0 && str[i]) // mots
		{
				tab[j] = ft_strdup( str, charset , i);
				j++;
				i++;
				while (check_sep(str[i], charset) == 0 && str[i])
					i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

int	main(int argc, char **argv)
{
	char **tab;
	int	i;

	if (argc >= 1)
	{
		tab = ft_split(argv[1], argv[2]);
		i = 0;
		while (tab[i])
		{
			printf("%p -----> %s\n", tab[i], tab[i]);
			i++;
		}
		printf("%p -----> %s\n", tab[i], tab[i]);
		i = 0;
		while (tab[i])
		{
			free(tab[i++]);
		}
		free(tab);
	}
}
