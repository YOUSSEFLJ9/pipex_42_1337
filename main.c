/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:08:26 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/07 08:03:15 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_1(char **av, int *fd, char **ev)
{
	char	**cmd1;
	char	*paths;
	char	*command;
	int		infile;

	close(fd[0]);
	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		error_and_exit(av[1], 1);
	dup2(infile, 0);
	close(infile);
	dup2(fd[1], 1);
	close(fd[1]);
	cmd1 = ft_split(av[2], ' ');
	if (access(cmd1[0],F_OK) == 0)
		execve(cmd1[0], &cmd1[0], NULL);
	else
	{
		paths = find_path(ev);
		paths = ft_strtok(paths, ":");
		while (*paths)
		{
			command = ft_strjoin(paths, "/");
			command = ft_strjoin(command, cmd1[0]);
			if (execve(command, &cmd1[0], NULL) == -1)
				paths = ft_strtok(NULL, ":");
		}
	}
	error_and_exit(*cmd1, 1);
}

int	main(int ac, char **av, char **ev)
{
	int		fd[2];
	int		id;
	int		id2;

	if (ac != 5)
		error_and_exit("USAGE: ./pipex infile cmd1 cmd2 outfile\n" ,-9);
	if (pipe(fd) == -1)
		error_and_exit("pipe", 1);
	id = fork();
	if (id == -1)
		error_and_exit("fork", 1);
	if (id == 0)
		child_1(av, fd, ev);
	else
		parent(av, fd, ev);
	return (0);
}
