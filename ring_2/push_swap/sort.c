/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:54:53 by meguetta          #+#    #+#             */
/*   Updated: 2025/03/28 06:34:21 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content
		&& (*stack_a)->next->content < (*stack_a)->next->next->content)
		swap_a(stack_a, 1);
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		swap_a(stack_a, 1);
		reverse_rotate_a(stack_a, 1);
	}	
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->content < (*stack_a)->next->next->content)
		rotate_a(stack_a, 1);
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		swap_a(stack_a, 1);
		rotate_a(stack_a, 1);
	}	
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
		reverse_rotate_a(stack_a, 1);
}

void	sort_four(t_list **stack_a, t_list **stack_b, t_bag *bag)
{
	min_first(stack_a, 0, bag);
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b, t_bag *bag)
{
	min_first(stack_a, 0, bag);
	push_b(stack_a, stack_b);
	min_first(stack_a, 0, bag);
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_one_hundred(t_list **stack_a, t_list **stack_b, t_bag *bag)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	algo(stack_a, stack_b, bag);
}
