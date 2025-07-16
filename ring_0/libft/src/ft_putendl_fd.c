/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:23:26 by meguetta          #+#    #+#             */
/*   Updated: 2025/07/12 05:34:43 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
/*
int	main(int argc, char **argv)
{

	(void)argc;
	int	fd = open(argv[2], O_WRONLY);
	ft_putendl_fd(argv[1], fd);
	close(fd);
	return (0);
}*/
