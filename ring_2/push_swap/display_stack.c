/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:06:46 by meguetta          #+#    #+#             */
/*   Updated: 2025/04/01 06:37:25 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	display_stack(t_list **stack, int b)
{
	t_list	*list_ptr;

	list_ptr = *stack;
	if (b == 0)
		ft_printf("stack_a\n");
	else
		ft_printf("stack_b\n");
	while (list_ptr)
	{
		ft_printf("%d\n", list_ptr->content);
		list_ptr = list_ptr->next;
	}
	ft_printf("\n");
}
