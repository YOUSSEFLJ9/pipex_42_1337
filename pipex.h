/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:13:33 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/07 18:04:47 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

/* FUNCTIONS */
void	execute_cmd(char *av, char **ev);
void	execute_help(char **cmd1, char **ev);
char	**freet(char **ptr, int i);
void	error_and_exit(char *s, int exit);
void	parent(char **av, int *fd, char **ev);
char	*find_path(char **ev);
char	*ft_strchr(const char *s, int c);
char	*ft_strtok(char *str, char *delimter);
char	*ft_strpbrk(char *s, char *accept);
int		ft_strncmp(const char *s1, const char *s2, size_t n );
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char *s2);
void	child_1(char **av, int *fd, char **ev);
char	**ft_split(char const *s, char c);