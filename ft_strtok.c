/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:32:33 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/05 16:18:49 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strtok(char *str, char	*delim)
{
	static char	*p;
	char		*start;

	if (str != NULL)
		p = str;
	else if (p == NULL)
		return (NULL);
	start = p;
	while (*p && ft_strchr(delim, *p) == NULL)
		p++;
	if (*p)
		*p++ = '\0';
	return (start);
}
