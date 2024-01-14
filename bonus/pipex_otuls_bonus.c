/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_otuls_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:08:31 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/15 00:44:03 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"


void wrt_on_pipe(int *fd, char *limiter)
{
	char *line;	
	// if (close(fd[0]) == -1)
	// 	error_and_exit("close", 1);
	line = " ";
	while (line)
	{
		line = get_next_line(0);
		if (!line)
			error_and_exit("can get the line from stdin.", -9);
		if ((ft_strncmp(line, limiter, ft_strlen(limiter)) == 0) && (ft_strlen(line) == ft_strlen(limiter) + 1))
			{
				free(line);
				return ;
			}
		if (write(fd[1], line, ft_strlen(line)) == -1)
			error_and_exit("write", 1);
		free(line);
	}
}
int open_file(char *av, char c)
{
	int fd = 0;

	if (c == 'c')
		fd = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (c == 'o')
		fd = open(av, O_RDONLY);
	if(fd == -1)
		error_and_exit("open", 1);
	return (fd);
}

void child_process (char *av, char **ev)
{
	int fd[2];
	int id;
	id = fork();
	if (id == -1)
		error_and_exit("fork", 1);
	if (id == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		execute_cmd(av, ev);
	}
	else
	{
		close(fd[1]);
		waitpid(id, NULL, 0);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

void multiple_process(int ac, char **av, char **ev)
{
	int infile;
	int outfile;
	int	cont;

	cont = 2;
	infile = open_file(av[ ac - 1], 'c');
	outfile = open_file(av[1], 'o');
	while (cont < ac - 2)
		child_process(av[cont++], ev);
	dup2(outfile, 1);
	close(outfile);
	execute_cmd(av[ac - 2], ev);
}

