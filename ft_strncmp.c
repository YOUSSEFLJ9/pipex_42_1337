/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:24:44 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/11 15:31:15 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n )
{
	size_t	k;

	k = 0;
	if ((!s1 && !s2) || n == 0)
		return (1);
	while (s1[k] && s2[k] && s1[k] == s2[k] && k < n - 1)
		k++;
	return ((unsigned char) s1[k] - (unsigned char) s2[k]);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	k;

	k = 0;
	if ((!s1 && !s2))
		return (0);
	while (s1[k] && s2[k] && s1[k] == s2[k])
		k++;
	return ((unsigned char) s1[k] - (unsigned char) s2[k]);
}