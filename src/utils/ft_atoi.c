/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 03:52:16 by blomo             #+#    #+#             */
/*   Updated: 2019/07/02 22:23:28 by  blomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_space(const char *str)
{
	int i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
	{
		i++;
		if (str[i] == '-')
			i--;
	}
	return (i);
}

int			ft_atoi(const char *str)
{
	size_t	i;
	long	res;
	long	temp;
	int		neg;

	res = 0;
	neg = 1;
	temp = 0;
	i = 0;
	i = ft_space(str);
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if (res / 10 != temp && neg == 1)
			return (-1);
		if (res / 10 != temp && neg == -1)
			return (0);
		temp = res;
	}
	return (res * neg);
}
