/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:36:59 by meguetta          #+#    #+#             */
/*   Updated: 2025/03/23 06:04:15 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}
/*
int	main(int argc, char **argv)
{
	(void)	argc;
	(void)	argv;
	char	*str1 = argv[1];
	char	*str2 = argv[2];
	char	*str3 = argv[3];
	t_list	*result1 = ft_lstnew(str1);
	t_list	*result2 = ft_lstnew(str2);
	t_list	*result3 = ft_lstnew(str3);

	ft_lstadd_front(&result1, result2);
	ft_lstadd_front(&result1, result3);
	while (result1)
	{
		printf("%s\n", (char *)result1->content);
		result1 = result1->next;
	}


	if (myList == NULL)
		return (0);
	myList->content = str1;
	myList->next = NULL;
	t_list	*newNode = malloc(sizeof(t_list));
	if (newNode == NULL)
		return (0);
	newNode->content = str2;
	newNode->next = NULL;
	t_list	*newNode2 = malloc(sizeof(t_list));
	if (newNode2 == NULL)
		return (0);
	newNode2->content = str3;
	newNode2->next = NULL;

	return (0);
}*/
