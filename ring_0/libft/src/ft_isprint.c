/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:29:18 by meguetta          #+#    #+#             */
/*   Updated: 2025/07/12 05:33:24 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char	*c;

	c = argv[1][0];
	printf("%d", ft_isprint(ft_atoi(c)));
	return (0);
}
*/
