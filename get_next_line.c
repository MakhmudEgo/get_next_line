/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:27:01 by mizola            #+#    #+#             */
/*   Updated: 2020/07/01 15:55:56 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char	hello[BUFFER_SIZE];
	t_data		str;
	int			tmp;
	int 		n;

	n = 0;
	str.buff = BUFFER_SIZE;
	str.line_len = ft_strlen(*line);
	while ((tmp = read(fd, hello, str.buff)) > 0)
	{
		hello[tmp] = '\0';
		while (hello[n] != '\0')
		{
			if (hello[n] == '\n' && str.line_len <= n)
			{
				*line = ft_substr(hello, 0, str.buff);
				return (1);
			}
			n++;
		}
		if (hello[n] == '\0')
		{

		}
	}
	*line = malloc(sizeof(char) * str.buff);
//	printf("%d\n%s\n", ij, hello);
	return 0;
}

int	main()
{

	char *line;

	line = 0x0;
	int fd = open("../test.c", O_RDONLY);
	get_next_line(fd, &line);
	printf("%d", fd);
}
