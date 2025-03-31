/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:05:36 by meguetta          #+#    #+#             */
/*   Updated: 2025/03/28 18:15:05 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_p(va_list list)
{
	unsigned long	tmp;
	int				count;

	count = 0;
	tmp = va_arg(list, unsigned long);
	if (!tmp)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	count += ft_putnbr_exa(tmp, 1);
	return (count + 2);
}
