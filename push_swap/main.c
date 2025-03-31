/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:12:20 by meguetta          #+#    #+#             */
/*   Updated: 2025/03/30 22:23:38 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_bag	*bag;
	
	if (argc <= 1)
		return (1);
	if (parcing(argc, argv) == 1)
		return (1);
	stack_a = ft_lstnew(ft_atol(argv[1]));
	stack_b = NULL;
	bag = malloc(sizeof(t_bag));
	check_arguments(&stack_a, argc, argv);
	if (check_duplicate(stack_a) == 1)
		return (free_stack(stack_a), write(2, "Error\n", 6), 1);
	if (check_if_sort(stack_a))
		return (free_stack(stack_a), 0);
	check_size(&stack_a, &stack_b, bag);
//	display_stack(&stack_a, 0);
//	display_stack(&stack_b, 1);
	free_stack(stack_a);
	return (0);
}
