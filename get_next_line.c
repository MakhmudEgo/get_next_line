/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:27:01 by mizola            #+#    #+#             */
/*   Updated: 2020/07/04 17:22:19 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *if_return_value_zero(char **s)
{
	char *tmp;
	int i;
	char *line;

	i = 0;
	tmp = *s;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
		{
			line = ft_substr(*s, 0, i);//
			tmp = ft_substr(*s, i + 1, ft_strlen(*s) - i + 1);
			free(*s);
			*s = tmp;
			return (line);
		}
		i++;
	}
	return (0x0);
}

int	get_next_line(int fd, char **line)
{
	static char *fds[256];
	int readed;
	char *str_tmp;
	int tmp;

	tmp = 0;
	str_tmp = malloc(BUFFER_SIZE);
	while ((readed = read(fd, str_tmp, BUFFER_SIZE)) > 0)
	{
		str_tmp[readed] = '\0';
		fds[fd] = ft_strjoin(fds[fd], str_tmp);
		while (fds[fd][tmp] != '\0')
		{
			if (fds[fd][tmp] == '\n')
			{
				*line = ft_substr(fds[fd], 0, tmp);
				free(str_tmp);
				str_tmp = ft_strdup(fds[fd] + tmp + 1);
				free(fds[fd]);
				fds[fd] = str_tmp;
				return (1);
			}
			tmp++;
		}
	}
	if (readed == 0)
		*line = if_return_value_zero(&fds[fd]);
	if (fds[fd][0] != '\0')
	{
		free(fds[fd]);
		return 0;
	}
	return (1);
}

int	main()
{

	char *line;

	line = 0x0;
	int i = 0;
	int fd = open("../test.c", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		i++;
	}
//	printf("%s\n", line);

}
