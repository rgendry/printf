/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:09:31 by blomo             #+#    #+#             */
/*   Updated: 2019/05/12 20:26:38 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*p;
	const unsigned char *c;

	if (dest == src)
		return (dest);
	p = (unsigned char *)dest;
	c = (unsigned char *)src;
	i = 0;
	while (i < len)
	{
		p[i] = c[i];
		i++;
	}
	return (dest);
}
