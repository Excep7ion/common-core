/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:45:32 by meguetta          #+#    #+#             */
/*   Updated: 2024/11/07 10:54:39 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_abs.h"

int	test(int a, int b)
{
	int result;
	result = a + b;
	return (result);
}

int main(void)
{
	printf("%d", ABS(-5));
	printf("%d", test(ABS(-40), -10));

	return (0);
}
