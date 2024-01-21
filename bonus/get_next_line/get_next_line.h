/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:32:33 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/21 21:08:23 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 
# define BUFFER_SIZE 42
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
/* FUNCTIONS */
char	*read_and_getline(char *buf, int fd, char *line);
void	free_it(char *str);
char	*ft_strjoin_1(char *line, char *buf);
void	shift(char *buf, int endl);
int		ft_strlen_1(char *s);
int		ft_strchr_1( char *s, int readit);
char	*get_next_line(int fd);
#endif