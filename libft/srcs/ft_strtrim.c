/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:06:17 by blomo             #+#    #+#             */
/*   Updated: 2019/04/11 19:34:45 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(char const *s, int p)
{
	while (s[p] == ' ' || s[p] == '\n' || s[p] == '\t')
	{
		p++;
	}
	return (p);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	char	*temp;
	size_t	p;
	size_t	l;

	i = 0;
	p = 0;
	l = 0;
	if (!(s))
		return (NULL);
	i = ft_strlen((char*)s);
	p = ft_space(s, p);
	if (i != p)
	{
		while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		{
			i--;
		}
	}
	if (!(temp = (char*)malloc(sizeof(char) * (i - p + 1))))
		return (NULL);
	while ((i - p) > 0)
		temp[l++] = s[p++];
	temp[l] = '\0';
	return (temp);
}
