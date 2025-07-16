/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:05:17 by meguetta          #+#    #+#             */
/*   Updated: 2025/04/02 08:00:02 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_overflow(char **argv, int b)
{
	int	i;

	i = 0;
	if (b == 0)
		i++;
	while (argv[i])
	{
		if ((argv[i][0] == '-' && ft_strlen(argv[i]) > 11)
			&& ft_strlen(argv[i]) > 10)
			return (1);
		if (ft_atol(argv[i]) < INT_MIN || ft_atol(argv[i]) > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

void	check_arguments(t_list **stack_a, int argc, char **argv)
{
	int		i;
	char	**tab;

	i = 1;
	tab = NULL;
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		while (tab[i])
			ft_lstadd_back(stack_a, ft_lstnew(ft_atol(tab[i++])));
		i = 0;
		while (tab[i])
			free(tab[i++]);
		free (tab);
	}
	else if (argc > 2)
	{
		i = 2;
		while (i < argc)
			ft_lstadd_back(stack_a, ft_lstnew(ft_atol(argv[i++])));
	}
}

void	check_size(t_list **stack_a, t_list **stack_b, t_bag *bag)
{
	if (ft_lstsize(*stack_a) == 2)
		swap_a(stack_a, 1);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort_four(stack_a, stack_b, bag);
	else if (ft_lstsize(*stack_a) == 5)
		sort_five(stack_a, stack_b, bag);
	else if (ft_lstsize(*stack_a) > 5)
		sort_one_hundred(stack_a, stack_b, bag);
}

int	check_duplicate(t_list *stack_a)
{
	t_list	*list_ptr;
	t_list	*list_ptr2;

	list_ptr = stack_a;
	list_ptr2 = stack_a;
	while (list_ptr)
	{
		list_ptr2 = list_ptr->next;
		while (list_ptr2)
		{
			if (list_ptr->content == list_ptr2->content)
				return (1);
			list_ptr2 = list_ptr2->next;
		}
		list_ptr = list_ptr->next;
	}
	return (0);
}

int	check_if_sort(t_list *stack_a)
{
	while (stack_a)
	{
		if (stack_a->next == NULL)
			return (1);
		if (stack_a->content < stack_a->next->content)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (0);
}
