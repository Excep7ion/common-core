/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:24:27 by meguetta          #+#    #+#             */
/*   Updated: 2025/01/13 18:06:00 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_2(va_list list, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(list, int));
	if (c == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(list, int));
	else if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(list, unsigned int));
	else if (c == 'p')
		count += check_p(list);
	else if (c == '%')
		count += ft_putchar(c);
	else if (c == 'x')
		count += ft_putnbr_exa(va_arg(list, unsigned int), 1);
	else if (c == 'X')
		count += ft_putnbr_exa(va_arg(list, unsigned int), 0);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	list;

	i = 0;
	count = 0;
	va_start(list, format);
	if (format == NULL)
		return (-1);
	while (format[i])
	{
//		if (format[i + 1] == '\0')
//			return (count);
		if (format[i] == '%' && format[i + 1] != '\0')
			count += ft_printf_2(list, format[++i]);
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(list);
	return (count);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char	c;
	char	*str;
	int	d;
	int	i;
	unsigned int	u;
	int	exa;

	c = 'a';
	str = NULL;
	d = 42;
	i = 11;
	u = -42;
	exa = -9999;
	printf("je m'entr%cine a reproduire %s pour la %deme fois\nl'adresse \
	de str est %x, em maj c'est %X je veux un seul %%\n", c, str, d, exa, exa);
	ft_printf("je m'entr%cine a reproduire %s pour la %deme fois\nl'adresse \
	de str est %x, em maj c'est %X je veux un seul %%\n", c, str, d, exa, exa);

	printf("c = %c\n", c);
	ft_printf("c = %c\n", c);

	printf("str = %s\n", str);
	ft_printf("str = %s\n", str);

//	printf("affiche le %", str);
//	ft_printf("affiche le %", str);

	printf("d = %d\n", d);
	ft_printf("d = %d\n", d);

	printf("i = %i\n", i);
	ft_printf("i = %i\n", i);

	printf("u = %u\n", u);
	ft_printf("u = %u\n", u);

	printf("str = %p\n", str);
	ft_printf("str = %p\n", str);

	printf("x = %x\n", exa);
	ft_printf("x = %x\n", exa);

	printf("X = %X\n", exa);
	ft_printf("X = %X\n", exa);

	printf("%%\n");
	ft_printf("%%\n");

	printf("count = %d\n", printf("%x\n", exa));

//	printf("%s", str)


	return (0);
}
