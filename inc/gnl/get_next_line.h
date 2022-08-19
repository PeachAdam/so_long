/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:13:19 by yaysu             #+#    #+#             */
/*   Updated: 2022/04/18 11:51:31 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ignore_line(char *str);
char	*find_line(char *str);
char	*set_buff(int fd, char *buff_str);
size_t	ft_strlen_a(const char *s);
char	*ft_strjoin_a(char *s1, char *s2);
char	*ft_strchr_a(const char *str, int c);
size_t	ft_strlcpy_a(char *dest, const char *src, size_t size);

#endif
