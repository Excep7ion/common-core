/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:38:16 by meguetta          #+#    #+#             */
/*   Updated: 2024/11/28 15:18:06 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
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

	printf("%d", ft_lstsize(result1));
	return (0);
}*/
