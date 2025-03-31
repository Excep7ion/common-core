/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:27:06 by meguetta          #+#    #+#             */
/*   Updated: 2025/03/30 20:47:24 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	algo(t_list **stack_a, t_list **stack_b, t_bag *bag)
{
//	display_stack(stack_a, 0);
//	display_stack(stack_b, 1);

	while (*stack_a)
	{
//		ft_printf("ALGO :\n");
//		display_stack(stack_a, 0);
//		display_stack(stack_b, 1);
		count_operations(*stack_a, *stack_b, bag);
//		display_stack(stack_a, 0);
//		display_stack(stack_b, 1);
//		printf("stack_a = %d\n", (*stack_a)->content);
//		printf("stack_b = %d\n", (*stack_b)->content);
//		printf("min_operations = %d\n\n", bag->min_operations);

		execute_operations(stack_a, stack_b, bag);
		//		printf("bag->min_operations = %d\n", bag->min_operations);
	}
	execute_operations_next(stack_a, stack_b, bag);
	push_a(stack_a, stack_b);
}

void	count_operations(t_list *stack_a, t_list *stack_b, t_bag *bag)
{
//	printf("COUNT_OPERATIONS :\n");
	int	position;
	bag->copie_a = stack_a;
	bag->size = ft_lstsize(stack_a);
	position = 0;
	bag->min_operations = INT_MAX;
	while (bag->copie_a)
	{
//		printf("\nstack_a = %d\n", bag->copie_a->content);
		bag->count_rb = 0;
		bag->count_rrb = 0;
		bag->count_ra = 0;
		bag->count_rra = 0;
		bag->count_rr = 0;
		bag->count_rrr = 0;
//		printf("Position stack_a: %d\n", position);
//		printf("Médiane stack_a: %d\n", search_median(stack_a, bag));
		if (position <= search_median(stack_a, bag))
		{
			bag->count_ra = position;
//			printf("ra = %d\n", bag->count_ra);
		}
		else
		{
//			printf("size = %d\n", ft_lstsize(stack_a));
//			printf("position = %d\n", position);
			bag->count_rra = ft_lstsize(stack_a) - position;
//			printf("rra = %d\n", bag->count_rra);
		}
		bag->target_position = target_position(bag->copie_a->content, stack_b, bag);
//		printf("target_position = %d\n", bag->target_position);
		if (bag->target_position <= search_median(stack_b, bag))
		{
			bag->count_rb = bag->target_position;
//			printf("rb = %d\n", bag->count_rb);
		}
		else	
		{
			bag->count_rrb = ft_lstsize(stack_b) - bag->target_position;
//			printf("rrb = %d\n", bag->count_rrb);
		}
//		printf("count_ra = %d\n", bag->count_ra);
//		printf("count_rra = %d\n", bag->count_rra);
//		printf("count_rb = %d\n", bag->count_rb);
//		printf("count_rrb = %d\n", bag->count_rrb);
		if (bag->count_ra > 0 && bag->count_rb > 0)
		{
			bag->count_rr = count_rr(bag->count_ra, bag->count_rb, bag);
			while (bag->count_ra > 0 && bag->count_rb > 0)
			{
				bag->count_ra--;
				bag->count_rb--;
			}
		}
		if (bag->count_rra > 0 && bag->count_rrb > 0)
		{
			bag->count_rrr = count_rrr(bag->count_rra, bag->count_rrb, bag);
			while (bag->count_rra > 0 && bag->count_rrb > 0)
			{
				bag->count_rra--;
				bag->count_rrb--;
			}
		}
//		printf("count_rr = %d\n", bag->count_rr);
//		printf("count_rrr = %d\n", bag->count_rrr);
		bag->tmp
			= bag->count_ra
			+ bag->count_rra
			+ bag->count_rb
			+ bag->count_rrb
			+ bag->count_rr
			+ bag->count_rrr;
//		printf("tmp = %d\n", bag->tmp);
		if (bag->tmp < bag->min_operations)
		{
			bag->winner = bag->copie_a->content;
//			search_winner(bag->winner, bag);
			bag->min_operations = bag->tmp;
		}
//		printf("min_operations = %d\n", bag->min_operations);
		position++;
		bag->copie_a = bag->copie_a->next;
	}
//	printf("\nle winner est %d\n", bag->winner);
//	printf("min_operations (+1 pour pb) = %d\n\n", bag->min_operations + 1);
}


int	target_position(int content, t_list *stack_b, t_bag *bag)
{
//	printf("TARGET_POSITION :\n");
//	printf("content = %d\n", content);
	bag->size = ft_lstsize(stack_b);
	if (content > search_max(stack_b, bag)
			|| content < search_min(stack_b, bag))
	{
		bag->target_position = max_position(stack_b, bag);
//		printf("*max* target_position = %d\n", bag->target_position);
	}
	else
	{
		bag->target_position = lower_position_close(stack_b, content, bag);
		//bag->target_position = bag->size - bag->target_position;
//		printf("*lower* target_position = %d\n", bag->target_position);
	}
	return (bag->target_position);
}

int	max_position(t_list *stack_b, t_bag *bag)
{
	bag->max = search_max(stack_b, bag);
	bag->position = 0;
	bag->copie_b = stack_b;
	while (bag->max != bag->copie_b->content)
	{
		bag->position++;
		bag->copie_b = bag->copie_b->next;
	}
	return (bag->position);
}

int	lower_position_close(t_list *stack_b, int content, t_bag *bag)
{
	bag->copie_b = stack_b;
	bag->position = 0;
	bag->tmp = 0;
	while (stack_b)
	{
		if (content > stack_b->content && stack_b->content > bag->tmp)
		{
			bag->tmp = stack_b->content;
		}
		stack_b = stack_b->next;
	}
	while (bag->tmp != bag->copie_b->content)
	{
		bag->position++;
		bag->copie_b = bag->copie_b->next;
	}
	return (bag->position);
}
/*
int	max_position_rb(t_list *stack_b, t_bag *bag)
{
	bag->position = 0;
	bag->max = search_max(stack_b, bag);
//	ft_printf("ici7\n");
	while (bag->max != stack_b->content)
	{
		bag->position++;
		stack_b = stack_b->next;
	}
	printf("position_rb = %d\n", bag->position);
	return (bag->position);
}

int	max_position_rrb(t_list *stack_b, t_bag *bag)
{
	bag->copie_b = stack_b;
	bag->max = search_max(stack_b, bag);
	bag->index = ft_lstsize(stack_b);
	bag->position = 0;
	while (bag->index > bag->position)
	{
		bag->position++;
		bag->copie_b = bag->copie_b->next;
		bag->index--;
	}
	printf("position_rrb = %d\n", bag->position);
	return (bag->position);
}

int	lower_position_close(t_list *stack_b, int content, t_bag *bag)
{
	bag->copie_b = stack_b;
	bag->position = 0;
	bag->tmp = 0;
	bag->position = lower_position_close_rrb(stack_b, content, bag);

	printf("lower_position_close = %d\n", bag->position);
	return (bag->position);
}

int	count_max_rb(t_list *stack_b, t_bag *bag)
{
	bag->position = max_position_rb(stack_b, bag);
	bag->count_rb = 0;
	while (bag->position > 0)
	{
		bag->position--;
		bag->count_rb++;
	}
	printf("max_count_rb = %d\n", bag->count_rb);
	return (bag->count_rb);
}

int	count_max_rrb(t_list *stack_b, t_bag *bag)
{
	bag->position = max_position_rrb(stack_b, bag);
	bag->count_rrb = 0;
	bag->size = ft_lstsize(stack_b);
	while (stack_b->next)
		stack_b = stack_b->next;
	while (bag->size - bag->position > 0)
	{
		bag->position++;
		bag->count_rrb++;
		printf("stack_b->content = %d\n", stack_b->content);
		stack_b = stack_b->prev;
	}
	printf("max_count_rrb = %d\n", bag->count_rrb);
	return (bag->count_rrb);
}

int	count_lower_close_rb(t_list *stack_b, int content, t_bag *bag)
{
	bag->position = lower_position_close_rb(stack_b, content, bag);
	bag->count_rb = 0;
	while (bag->position > 0)
	{
		bag->position--;
		bag->count_rb++;
	}
	printf("lower_close_count_rb = %d\n", bag->count_rb);
	return (bag->count_rb);
}

int	count_lower_close_rrb(t_list *stack_b, int content, t_bag *bag)
{
	bag->position = lower_position_close_rrb(stack_b, content, bag);
	bag->count_rrb = 0;
	while (stack_b)
//	ft_printf("ici9\n");
	while (bag->copie_b)
	{
		if (content > bag->copie_b->content && bag->copie_b->content > bag->tmp)
		{
			bag->tmp = bag->copie_b->content;
		}
		bag->copie_b = bag->copie_b->next;
	}
	bag->copie_b = stack_b;
//	ft_printf("ici9,25\n");
	while (bag->tmp != bag->copie_b->content)
	{
		bag->position++;
		bag->copie_b = bag->copie_b->next;
	}
//	ft_printf("ici9,5\n");
	if (bag->position <= search_median(stack_b, bag))
		bag->position = lower_position_close_rb(stack_b, content, bag);
	else
		bag->position = lower_position_close_rrb(stack_b, content, bag);

	printf("lower_position_close = %d\n", bag->position);
	return (bag->position);
}

int	lower_position_close_rb(t_list *stack_b, int content, t_bag *bag)
{

	bag->position = 0;
	bag->tmp = 0;
	bag->copie_b = stack_b;
//	ft_printf("ici10\n");
	while (bag->copie_b)
	{
		if (content > bag->copie_b->content && bag->copie_b->content > bag->tmp)
		{
			bag->tmp = bag->copie_b->content;
		}
		bag->copie_b = bag->copie_b->next;
	}
//	ft_printf("ici11\n");
//	ft_printf("tmp = %d\n", bag->tmp);
//	ft_printf("valeur de 2 = %d\n", stack_b->content);
	while (bag->tmp != stack_b->content)
	{
//		ft_printf("ici12\n");
		bag->position++;
		stack_b = stack_b->next;
	}
//	ft_printf("ici13\n");
	printf("lower_position_close_rb = %d\n", bag->position);
	return (bag->position);
}

int	lower_position_close_rrb(t_list *stack_b, int content, t_bag *bag)
{
	bag->position = 0;
	bag->tmp = 0;
	while (stack_b)
	{
		if (content > stack_b->content && stack_b->content > bag->tmp)
		{
			bag->tmp = stack_b->content;
		}
		stack_b = stack_b->next;
	}
	while (bag->tmp != stack_b->content)
	{
		bag->position++;
		stack_b = stack_b->prev;
	}
	printf("lower_position_close_rrb = %d\n", bag->position);
	return (bag->position);
}

int	count_rb_max_position(t_list *stack_b, t_bag *bag)
{
	bag->position = max_position_rb(stack_b, bag);
	bag->count_rb = 0;
	while (bag->position > 0)
	{
		bag->position--;
		bag->count_rb++;
	}
	printf("max_count_rb = %d\n", bag->count_rb);
	return (bag->count_rb);
}

int	count_rrb_max_position(t_list *stack_b, t_bag *bag)
{
	bag->position = max_position_rrb(stack_b, bag);
	bag->count_rrb = 0;
	bag->size = ft_lstsize(stack_b);
	while (stack_b->next)
		stack_b = stack_b->next;
	while (bag->size - bag->position > 0)
	{
		bag->position++;
		bag->count_rrb++;
		printf("stack_b->content = %d\n", stack_b->content);
		stack_b = stack_b->prev;
	}
	printf("max_count_rrb = %d\n", bag->count_rrb);
	return (bag->count_rrb);
}

int	count_rb_lower_close(t_list *stack_b, int content, t_bag *bag)
{
	bag->position = lower_position_close_rb(stack_b, content, bag);
	bag->count_rb = 0;
	while (bag->position > 0)
	{
		bag->position--;
		bag->count_rb++;
	}
	printf("lower_close_count_rb = %d\n", bag->count_rb);
	return (bag->count_rb);
}

int	count_rrb_lower_close(t_list *stack_b, int content, t_bag *bag)
{
	bag->position = lower_position_close_rrb(stack_b, content, bag);
	bag->count_rrb = 0;
	while (stack_b)
		stack_b = stack_b->next;
	while (ft_lstsize(stack_b) - bag->position != 0)
	{
		bag->position++;
		bag->count_rrb++;
		stack_b = stack_b->prev;
	}
	printf("lower_count_rrb = %d\n", bag->count_rrb);
	return (bag->count_rrb);
}
*/
