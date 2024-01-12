/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:32:36 by ymomen            #+#    #+#             */
/*   Updated: 2023/11/22 17:59:34 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_it(char *str)
{
	if (str)
		free(str);
	str = NULL;
}

int	ft_strchr_1( char *s, int readit)
{
	int	i;

	i = 1;
	while (s[i - 1] || readit >= i)
	{
		if (s[i - 1] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*read_and_getline(char *buf, int fd, char *line)
{
	int	readit;
	int	endl;

	readit = 1;
	endl = 0;
	while (endl == 0 && readit > 0)
	{
		readit = read(fd, buf, BUFFER_SIZE);
		buf[readit] = '\0';
		if (readit == 0)
			return (shift(buf, BUFFER_SIZE), line);
		endl = ft_strchr_1(buf, readit);
		line = ft_strjoin_1(line, buf);
		if (!line)
			return (NULL);
		if (endl)
			shift(buf, endl);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			endl;

	line = NULL;
	endl = 0;
	if ((read(fd, buf, 0) == -1) || (2048 < fd || fd < 0))
		return (shift(buf, BUFFER_SIZE), NULL);
	if (*buf != 0)
	{
		line = ft_strjoin_1(line, buf);
		if (!line)
			return (NULL);
		endl = ft_strchr_1(buf, BUFFER_SIZE);
		if (!endl)
			shift(buf, BUFFER_SIZE);
		else
			return (shift(buf, endl), line);
	}
	return (read_and_getline(buf, fd, line));
}