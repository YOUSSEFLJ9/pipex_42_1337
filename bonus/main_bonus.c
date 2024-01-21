/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:08:26 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/21 20:54:50 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	here_doc(int ac, char **av, char **ev)
{
	int		fd2;

	if (ac < 6)
		error_and_exit(
			"ERROR USAGE: ./pipex here_doc LIMITER cmd cmd1 file\n", -9);
	fd2 = open("/tmp/here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd2 == -1)
		error_and_exit("open", 1);
	wrt_on_pipe(&fd2, av[2]);
	if (close(fd2) == -1)
		error_and_exit("close", 1);
	multiple_process(ac - 1, av + 1, ev, fd2);
	if (unlink("/tmp/here_doc") == -1)
		error_and_exit("unlink", 1);
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
