/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:53:10 by meguetta          #+#    #+#             */
/*   Updated: 2024/11/21 16:15:33 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Copie les n octets depuis la zone memoire src vers la zone memoire dest
//les 2 zones ne peuvent pas ce cheuvaucher
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;

	i = 0;
	ptr_d = (unsigned char *)dest;
	ptr_s = (unsigned char *)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (src < dest)
	{
		while (n-- > 0)
			ptr_d[n] = ptr_s[n];
	}
	else
	{
		while (i < n)
		{
			ptr_d[i] = ptr_s[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main(int argc,char **argv)
{
	(void)argc;
	char *src = argv[1];
	char *dest = argv[2];
	size_t n = 3;
	ft_memmove(dest, src, n);
	printf("%s", dest);
	return (0);
}*/
