/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:06:11 by blomo             #+#    #+#             */
/*   Updated: 2019/04/13 21:22:41 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	p;
	char	*temp;

	p = 0;
	if (!(s))
		return (NULL);
	if (!(temp = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len && s[start] != '\0')
	{
		temp[p] = s[start];
		p++;
		len--;
		start++;
	}
	temp[p] = '\0';
	return (temp);
}
