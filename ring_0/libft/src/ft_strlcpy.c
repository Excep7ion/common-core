/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:37:24 by meguetta          #+#    #+#             */
/*   Updated: 2025/07/12 05:35:30 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//Copie src à la chaîne dst de taille siz et termine par un '\0'
size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;

	i = 0;
	while (src[i] && (i + 1) < siz)
	{
		dst[i] = src[i];
		i++;
	}
	if (siz > 0)
		dst[i] = '\0';
	return (ft_strlen((char *)src));
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
//	char	*src = argv[1];
	char	src[] = "aa";
//	char	*dst = argv[2];
	char	dst[] = "destination";
//	char	*dest = argv[3];
	char	dest[] = "destination";
//	size_t	siz = atoi(argv[4]);
	size_t	siz = 0;
	printf("%zu\n", strlcpy(dst, src, siz));
	printf("%s\n", dst);
	printf("%zu\n", ft_strlcpy(dest, src, siz));
	printf("%s", dest);
	return (0);
}*/
