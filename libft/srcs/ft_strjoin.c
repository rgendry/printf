/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:05:00 by blomo             #+#    #+#             */
/*   Updated: 2019/04/11 18:21:48 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	size1;
	unsigned int	size2;
	char			*ptr;

	i = 0;
	if (!(s1) || !(s2))
		return (NULL);
	size1 = ft_strlen((char*)s1);
	size2 = ft_strlen((char*)s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (size1 + size2 + 1))))
		return (NULL);
	while (*s1)
	{
		ptr[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		ptr[i] = *s2;
		s2++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
