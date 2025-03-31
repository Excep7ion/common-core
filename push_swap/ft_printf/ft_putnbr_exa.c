/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_exa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:16:35 by meguetta          #+#    #+#             */
/*   Updated: 2025/03/28 18:14:26 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_exa(unsigned long nb, int maj)
{
	int		count;
	char	*base;

	count = 0;
	if (maj)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb > 15)
	{
		count += ft_putnbr_exa(nb / 16, maj);
		count += ft_putnbr_exa(nb % 16, maj);
	}
	else
		count += ft_putchar(base[nb]);
	return (count);
}
