/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_otuls_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:08:31 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/09 10:09:26 by ymomen           ###   ########.fr       */
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

void	fr_split_exit(char **ptr, char *msg, int existut)
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

	paths = find_path(ev);
	paths = ft_strtok(paths, ":");
	while (*paths)
	{
		command = ft_strjoin(paths, "/");
		if (!command)
			// fr_split_exit(cmd1, "strjoin", 1);
		tmp = command;
		command = ft_strjoin(command, cmd1[0]);
		// free(tmp);
		if (!command)
			// fr_split_exit(cmd1, "strjoin", 1);
		if (execve(command, &cmd1[0], NULL) == -1)
			paths = ft_strtok(NULL, ":");
	}
	// free (command);
}

void	execute_cmd(char *av, char **ev)
{
	char	**cmd1;

	cmd1 = ft_split(av, ' ');
	if (!cmd1)
		error_and_exit("split", 1);
	if (access(cmd1[0], F_OK | X_OK) == 0)
		execve(cmd1[0], cmd1, ev);
	else
		execute_help(cmd1, ev);
	// fr_split_exit(cmd1, av, 1);
}
