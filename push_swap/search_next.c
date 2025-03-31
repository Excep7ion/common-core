/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:33:58 by meguetta          #+#    #+#             */
/*   Updated: 2025/03/30 20:46:22 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*
int	search_winner(int winner, t_bag *bag)
{
	bag->winner = winner;
	return (bag->winner);
}*/
/*
int	search_winner(t_list *stack_a, t_list *stack_b, int min_operation, t_bag *bag)
{
	int	rb;
	int	ra;
	int	position;
	int	winner;

	ra = 0;
	while (stack_a)
	{
		position = target_position(stack_a, stack_b, bag);
		rb = 0;
		while (position > 1)
		{
			rb++;
			position--;
		}
		if ((ra + rb) < min_operation)
		{
			min_operation = ra + rb;
			winner = stack_a->content;
		}
		ra++;
		stack_a = stack_a->next;
	}
	return (winner);
}
*/

int	search_winner(t_list *stack_a, t_list *stack_b, t_bag *bag)
{
	//	printf("COUNT_OPERATIONS :\n");
	int	position;
	bag->copie_a = stack_a;
	bag->size = ft_lstsize(stack_a);
	position = 0;
	bag->min_operations = INT_MAX;
	while (bag->copie_a)
	{
		//		printf("\nstack_a = %d\n", bag->copie_a->content);
		bag->count_rb = 0;
		bag->count_rrb = 0;
		bag->count_ra = 0;
		bag->count_rra = 0;
		bag->count_rr = 0;
		bag->count_rrr = 0;
//		printf("Position stack_a: %d\n", position);
//		printf("Médiane stack_a: %d\n", search_median(stack_a, bag));
		if (position <= search_median(stack_a, bag))
		{
			bag->count_ra = position;
//			printf("ra = %d\n", bag->count_ra);
		}
		else
		{
//			printf("size = %d\n", ft_lstsize(stack_a));
//			printf("position = %d\n", position);
			bag->count_rra = ft_lstsize(stack_a) - position;
//			printf("rra = %d\n", bag->count_rra);
		}
		bag->target_position = target_position(bag->copie_a->content, stack_b, bag);
		//		printf("target_position = %d\n", bag->target_position);
		if (bag->target_position <= search_median(stack_b, bag))
		{
			bag->count_rb = bag->target_position;
			//			printf("rb = %d\n", bag->count_rb);
		}
		else	
		{
			bag->count_rrb = ft_lstsize(stack_b) - bag->target_position;
//			printf("rrb = %d\n", bag->count_rrb);
		}
//		printf("count_ra = %d\n", bag->count_ra);
//		printf("count_rra = %d\n", bag->count_rra);
//		printf("count_rb = %d\n", bag->count_rb);
//		printf("count_rrb = %d\n", bag->count_rrb);
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
//		printf("count_rr = %d\n", bag->count_rr);
//		printf("count_rrr = %d\n", bag->count_rrr);
		bag->tmp
			= bag->count_ra
			+ bag->count_rra
			+ bag->count_rb
			+ bag->count_rrb
			+ bag->count_rr
			+ bag->count_rrr;
//		printf("tmp = %d\n", bag->tmp);
		if (bag->tmp < bag->min_operations)
		{
			bag->winner = bag->copie_a->content;
			bag->min_operations = bag->tmp;
		}
//		printf("min_operations = %d\n", bag->min_operations);
		position++;
		bag->copie_a = bag->copie_a->next;
	}
//	printf("\nle winner est %d\n", bag->winner);
//	printf("min_operations (+1 pour pb) = %d\n\n", bag->min_operations + 1);
	return (bag->winner);
}
