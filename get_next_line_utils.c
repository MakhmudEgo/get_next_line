/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:28:27 by mizola            #+#    #+#             */
/*   Updated: 2020/07/03 14:55:09 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_strlcpy(char *dst, const char *src, int siz)
{
	int i;

	i = 0;
	if (!src)
		return (0);
	if (siz == 0)
		return (ft_strlen(src));
	while (i < siz - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = ft_strlen(s1) + 1;
	str = (char*)malloc(sizeof(*str) * i);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
//	if (ft_strlen(s) < start)
//		return (ft_strdup(""));
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	len;
	unsigned int	i;
	unsigned int	n;

//	if (!s1 || !s2)
//		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = 0;
	n = 0;
	str = (char*)malloc(len);
	if (str == NULL)
		return (NULL);
	while (s1 && s1[n] != '\0')
		str[i++] = s1[n++];
	n = 0;
	while (s2[n] != '\0')
		str[i++] = s2[n++];
	str[i] = '\0';
	return (str);
}