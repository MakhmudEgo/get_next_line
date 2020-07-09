/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:28:39 by mizola            #+#    #+#             */
/*   Updated: 2020/07/09 15:15:09 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_GET_NEXT_LINE_H
# define G_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

int				get_next_line(int fd, char **line);
int				ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char const *s2);
char			*ft_strdup(const char *s1);

#endif
