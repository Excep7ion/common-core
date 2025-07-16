/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:49:57 by meguetta          #+#    #+#             */
/*   Updated: 2024/12/17 14:52:13 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/*
read :
ssize_t read(int fd, void *buf, size_t count)

write :
ssize_t write(int fd, const void *buf, size_t count);
*/

int	main(int argc, char **argv)
{
	int		fd;
	char	buffer[4];
	int		size;

	if (argc == 1)
		write(1, "File name missing.\n", 19);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		size = read(fd, buffer, 4);
		if (fd == -1)
		{
			write(1, "Cannot read file.\n", 18);
			return (1);
		}
		while (size > 0)
		{
			write(1, buffer, size);
			size = read(fd, buffer, 4);
		}
		close(fd);
	}
	if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	return (0);
}
