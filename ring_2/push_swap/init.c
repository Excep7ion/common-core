/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 06:17:15 by meguetta          #+#    #+#             */
/*   Updated: 2025/04/01 06:18:54 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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

void	init_count(t_bag **bag)
{
	(*bag)->count_ra = 0;
	(*bag)->count_rra = 0;
	(*bag)->count_rb = 0;
	(*bag)->count_rrb = 0;
	(*bag)->count_rr = 0;
	(*bag)->count_rrr = 0;
}

void	addition_count(t_bag **bag)
{
	(*bag)->tmp
		= (*bag)->count_ra
		+ (*bag)->count_rra
		+ (*bag)->count_rb
		+ (*bag)->count_rrb
		+ (*bag)->count_rr
		+ (*bag)->count_rrr;
}
