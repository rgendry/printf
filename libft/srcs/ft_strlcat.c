/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:05:05 by blomo             #+#    #+#             */
/*   Updated: 2019/04/14 03:58:53 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t p;

	i = 0;
	j = 0;
	p = 0;
	while (dst[i] != '\0')
	{
		i++;
	}
	while (src[p] != '\0')
	{
		p++;
	}
	if (size <= i)
		p = p + size;
	else
		p = p + i;
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (p);
}
