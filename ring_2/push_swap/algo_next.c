/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:20:54 by meguetta          #+#    #+#             */
/*   Updated: 2025/04/02 06:09:49 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_winner(t_list *stack_a, t_list *stack_b, t_bag *bag)
{
	int	position;

	bag->winner = search_winner(stack_a, stack_b, bag);
	position = 0;
	while (bag->winner != stack_a->content)
	{
		position++;
		stack_a = stack_a->next;
	}
	return (position);
}

void	execute_operations(t_list **stack_a, t_list **stack_b, t_bag *bag)
{
	int	position;

	position = position_winner(*stack_a, *stack_b, bag);
	init_bag(&bag, *stack_a);
	if (position <= search_median(bag->copie_a, bag))
		bag->count_ra = position;
	else
		bag->count_rra = ft_lstsize(*stack_a) - position;
	bag->target_position = target_position(bag->winner, *stack_b, bag);
	if (bag->target_position <= search_median(*stack_b, bag))
		bag->count_rb = bag->target_position;
	else
		bag->count_rrb = ft_lstsize(*stack_b) - bag->target_position;
	check_rr_and_rrr(&bag);
	actions(stack_a, stack_b, bag);
}

void	actions(t_list **stack_a, t_list **stack_b, t_bag *bag)
{
	while (bag->count_ra-- > 0)
		rotate_a(stack_a, 1);
	while (bag->count_rra-- > 0)
		reverse_rotate_a(stack_a, 1);
	while (bag->count_rb-- > 0)
		rotate_b(stack_b, 1);
	while (bag->count_rrb-- > 0)
		reverse_rotate_b(stack_b, 1);
	while (bag->count_rr-- > 0)
		rotate_a_and_b(stack_a, stack_b);
	while (bag->count_rrr-- > 0)
		reverse_rotate_a_and_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
}

void	execute_operations_next(t_list **stack_a, t_list **stack_b, t_bag *bag)
{
	bag->position = 0;
	while ((*stack_b)->next)
	{
		if ((*stack_b)->content > (*stack_b)->next->content
			&& (*stack_b)->content > ft_lstlast(*stack_b)->content)
			push_a(stack_a, stack_b);
		else
		{
			bag->position = rb_or_rrb(*stack_b, bag);
			if (bag->position < search_median(*stack_b, bag))
				rotate_b(stack_b, 1);
			else
				reverse_rotate_b(stack_b, 1);
			bag->position = 0;
		}
	}
}

int	rb_or_rrb(t_list *stack_b, t_bag *bag)
{
	bag->copie_b = stack_b;
	bag->position = 0;
	while (bag->copie_b->content != stack_b->content)
	{
		bag->position++;
		stack_b = stack_b->next;
	}
	return (bag->position);
}
