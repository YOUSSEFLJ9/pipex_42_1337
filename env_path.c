/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:57:37 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/15 22:05:04 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **ev, char *vr_env)
{
	char	*vr;
	int		len;

	vr = ft_strjoin(vr_env, "=");
	if (!vr)
		error_and_exit("ft_strjoin", 1);
	len = ft_strlen(vr);
	while (ev)
	{
		if (ft_strncmp(vr, *ev, len) == 0)
			break ;
		ev++;
	}
	if (ft_strncmp(vr, *ev, len) == 0)
		return (free(vr), *ev + len);
	return (NULL);
}
