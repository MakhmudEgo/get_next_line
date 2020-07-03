/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:27:01 by mizola            #+#    #+#             */
/*   Updated: 2020/07/03 17:24:57 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int	get_next_line(int fd, char **line)
{
	static char *fds[256];
	int buff;
	int readed;
	char *str_tmp;
	int tmp;

	tmp = 0;
	buff = 	BUFFER_SIZE;
	str_tmp = malloc(BUFFER_SIZE);
	printf("\n%s\n", fds[fd]);
	while ((readed = read(fd, str_tmp, buff)) > 0)
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
	return 0;
}

int	main()
{

	char *line;

	line = 0x0;
	int i = 0;
	int fd = open("../test.c", O_RDONLY);
	while (i < 4)
	{
		get_next_line(fd, &line);
		printf("%s\n", line);
		i++;
	}

	printf("%d", fd);
}
