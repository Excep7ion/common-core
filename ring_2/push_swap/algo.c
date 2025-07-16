/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:27:06 by meguetta          #+#    #+#             */
/*   Updated: 2025/04/02 07:51:51 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_list **stack_a, t_list **stack_b, t_bag *bag)
{
	while (*stack_a)
	{
		count_operations(*stack_a, *stack_b, bag);
		execute_operations(stack_a, stack_b, bag);
	}
	execute_operations_next(stack_a, stack_b, bag);
	push_a(stack_a, stack_b);
}

void	count_operations(t_list *stack_a, t_list *stack_b, t_bag *bag)
{
	int	position;

	bag->copie_a = stack_a;
	bag->size = ft_lstsize(stack_a);
	position = 0;
	bag->min_operations = INT_MAX;
	while (bag->copie_a)
	{
		init_count(&bag);
		ra_rra_rb_rrb(stack_a, stack_b, bag, position);
		check_rr_and_rrr(&bag);
		addition_count(&bag);
		if (bag->tmp < bag->min_operations)
		{
			bag->winner = bag->copie_a->content;
			bag->min_operations = bag->tmp;
		}
		position++;
		bag->copie_a = bag->copie_a->next;
	}
}

int	target_position(int content, t_list *stack_b, t_bag *bag)
{
	bag->size = ft_lstsize(stack_b);
	if (content > search_max(stack_b, bag) || content < search_min(stack_b,
			bag))
		bag->target_position = max_position(stack_b, bag);
	else
		bag->target_position = lower_position_close(stack_b, content, bag);
	return (bag->target_position);
}

int	max_position(t_list *stack_b, t_bag *bag)
{
	bag->max = search_max(stack_b, bag);
	bag->position = 0;
	bag->copie_b = stack_b;
	while (bag->max != bag->copie_b->content)
	{
		bag->position++;
		bag->copie_b = bag->copie_b->next;
	}
	return (bag->position);
}

int	lower_position_close(t_list *stack_b, int content, t_bag *bag)
{
	int	tmp;

	bag->copie_b = stack_b;
	bag->position = 0;
	bag->tmp = 0;
	tmp = -500;
	while (stack_b)
	{
		if (content > stack_b->content && stack_b->content > tmp)
			tmp = stack_b->content;
		stack_b = stack_b->next;
	}
	while (bag->copie_b && tmp != bag->copie_b->content)
	{
		bag->position++;
		bag->copie_b = bag->copie_b->next;
	}
	return (bag->position);
}
