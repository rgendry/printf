/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delenie.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:57:43 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/10 19:08:05 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	delenie(char *str, unsigned long long int rem, unsigned long long int sub, int i)
{
	unsigned long long int	temp;
	int						quot;
	int						add;
	int						shifts;

	temp = sub;
	quot = 0;
	add = 1;
	shifts = 1;
	if (rem == 0 || i == 1000)
	{
		str[i] = '\0';
		return ;
	}
	while (rem > sub)
	{
		sub <<= 1;
		add <<= 1;
		shifts++;
	}
	while (shifts)
	{
		while (rem >= sub)
		{
			rem -= sub;
			quot += add;
		}
		sub >>= 1;
		add >>= 1;
		shifts--;
	}
	str[i] = quot + 48;
	i++;
	delenie (str,rem * 10, temp, i);
}
