/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:29:12 by meguetta          #+#    #+#             */
/*   Updated: 2024/11/15 17:55:22 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -= 32);
	else
		return (c);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	int	c = atoi(argv[1]);
	printf("%d\n", ft_toupper(c));
	fflush(stdout);
	printf("%d", toupper(c));
	fflush(stdout);
	return (0);
}
*/
