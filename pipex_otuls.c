/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_otuls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:08:31 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/07 07:57:43 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void parent(char **av, int *fd, char **ev)
{
	return ;
}
void error_and_exit(char *s, int exite)
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