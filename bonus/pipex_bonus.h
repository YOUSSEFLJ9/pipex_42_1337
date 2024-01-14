/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:23:32 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/15 00:43:10 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
#define PIPEX_BONUS_H

#include "get_next_line/get_next_line.h"
#include "../pipex.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <string.h>
# include <fcntl.h>

void here_doc(int ac, char **av , char **ev);
void wrt_on_pipe(int *fd, char *limiter);
void multiple_process(int ac, char **av, char **ev);

#endif