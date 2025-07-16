/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:33:58 by meguetta          #+#    #+#             */
/*   Updated: 2025/04/02 06:10:18 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	check_rr_and_rrr(t_bag **bag)
{
	if ((*bag)->count_ra > 0 && (*bag)->count_rb > 0)
	{
		(*bag)->count_rr = rr((*bag)->count_ra, (*bag)->count_rb, *bag);
		while ((*bag)->count_ra > 0 && (*bag)->count_rb > 0)
		{
			(*bag)->count_ra--;
			(*bag)->count_rb--;
		}
	}
	if ((*bag)->count_rra > 0 && (*bag)->count_rrb > 0)
	{
		(*bag)->count_rrr = rrr((*bag)->count_rra, (*bag)->count_rrb, *bag);
		while ((*bag)->count_rra > 0 && (*bag)->count_rrb > 0)
		{
			(*bag)->count_rra--;
			(*bag)->count_rrb--;
		}
	}
}

void	ra_rra_rb_rrb(t_list *stack_a, t_list *stack_b, t_bag *bag, int p)
{
	if (p <= search_median(stack_a, bag))
		bag->count_ra = p;
	else
		bag->count_rra = ft_lstsize(stack_a) - p;
	bag->target = target_position(bag->copie_a->content, stack_b, bag);
	if (bag->target <= search_median(stack_b, bag))
		bag->count_rb = bag->target;
	else
		bag->count_rrb = ft_lstsize(stack_b) - bag->target;
}

int	search_winner(t_list *stack_a, t_list *stack_b, t_bag *bag)
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
	return (bag->winner);
}
