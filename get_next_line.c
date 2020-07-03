/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:27:01 by mizola            #+#    #+#             */
/*   Updated: 2020/07/03 15:23:17 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char *fds[256];
	int buff;
	int readed;
	char *str_tmp;
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	buff = 	BUFFER_SIZE;
	str_tmp = malloc(BUFFER_SIZE);
	while ((readed = read(fd, str_tmp, buff)) > 0)
	{
		str_tmp[readed] = '\0';
//		printf("\n%s\n", fds[fd]);
		fds[fd] = ft_strjoin(fds[fd], str_tmp);
		printf("\n%s\n", fds[fd]);
//		free(str_tmp);//
		while (fds[fd][tmp] != '\0')
		{
			if (fds[fd][tmp] == '\n')
			{

				*line = ft_substr(fds[fd], 0, tmp);
				free(str_tmp);
				return (1);
			}
//			fds[fd][tmp];
			tmp++;
		}
//		str_tmp = malloc(buff += BUFFER_SIZE);
	}
	return 0;
}

int	main()
{

	char *line;

	line = 0x0;
	int fd = open("../test.c", O_RDONLY);
	get_next_line(fd, &line);
	get_next_line(fd, &line);

	printf("%d", fd);
}
