/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:05:34 by blomo             #+#    #+#             */
/*   Updated: 2019/04/13 17:52:06 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && n > 0)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		n--;
	}
	if (n == 0 && i != 0)
		i--;
	if ((s1[i] == '\0' && s2[i] != '\0') || (s2[i] == '\0' && s1[i] != '\0'))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
