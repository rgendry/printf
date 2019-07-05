/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:03:14 by blomo             #+#    #+#             */
/*   Updated: 2019/04/15 14:42:07 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dest, const void *src, int ch, size_t len)
{
	size_t				i;
	unsigned char		*p;
	const unsigned char	*c;

	if (dest == src)
		return (dest);
	p = (unsigned char *)dest;
	c = (unsigned char *)src;
	i = 0;
	while (i < len)
	{
		p[i] = c[i];
		if (p[i] == (unsigned char)ch)
			return ((void *)(dest + i + 1));
		i++;
	}
	return (NULL);
}
