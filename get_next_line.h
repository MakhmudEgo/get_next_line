/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:28:39 by mizola            #+#    #+#             */
/*   Updated: 2020/07/01 15:24:00 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_GET_NEXT_LINE_H
# define G_GET_NEXT_LINE_H
# define BUFFER_SIZE 10

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int line_len;
	int buff;
} t_data;

int get_next_line(int fd, char **line);
int ft_strlen(const char *str);
int	ft_strlcpy(char *dst, const char *src, int siz);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif

