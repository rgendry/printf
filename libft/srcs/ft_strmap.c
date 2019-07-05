/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:05:21 by blomo             #+#    #+#             */
/*   Updated: 2019/04/11 18:19:39 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*temp;

	if (!(s) || !(f))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
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
		temp[i] = f(s[i]);
	}
	return (temp);
}
