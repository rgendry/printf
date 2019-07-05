/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:06:07 by blomo             #+#    #+#             */
/*   Updated: 2019/04/10 05:59:08 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int i;
	int j;
	int len;

	len = ft_strlen((char*)str2);
	i = 0;
	j = 0;
	while (str1[i] != '\0')
	{
		while (str1[i] == str2[j] && str2[j] != '\0' && str1[i] != '\0')
		{
			j++;
			i++;
		}
		if (j == len)
			return ((char*)str1 + i - j);
		else
			i = i - j;
		i++;
		j = 0;
	}
	if (*str1 == '\0' && *str2 == '\0')
		return ((char*)str1);
	return (NULL);
}
