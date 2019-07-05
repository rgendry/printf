/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:05:53 by blomo             #+#    #+#             */
/*   Updated: 2019/04/13 20:44:48 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*str2)
		return ((char*)str1);
	i = 0;
	while (i < len && str1[i])
	{
		j = 0;
		while (i + j < len && str1[i + j] == str2[j] && str2[j] && str1[i + j])
			j++;
		if (!str2[j])
			return ((char*)str1 + i);
		i++;
	}
	return (NULL);
}
