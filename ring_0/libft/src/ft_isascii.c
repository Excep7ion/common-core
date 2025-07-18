/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:19:24 by meguetta          #+#    #+#             */
/*   Updated: 2025/07/12 05:33:16 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int main(int argc, char **argv)
{
	(void)argc;
	int	c;

	c = argv[1][0];
	printf("%d", ft_isascii(c));
	return (0);
}
*/
