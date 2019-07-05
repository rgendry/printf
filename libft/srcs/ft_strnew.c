/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:05:49 by blomo             #+#    #+#             */
/*   Updated: 2019/04/15 16:57:50 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	if (size > size + 1)
		return (NULL);
	i = 0;
	ptr = (0);
	if (!(ptr = (char *)malloc(size + 1)))
		return (NULL);
	while (i < size + 1)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
