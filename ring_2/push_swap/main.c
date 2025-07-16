/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:12:20 by meguetta          #+#    #+#             */
/*   Updated: 2025/04/02 07:31:37 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	include_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_bag	*bag;

	if (argc <= 1)
		return (1);
	if (parsing(argc, argv) == 1 || ft_strlen(argv[1]) == 0)
		return (write(2, "Error\n", 6), 1);
	if (include_space(argv[1]) && argc > 2)
		return (write(2, "Error\n", 6), 1);
	stack_a = ft_lstnew(ft_atol(argv[1]));
	stack_b = NULL;
	bag = malloc(sizeof(t_bag));
	check_arguments(&stack_a, argc, argv);
	if (check_duplicate(stack_a) == 1)
		return (free_stack(stack_a), free(bag), write(2, "Error\n", 6), 1);
	if (check_if_sort(stack_a))
		return (free_stack(stack_a), free(bag), 0);
	check_size(&stack_a, &stack_b, bag);
	free_stack(stack_a);
	free(bag);
	return (0);
}
