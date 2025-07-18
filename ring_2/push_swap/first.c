/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:13:33 by meguetta          #+#    #+#             */
/*   Updated: 2025/04/02 06:59:24 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	min_first(t_list **stack, int b, t_bag *bag)
{
	int	min;
	int	median;
	int	position_min;

	(void) b;
	position_min = search_position_min(*stack, bag);
	median = search_median(*stack, bag);
	min = search_min(*stack, bag);
	while (min != (*stack)->content)
	{
		if (position_min <= median)
			rotate_a(stack, 1);
		else
			reverse_rotate_a(stack, 1);
	}
}

void	max_first(t_list **stack, int b, t_bag *bag)
{
	bag->max = search_max(*stack, bag);
	bag->median = search_median(*stack, bag);
	bag->position_max = search_position_max(*stack, bag);
	while (bag->max != (*stack)->content)
	{
		if (bag->position_max <= bag->median)
		{
			if (b == 0)
				rotate_a(stack, 1);
			else
				rotate_b(stack, 1);
		}
		else
		{
			if (b == 0)
				reverse_rotate_a(stack, 1);
			else
				reverse_rotate_b(stack, 1);
		}
	}
}
