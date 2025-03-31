/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:05:03 by meguetta          #+#    #+#             */
/*   Updated: 2025/03/24 10:42:23 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*tmp_list;
	t_list	*first;

	tmp_list = *list;
	first = tmp_list;
	while (tmp_list)
	{
		if (tmp_list->next == NULL)
		{
			tmp_list->next = new;
			new->prev = tmp_list;
			*list = first;
			return ;
		}
		tmp_list = tmp_list->next;
	}
}
/*
void display(t_list *list)
{
    while (list)
    {
        printf("Data: %d\n", list->content);
        if (list->prev)
            printf("Previous: %d\n", list->prev->content);
        else
            printf("Previous: NULL\n");
        list = list->next;
    }
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	int	i;

	i = 1;
	printf("ici");
	stack_a = ft_lstnew(atoi(argv[i]));
	printf("ici");
	while (i < argc)
		ft_lstadd_back(&stack_a, ft_lstnew(atoi(argv[i++])));
	printf("ici");
	display(stack_a);
	return (0);
}
*/
