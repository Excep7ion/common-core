/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 07:33:42 by meguetta          #+#    #+#             */
/*   Updated: 2025/03/28 05:43:46 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	count_rr(int ra, int rb, t_bag *bag)
{
	bag->count = 0;
	while (ra && rb)
	{
		ra--;
		rb--;
		bag->count++;
	}
	return (bag->count);
}

int	count_rrr(int rra, int rrb, t_bag *bag)
{
	bag->count = 0;
	while (rra && rrb)
	{
		rra--;
		rrb--;
		bag->count++;
	}
	return (bag->count);
}
