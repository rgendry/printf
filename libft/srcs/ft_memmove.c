/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:03:35 by blomo             #+#    #+#             */
/*   Updated: 2019/04/15 14:43:35 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*p;
	const unsigned char	*c;

	if (dest == src)
		return (dest);
	p = (unsigned char *)dest;
	c = (unsigned char *)src;
	i = 0;
	if (c < p)
	{
		while (++i <= len)
		{
			p[len - i] = c[len - i];
		}
	}
	else
		while (len-- > 0)
		{
			*p = *c;
			p++;
			c++;
		}
	return (dest);
}
