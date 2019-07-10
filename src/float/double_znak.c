/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_znak.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:58:11 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/10 18:04:59 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_znakk(long double nbr)
{
	union Byte	x;
	int			i;

	x.i = nbr;
	if (x.bitfield.znak & 1)
		i = -1;
	else
		i = 0;
	return (i);
}
