/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:16:15 by yaysu             #+#    #+#             */
/*   Updated: 2022/04/18 11:52:04 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ignore_line(char *str)
{
	size_t	start;
	size_t	end;
	char	*s;

	start = 0;
	end = 0;
	while (str[start] != '\0' && str[start] != '\n')
		start++;
	start++;
	while (str[end] != '\0')
		end++;
	if (start >= end)
	{
		free(str);
		return (NULL);
	}
	s = malloc(((end - start) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	ft_strlcpy_a(s, str + start, (end - start) + 1);
	free(str);
	return (s);
}

char	*find_line(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (1)
	{
		if (str[i] == '\0')
			break ;
		else if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	s = malloc((i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[i] = '\0';
	while (i-- > 0)
		s[i] = str[i];
	return (s);
}

char	*set_buff(int fd, char *buff_str)
{
	char	*buff;
	int		bytes_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_a(buff_str, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		buff_str = ft_strjoin_a(buff_str, buff);
	}
	free(buff);
	return (buff_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff_str = set_buff(fd, buff_str);
	if (!buff_str)
		return (NULL);
	line = find_line(buff_str);
	buff_str = ignore_line(buff_str);
	if (!line)
		return (NULL);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *s;

	fd = open("text.txt", O_RDONLY);
	s = get_next_line(fd);
	
	while (s)
	{
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
	}
}

*/
