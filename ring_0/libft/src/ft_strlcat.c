/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:15:28 by meguetta          #+#    #+#             */
/*   Updated: 2025/07/12 05:35:26 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//Ajoute les caractères de src à la fin de dst,
//jusqu’à ce que le buffer de destination atteigne la taille dstsize ou
//jusqu’à ce que le caractère NUL (\0) soit rencontré dans src.
size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	if (siz == 0 || dst_len >= siz)
		return (siz + src_len);
	else if (src_len < (siz - dst_len))
	{
		ft_memcpy(dst + dst_len, src, src_len);
		dst[dst_len + src_len] = '\0';
	}
	else
	{
		ft_memcpy(dst + dst_len, src, (siz - 1) - dst_len);
		dst[siz - 1] = '\0';
	}
	return (dst_len + src_len);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
//	char	*dst = argv[1];
	char	dst[] = "abcddddddddddddddddddd";
//	char	*src = argv[2];
//	char	src[] = "destination";
//	size_t	siz = atoi(argv[3]);
//	size_t	siz = 1;
//	printf("%zu\n", strlcat(dst, src, siz));
//	printf("%s\n", dst);
//	printf("%zu\n", ft_strlcat(dst, src, siz));
//	printf("%s\n", dst);

	printf("%zu\n", ft_strlcat("pqrstuvwxyz", dst, 2));
	printf("%s\n", dst);
	printf("%zu\n", strlcat("pqrstuvwxyz", dst, 2));
	printf("%s\n", dst);
	return (0);
}*/
