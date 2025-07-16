/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:54:52 by meguetta          #+#    #+#             */
/*   Updated: 2024/12/24 10:53:25 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (*ptr);
}

int	ft_read(int fd, char **stash)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	int		size;

	tmp = NULL;
	size = 1;
	while (size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
			return (ft_free((void **)stash), -1);
		buffer[size] = '\0';
		if (size == 0)
			break ;
		tmp = *stash;
		*stash = ft_strjoin(tmp, buffer);
		if (*stash == NULL)
			return (ft_free((void *)&tmp), -1);
		ft_free((void **)&tmp);
		if (ft_strchr(*stash, '\n'))
			break ;
	}
	return (0);
}

char	*ft_stash_cpy(char *src)
{
	int		i;
	int		src_len;
	char	*dest;

	i = 0;
	src_len = 0;
	while (src[src_len] && src[src_len] != '\n')
	{
		src_len++;
	}
	if (src[src_len] == '\n')
		src_len++;
	dest = ft_calloc(sizeof (char), (src_len + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}

void	ft_line(char **stash, char **line)
{
	char	*check;
	char	*tmp;

	*line = ft_stash_cpy(*stash);
	if (line == NULL)
		free(*line);
	check = *stash;
	tmp = ft_strchr(*stash, '\n');
	if (tmp && *tmp == '\n')
		*stash = ft_strdup(tmp + 1);
	else
		*stash = ft_strdup(tmp);
	if (check)
	{
		free(check);
		check = NULL;
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	line = NULL;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_read(fd, &stash) == -1)
		return (NULL);
	if (ft_strlen(stash))
	{
		ft_line(&stash, &line);
		return (line);
	}
	if (stash)
		free(stash);
	return (stash = NULL, line);
}

/*
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int	fd;
	int	i;
	char	*str;

	i = 0;
	fd = open(argv[1], O_RDONLY);

	while ((str = get_next_line(fd)) != NULL)
		{
			printf("%s", str);
			if (str)
			{
				free(str);
				str = NULL;
			}
		}
		close (fd);
		return (0);
}*/

/*
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
		{
			printf("str == NULL\n");
			break;
		}
		else
		{
			printf("%s\n", str);
			free(str);
			str = NULL;
		}
		return (0);
	}
}*/
