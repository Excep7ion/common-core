/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:02:35 by meguetta          #+#    #+#             */
/*   Updated: 2025/03/24 10:16:49 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	reverse_rotate_a(t_list **stack_a, int b)
{
	t_list	*last;
	t_list	*before_last;

	last = *stack_a;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (b)
		ft_printf("%s\n", RRA);
}

void	reverse_rotate_b(t_list **stack_b, int b)
{
	t_list	*last;
	t_list	*before_last;

	last = *stack_b;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if (b)
		ft_printf("%s\n", RRB);
}

void	reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_a(stack_a, 0);
	reverse_rotate_b(stack_b, 0);
	ft_printf("%s\n", RRR);
}
