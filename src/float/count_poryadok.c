/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_poryadok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:56:00 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/11 14:16:33 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_poryadok(long double nbr)
{
	union Byte			x;
	int					pow;
	flag				ptr;

	x.i = nbr;
	ptr.count = 15;
	pow = 0;
	ptr.two = 1;
	ptr.one = 1;
	while (ptr.count--)
	{
		if (x.bitfield.poryadok & ptr.one)
			pow = pow + ptr.two;
		ptr.two *= 2;
		ptr.one <<= 1;
	}
	pow = pow - 16383;
	return (pow);
}
