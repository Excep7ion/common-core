/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:37:50 by meguetta          #+#    #+#             */
/*   Updated: 2025/07/12 05:33:27 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	conversion(long nb, char *str, int str_len, int i)
{
	while (i < str_len)
	{
		str[str_len - 1] = (nb % 10) + 48;
		nb /= 10;
		str_len--;
	}
}

static int	count_char(long nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
	{
		nb *= -1;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		i;
	int		str_len;
	char	*str;
	long	nb;

	i = 0;
	nb = n;
	str_len = count_char(nb);
	str = malloc(sizeof(char) * (str_len + 1));
	if (str == NULL)
		return (NULL);
	if (nb < 0)
	{
		str[i++] = '-';
		nb *= -1;
	}
	if (nb == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	conversion(nb, str, str_len, i);
	str[str_len] = '\0';
	return (str);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	int	n;
	n = ft_atoi(argv[1]);
	printf("%s", ft_itoa(n));
	return (0);
}
*/
