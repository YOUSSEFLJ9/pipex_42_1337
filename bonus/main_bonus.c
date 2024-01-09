/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:08:26 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/09 09:38:59 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_2(char **av, int *fd, char **ev)
{
	int		outfile;

	close(fd[1]);
	outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (outfile == -1)
		error_and_exit(av[4], 1);
	dup2(outfile, 1);
	close(outfile);
	dup2(fd[0], 0);
	close(fd[0]);
	execute_cmd(av[3], ev);
}

void	child_1(char **av, int *fd, char **ev)
{
	int		infile;

	close(fd[0]);
	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		error_and_exit(av[1], 1);
	dup2(infile, 0);
	close(infile);
	dup2(fd[1], 1);
	close(fd[1]);
	execute_cmd(av[2], ev);
}

void	parent(int ac, char **av, char **ev)
{
	int		fd[2];
	int		id;
	int		id2;

	if (pipe(fd) == -1)
		error_and_exit("pipe", 1);
	id = fork();
	if (id == -1)
		error_and_exit("fork", 1);
	if (id == 0)
		child_1(av, fd, ev);
	id2 = fork();
	if (id2 == -1)
		error_and_exit("fork", 1);
	if (id2 == 0)
		child_2(av, fd, ev);
	close(fd[0]);
	close(fd[1]);
}

int	main(int ac, char **av, char **ev)
{
	if (ac <= 5)
		error_and_exit("USAGE: ./pipex infile cmd1 cmd2 ...cmdn outfile\n", -9);
	if (waitpid(id, NULL, 0) == -1)
		error_and_exit("waitpid 1st child", 1);
	if (waitpid(id2, NULL, 0) == -1)
		error_and_exit("waitpid 2ed child", 1);
	return (0);
}
