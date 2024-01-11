/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:08:26 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/11 15:16:28 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child(char **av, int *fd, char **ev)
{
	int		outfile;

	if (close(fd[1]) == -1)
		error_and_exit("close", 1);
	outfile = open(av[5], O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (outfile == -1)
		error_and_exit(av[5], 1);
	if (dup2(outfile, 1) == -1)
		error_and_exit("dup2", 1);
	if (close(outfile) == -1)
		error_and_exit("close", 1);
	if (dup2(fd[0], 0) == -1)
		error_and_exit("dup2", 1);
	if (close(fd[0]) == -1)
		error_and_exit("close", 1);
	execute_cmd(av[4], ev);
}
void	here_doc_hlp(int id, char **av, int *fd, char **ev)
{
	int id2; 

	id2 = fork();
	if (id2 == -1)
		error_and_exit("fork", 1);
	if (id2 == 0)
		child(av, fd, ev);
	else
	{
		if (close(fd[0]) == -1 || close(fd[1]) == -1)
			error_and_exit("close", 1);
		if (waitpid(id, NULL, 0) == -1)
			error_and_exit("waitpid 1st child", 1);
		if (waitpid(id2, NULL, 0) == -1)
			error_and_exit("waitpid 2ed child", 1);
	}
}
void here_doc(int ac, char **av , char **ev)
{
	int		fd[2];
	int		fd2[2];
	int		id;
	
	if (ac != 6)
		error_and_exit("ERROR USAGE: ./pipex here_doc LIMITER cmd cmd1 file\n", -9);
	if(pipe(fd) == -1)
		error_and_exit("pipe", 1);
	id = fork();
	if (id == -1)
		error_and_exit("fork", 1);
	if (id == 0)
	{
		close(fd[0]);
		if(pipe(fd2) == -1)
			error_and_exit("pipe", 1);
		wrt_on_pipe(fd2, av[2]);
		dup2(fd2[0], 0);
		close(fd2[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		execute_cmd(av[3], ev);
	}
	else
		here_doc_hlp(id , av, fd, ev);
}
int	main(int ac, char **av, char **ev)
{
	if (ac < 5)
		error_and_exit("USAGE: ./pipex infile cmd1 cmd2 ...cmdn outfile\n", -9);
	if (ft_strncmp("here_doc", av[1], 9) == 0)
		here_doc(ac, av , ev);
	else
		
	return (0);
}
