/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_otuls_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:08:31 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/11 16:31:26 by ymomen           ###   ########.fr       */
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
