/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:19:06 by meguetta          #+#    #+#             */
/*   Updated: 2025/07/12 05:34:23 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//Copie n octets depuis la zone mémoire src vers la zone mémoire dest
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptr_d;
	char	*ptr_s;

	i = 0;
	ptr_d = (char *)dest;
	ptr_s = (char *)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i < n)
	{
		ptr_d[i] = ptr_s[i];
		i++;
	}
	return (ptr_d);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	char	*src = argv[1];
	int	v;
	v = ft_strlen((argv[1])) + 1;
	char	dest[v];
	ft_memcpy(dest, src, v);
	memcpy(dest, src, v);
	printf("%s", dest);
	return (0);
}*/
