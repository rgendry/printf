/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:04:43 by blomo             #+#    #+#             */
/*   Updated: 2019/04/14 03:44:29 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	if (i == (size_t)-1)
		return (NULL);
	if (!(temp = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	temp[i] = '\0';
	if (!i)
	{
		return (temp);
	}
	while (i > 0)
	{
		i--;
		temp[i] = src[i];
	}
	return (temp);
}
