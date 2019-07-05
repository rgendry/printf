/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:03:24 by blomo             #+#    #+#             */
/*   Updated: 2019/04/15 14:43:07 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (len == 0)
		return (0);
	i = -1;
	while (++i < len)
	{
		if (*ptr1 != *ptr2)
			return ((int)(*ptr1 - *ptr2));
		ptr2++;
		ptr1++;
	}
	return (0);
}
