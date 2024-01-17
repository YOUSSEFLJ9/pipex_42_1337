/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:13:33 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/17 11:30:28 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "bonus/get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

/* FUNCTIONS */
void	execute_cmd(char *av, char **ev);
void	execute_help(char **cmd1, char **ev);
char	**freet(char **ptr, int i);
void	error_and_exit(char *s, int exit);
void	parent(char **av, int *fd, char **ev);
char	*find_path(char **ev, char *vr_env);
char	*ft_strchr(const char *s, int c);
char	*ft_strtok(char *str, char *delimter);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char *s2);
void	child_1(char **av, int *fd, char **ev);
char	**ft_split(char const *s, char c);
/*BONUS*/
void	here_doc(int ac, char **av, char **ev);
void	wrt_on_pipe(int *fd, char *limiter);
void	multiple_process(int ac, char **av, char **ev, int infile);

#endif