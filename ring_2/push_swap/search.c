/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:26:48 by meguetta          #+#    #+#             */
/*   Updated: 2025/03/30 13:22:43 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	search_min(t_list *stack, t_bag *bag)
{
	bag->min = stack->content;
	while (stack)
	{
		if (bag->min > stack->content)
			bag->min = stack->content;
		stack = stack->next;
	}
	return (bag->min);
}

int	search_max(t_list *stack, t_bag *bag)
{
	bag->max = stack->content;
	while (stack)
	{
		if (bag->max < stack->content)
			bag->max = stack->content;
		stack = stack->next;
	}
	return (bag->max);
}

int	search_median(t_list *stack, t_bag *bag)
{
	bag->median = ft_lstsize(stack) / 2;
	return (bag->median);
}

int	search_position_min(t_list *stack, t_bag *bag)
{
	int	position;
	int	min;

	min = stack->content;
	position = 0;
	while (stack)
	{
		position++;
		if (min > stack->content)
			min = stack->content;
		if (min == search_min(stack, bag))
			break ;
		stack = stack->next;
	}
	return (position);
}

int	search_position_max(t_list *stack, t_bag *bag)
{
	bag->position = 0;
	bag->max = stack->content;
	while (stack)
	{
		bag->position++;
		if (bag->max > stack->content)
			bag->max = stack->content;
		if (bag->max == search_max(stack, bag))
			break ;
		stack = stack->next;
	}
	return (bag->position);
}
