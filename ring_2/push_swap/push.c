/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:57:57 by meguetta          #+#    #+#             */
/*   Updated: 2025/03/24 08:47:22 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_list;

	tmp_list = *stack_a;
	if (*stack_b == NULL)
		return ;
	tmp_list = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp_list->next = *stack_a;
	*stack_a = tmp_list;
	ft_printf("%s\n", PA);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_list;

	tmp_list = *stack_b;
	if (*stack_a == NULL)
		return ;
	tmp_list = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp_list->next = *stack_b;
	*stack_b = tmp_list;
	ft_printf("%s\n", PB);
}
