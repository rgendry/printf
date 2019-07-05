/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:36:04 by blomo             #+#    #+#             */
/*   Updated: 2019/04/14 03:27:22 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	char	*str1;
	size_t	i;

	i = 0;
	str1 = str;
	while (i < len)
	{
		str1[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
