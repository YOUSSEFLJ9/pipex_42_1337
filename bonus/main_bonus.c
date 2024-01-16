/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:08:26 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/16 21:07:35 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child(char **av, int *fd, char **ev)
{
	int		outfile;

	if (close(fd[1]) == -1)
		error_and_exit("close", 1);
	outfile = open(av[5], O_CREAT | O_WRONLY | O_APPEND, 0644);
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

void	here_doc(int ac, char **av, char **ev)
{
	int		fd2[2];

	if (ac < 6)
		error_and_exit(
			"ERROR USAGE: ./pipex here_doc LIMITER cmd cmd1 file\n", -9);
	if (pipe(fd2) == -1)
		error_and_exit("pipe", 1);
	wrt_on_pipe(fd2, av[2]);
	close(fd2[1]);
	multiple_process(ac - 1, av + 1, ev, fd2[0]);
}

int	main(int ac, char **av, char **ev)
{
	if (ac < 5)
		error_and_exit("USAGE: ./pipex infile cmd1 cmd2 ...cmdn outfile\n", -9);
	if (ft_strncmp("here_doc", av[1], 9) == 0)
		here_doc(ac, av, ev);
	else
		multiple_process(ac, av, ev, -2);
	return (0);
}
