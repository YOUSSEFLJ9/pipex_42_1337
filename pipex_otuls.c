/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_otuls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:08:31 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/15 19:14:19 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_and_exit(char *s, int exite)
{
	if (exite == -9)
	{
		write(2, s, ft_strlen(s));
		exit (1);
	}
	perror(s);
	if (exite != 0)
		exit(exite);
}

static void	fr_split_exit(char **ptr, char *msg, int existut)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
		i++;
	freet(ptr, i);
	error_and_exit(msg, existut);
}

void	execute_help(char **cmd1, char **ev)
{
	char	*paths;
	char	*command;
	char	*tmp;

	paths = find_path(ev, "PATH");
	paths = ft_strtok(paths, ":");
	while (*paths)
	{
		tmp = ft_strjoin(paths, "/");
		if (!tmp)
			fr_split_exit(cmd1, "strjoin", 1);
		command = ft_strjoin(tmp, cmd1[0]);
		free(tmp);
		if (!command)
			fr_split_exit(cmd1, "strjoin", 1);
		if (execve(command, &cmd1[0], ev) == -1)
			paths = ft_strtok(NULL, ":");
		free(command);
	}
}

void	execute_cmd(char *av, char **ev)
{
	char	**cmd1;

	cmd1 = ft_split(av, ' ');
	if (!cmd1)
		error_and_exit("split", 1);
	if (cmd1[0][0] == '/' || access(cmd1[0], F_OK | X_OK) == 0)
		execve(cmd1[0], &cmd1[0], ev);
	else
		execute_help(cmd1, ev);
	fr_split_exit(cmd1, av, 1);
}
