/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 07:20:20 by meguetta          #+#    #+#             */
/*   Updated: 2025/07/12 05:35:54 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (ptr == NULL || s == NULL)
		return (NULL);
	while (s[i])
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
   int main(int argc, char **argv)
   {
   (void)argc;
   unsigned int	i = 0;
   char	c = 'a';
   char	*s = argv[1];
   printf("%s", ft_strmapi(s, isalpha_2((char *)s, i, c)));
   return (0);
   }*/
