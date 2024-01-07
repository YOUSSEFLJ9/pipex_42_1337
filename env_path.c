/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:57:37 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/07 18:04:07 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **ev)
{
	while (ev)
	{
		if (ft_strncmp("PATH=", *ev, 5) == 0)
			break ;
		ev++;
	}
	if (ft_strncmp("PATH=", *ev, 5) == 0)
		return (*ev + 5);
	return (NULL);
}
