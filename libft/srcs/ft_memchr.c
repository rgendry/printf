/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:03:20 by blomo             #+#    #+#             */
/*   Updated: 2019/04/14 03:09:16 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *src, int ch, size_t len)
{
	while (len--)
	{
		if (*(unsigned char *)src == (unsigned char)ch)
			return ((void *)src);
		src++;
	}
	return (NULL);
}
