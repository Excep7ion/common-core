/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:59:03 by meguetta          #+#    #+#             */
/*   Updated: 2025/03/24 08:45:21 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_a(t_list **stack_a, int b)
{
	t_list	*tmp_list;
	t_list	*tmp_list2;

	tmp_list = *stack_a;
	tmp_list2 = *stack_a;
	while (tmp_list->next)
		tmp_list = tmp_list->next;
	tmp_list->next = *stack_a;
	*stack_a = tmp_list2->next;
	tmp_list2->next = NULL;
	if (b)
		ft_printf("%s\n", RA);
}

void	rotate_b(t_list **stack_b, int b)
{
	t_list	*tmp_list;
	t_list	*tmp_list2;

	tmp_list = *stack_b;
	tmp_list2 = *stack_b;
	while (tmp_list->next)
		tmp_list = tmp_list->next;
	tmp_list->next = *stack_b;
	*stack_b = tmp_list2->next;
	tmp_list2->next = NULL;
	if (b)
		ft_printf("%s\n", RB);
}

void	rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	ft_printf("%s\n", RR);
}
