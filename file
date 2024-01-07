/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:08:26 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/07 04:25:59 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_1(char **av, int *fd, char **ev)
{
	char	**cmd1;
	char	*paths;
	char	*command;

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
	perror(*cmd1);
	fprintf(stderr, "Error code: %d\n", errno);
	exit(1);
}

int	main(int ac, char **av, char **ev)
{
	int		fd[2];
	int		id;
	int		id2;

	if (ac != 5)
		exit(1);
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	id = fork();
	if (id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (id == 0)
		child_1(av, fd, ev);
	else
	{
		int k;
		wait(&k);
		parent(av, fd, ev);
	}
	return (0);
}
