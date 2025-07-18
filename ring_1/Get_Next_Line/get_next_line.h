/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:26:21 by meguetta          #+#    #+#             */
/*   Updated: 2024/12/24 10:58:55 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# if BUFFER_SIZE > 16000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

// get_next_line.c //
void	*ft_free(void **ptr);
int		ft_read(int fd, char **stash);
char	*ft_stash_cpy(char *src);
void	ft_line(char **stash, char **line);
char	*get_next_line(int fd);

// get_next_line_utils.c //
int		ft_strlen(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
