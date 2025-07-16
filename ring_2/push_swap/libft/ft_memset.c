/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:02:24 by meguetta          #+#    #+#             */
/*   Updated: 2024/11/21 16:13:19 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//                 string   value    len
void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*ptr;

	ptr = s;
	i = 0;
	while (n > 0)
	{
		ptr[i] = c;
		n--;
		i++;
	}
	return (s);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	char	*str;
	int	c;
	size_t	n;

	str = argv[1];
	c = argv[2][0];
	n = ft_atoi(argv[3]);
	printf("%s\n",(char *) ft_memset(str, c, n));
	printf("%s",(char *) memset(str, c, n));
	return (0);
}
*/
