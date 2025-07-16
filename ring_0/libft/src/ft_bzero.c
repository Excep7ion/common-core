/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:31:52 by meguetta          #+#    #+#             */
/*   Updated: 2025/07/12 05:32:56 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	int				i;
	unsigned char	*ptr;

	ptr = s;
	i = 0;
	while (n > 0)
	{
		ptr[i] = '\0';
		n--;
		i++;
	}
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	char	*str;
	size_t n;

	str = argv[1];
	n = ft_atoi(argv[2]);
	ft_bzero(str, n);
	printf("%s", str);
//	printf("%s\n",(void) ft_bzero(str, n));
//	printf("%s",(void) bzero(str, n));
	return (0);
}
*/
