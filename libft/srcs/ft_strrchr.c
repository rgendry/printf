/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:05:58 by blomo             #+#    #+#             */
/*   Updated: 2019/04/10 05:46:24 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int ch)
{
	char *p;

	p = (0);
	while (*src)
	{
		if (*src == (unsigned char)ch)
			p = (char*)src;
		src++;
	}
	if (p)
		return (p);
	if ((unsigned char)ch == '\0')
		return ((char*)src);
	return (NULL);
}
