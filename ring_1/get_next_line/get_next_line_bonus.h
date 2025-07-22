/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:26:21 by meguetta          #+#    #+#             */
/*   Updated: 2024/12/25 20:42:35 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# if BUFFER_SIZE > 8192000
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

// get_next_line_bonus.c //
void	*ft_free(void **ptr);
int		ft_read(int fd, char **stash);
char	*ft_stash_cpy(char *src);
void	ft_line(char **stash, char **line);
char	*get_next_line(int fd);

// get_next_line_utils_bonus.c //
int		ft_strlen(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
