/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:02:58 by blomo             #+#    #+#             */
/*   Updated: 2019/04/14 02:24:28 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lenght(unsigned int n)
{
	int res;
	int count;

	res = n;
	count = 0;
	if (n == 0)
		count++;
	while (res != 0)
	{
		count++;
		res = res / 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	int				count;
	unsigned int	res;
	int				neg;
	char			*out;

	neg = 0;
	res = n;
	if (n < 0)
	{
		neg = 1;
		res = (unsigned)n * -1;
	}
	count = ft_lenght(res) + neg;
	out = (char*)malloc(sizeof(char) * (count + 1));
	if (!(out))
		return (NULL);
	out[count] = '\0';
	if (neg == 1)
		out[0] = '-';
	while (count-- > neg)
	{
		out[count] = (char)(res % 10 + '0');
		res /= 10;
	}
	return (out);
}
