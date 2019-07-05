/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:04:19 by blomo             #+#    #+#             */
/*   Updated: 2019/04/14 03:35:02 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *src, int ch)
{
	while (*src)
	{
		if (*src == (unsigned char)ch)
			return ((char *)src);
		src++;
	}
	if (*src == '\0' && *src == (unsigned char)ch)
		return ((char*)src);
	return (NULL);
}
