/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:49:53 by meguetta          #+#    #+#             */
/*   Updated: 2025/03/08 19:58:39 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	free_element(void *content)
{
	free(content);
}

void	ft_lstdelone(t_list *list, void (*del)(void*))
{
	if (list && del)
	{
		del((void *)list->content);
		free(list);
	}
}
