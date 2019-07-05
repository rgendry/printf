/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:06:03 by blomo             #+#    #+#             */
/*   Updated: 2019/04/15 14:34:24 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_start(char const *s, size_t start, char c)
{
	while (s[start] != '\0' && s[start] == c)
	{
		start++;
	}
	return (start);
}

static size_t		ft_end(char const *s, size_t end, char c)
{
	while (s[end] != '\0' && s[end] != c)
	{
		end++;
	}
	return (end);
}

static char			*ft_out(char const *s, size_t start, size_t end)
{
	char		*ptr;
	size_t		i;

	i = 0;
	if (!(ptr = (char*)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	while (i < (end - start))
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static void			*ft_fresh(char **mat, size_t i)
{
	while (mat[++i])
		free(mat[i]);
	free(mat);
	return (NULL);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**mat;
	size_t		i;
	size_t		start;
	size_t		end;
	char		*tmp;

	if (!(s))
		return (NULL);
	end = ft_count_word(s, c);
	if (!(mat = (char**)malloc(sizeof(char*) * (end + 1))))
		return (NULL);
	mat[end] = 0;
	end = 0;
	i = -1;
	while (++i < ft_count_word(s, c))
	{
		start = ft_start(s, end, c);
		end = ft_end(s, start, c);
		tmp = ft_out(s, start, end);
		if (!tmp)
			return (ft_fresh(mat, i));
		mat[i] = tmp;
	}
	return (mat);
}
