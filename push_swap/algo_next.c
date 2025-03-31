/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:20:54 by meguetta          #+#    #+#             */
/*   Updated: 2025/03/30 21:15:09 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_winner(t_list *stack_a, t_list *stack_b, t_bag *bag)
{
	int	position;


	bag->winner = search_winner(stack_a, stack_b, bag);
	position = 0;
//	printf("winner -> %d\n", bag->winner);
	while (bag->winner != stack_a->content)
	{
//		printf("ici\n");
		position++;
		stack_a = stack_a->next;
	}
//	printf("position -> %d\n", position);
	return (position);
}

void	init_bag(t_bag **bag, t_list *stack_a)
{
	(*bag)->copie_a = stack_a;
	(*bag)->count_ra = 0;
	(*bag)->count_rb = 0;
	(*bag)->count_rra = 0;
	(*bag)->count_rrb = 0;
	(*bag)->count_rr = 0;
	(*bag)->count_rrr = 0;
}

void	execute_operations(t_list **stack_a, t_list **stack_b, t_bag *bag)
{
	int	position;
	position = position_winner(*stack_a, *stack_b, bag);
//	printf("EXECUTE_OPERATIONS :\n");
	init_bag(&bag, *stack_a);
	//	printf("search_median = %d\n", search_median(*stack_a, bag));
//	printf("position = %d\n", position);
	if (position <= search_median(bag->copie_a, bag))
	{
		bag->count_ra = position;
	}
	else
	{
//		printf("ici\n");
		bag->count_rra = ft_lstsize(*stack_a) - position;
	}
	bag->target_position = target_position(bag->winner, *stack_b, bag);
	if (bag->target_position <= search_median(*stack_b, bag))
	{
		bag->count_rb = bag->target_position;
	}
	else
	{
		bag->count_rrb = ft_lstsize(*stack_b) - bag->target_position;
	}
//	printf("count_ra = %d\n", bag->count_ra);
//	printf("count_rra = %d\n", bag->count_rra);
//	printf("count_rb = %d\n", bag->count_rb);
//	printf("count_rrb = %d\n", bag->count_rrb);
	if (bag->count_ra > 0 && bag->count_rb > 0)
	{
		bag->count_rr = count_rr(bag->count_ra, bag->count_rb, bag);
		while (bag->count_ra > 0 && bag->count_rb > 0)
		{
			bag->count_ra--;
			bag->count_rb--;
		}
	}
	if (bag->count_rra > 0 && bag->count_rrb > 0)
	{
		bag->count_rrr = count_rrr(bag->count_rra, bag->count_rrb, bag);
		while (bag->count_rra > 0 && bag->count_rrb > 0)
		{
			bag->count_rra--;
			bag->count_rrb--;
		}
	}
	while (bag->count_ra-- > 0)
		rotate_a(stack_a, 1);
	while (bag->count_rra > 0)
	{
		reverse_rotate_a(stack_a, 1);
		bag->count_rra--;
	}
	while (bag->count_rb > 0)
	{
		rotate_b(stack_b, 1);
		bag->count_rb--;
	}
	while (bag->count_rrb > 0)
	{
		reverse_rotate_b(stack_b, 1);
		bag->count_rrb--;
	}
	while (bag->count_rr > 0)
	{
		rotate_a_and_b(stack_a, stack_b);
		bag->count_rr--;
	}
	while (bag->count_rrr > 0)
	{
		reverse_rotate_a_and_b(stack_a, stack_b);
		bag->count_rrr--;
	}
//	printf("count_rr = %d\n", bag->count_rr);
//	printf("count_rrr = %d\n", bag->count_rrr);
	push_b(stack_a, stack_b);
}
/*
void	execute_rb_or_rrb(t_list **stack_b, int min_operation, int target, t_bag *bag)
{
	if (min_operation <= search_median(*stack_b, bag))
	{
		while (target != (*stack_b)->content)
			rotate_b(stack_b, 1);
	}
	else
	{
		min_operation = (min_operation / 2);
		while (target != (*stack_b)->content)
			reverse_rotate_b(stack_b, 1);
	}
}
*/
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
