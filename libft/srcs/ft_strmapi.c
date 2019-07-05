/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:05:26 by blomo             #+#    #+#             */
/*   Updated: 2019/04/10 05:31:55 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	p;
	char	*temp;

	if (!(s) || !(f))
		return (NULL);
	i = 0;
	p = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	if (!(temp = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (!i)
	{
		return (temp);
	}
	while (s[p] != '\0')
	{
		temp[p] = f(p, s[p]);
		p++;
	}
	temp[p] = '\0';
	return (temp);
}
