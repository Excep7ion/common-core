/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:49:38 by meguetta          #+#    #+#             */
/*   Updated: 2024/11/15 17:55:00 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c += 32);
	else
		return (c);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	int	c = atoi(argv[1]);
	printf("%d\n", ft_tolower(c));
	fflush(stdout);
	printf("%d", tolower(c));
	fflush(stdout);
	return (0);
}
*/
