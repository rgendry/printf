/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:08:24 by blomo             #+#    #+#             */
/*   Updated: 2019/04/15 14:39:00 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(char const *s, size_t start, char c)
{
	while (s[start] != '\0' && s[start] == c)
	{
		start++;
	}
	return (start);
}

static size_t	ft_end(char const *s, size_t end, char c)
{
	while (s[end] != '\0' && s[end] != c)
	{
		end++;
	}
	return (end);
}

size_t			ft_count_word(char const *s, char c)
{
	size_t count;
	size_t start;
	size_t end;

	start = 0;
	count = 0;
	start = ft_start(s, start, c);
	end = ft_end(s, start, c);
	while (start - end != 0 && *s)
	{
		count++;
		start = ft_start(s, end, c);
		end = ft_end(s, start, c);
	}
	return (count);
}
