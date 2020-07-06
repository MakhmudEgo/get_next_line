/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:27:01 by mizola            #+#    #+#             */
/*   Updated: 2020/07/06 21:54:45 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	if_one_line(char **line, char **fds, const int *tmp, char **str_tmp)
{
	*line = ft_substr(*fds, 0, *tmp + 1);
	if (*str_tmp)
		free(*str_tmp);
	if (*fds)
		free(*fds);
	*fds = 0x0;
	return (0);
}

static int	if_return_value_zero(char **s, char **line, char **str_tmp)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = *s;
	while (tmp && tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
		{
			*line = ft_substr(*s, 0, i);
			tmp = ft_substr(*s, i + 1, ft_strlen(*s) - i + 1);
			free(*s);
			*s = tmp;
			return (1);
		}
		i++;
	}
	if (tmp && tmp[i] == '\0')
		return (if_one_line(&(*line), &tmp, &i, &(*str_tmp)));
	free(*s);
	free(*str_tmp);
	*line = ft_strdup("");
	return (0);
}

static int	if_line_break(char **line, char **fds,
		const int *tmp, char **str_tmp)
{
	*line = ft_substr(*fds, 0, *tmp);
	free(*str_tmp);
	*str_tmp = ft_strdup(*fds + *tmp + 1);
	free(*fds);
	*fds = *str_tmp;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*fds[256];
	char		*str_tmp;
	int			tmp;
	int			readed;

	tmp = 0;
	str_tmp = malloc(BUFFER_SIZE + 1);
	if (!str_tmp || !line || fd < 0)
		return (-1);
	while ((readed = read(fd, str_tmp, BUFFER_SIZE)) > 0)
	{
		str_tmp[readed] = '\0';
		fds[fd] = ft_strjoin(&fds[fd], str_tmp);
		while (fds[fd][tmp] != '\0')
		{
			if (fds[fd][tmp] == '\n')
				return (if_line_break(&(*line), &fds[fd], &tmp, &str_tmp));
			tmp++;
		}
	}
	if (fds[fd] && fds[fd][tmp] == '\0')
		return (if_one_line(&(*line), &fds[fd], &tmp, &str_tmp));
	if (readed == 0)
		return (if_return_value_zero(&fds[fd], &(*line), &str_tmp));
	return (-1);
}
