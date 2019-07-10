/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow_nb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:27:15 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/10 19:27:18 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long int ft_power(int pow)
{
	unsigned long int p;
	p = 1;
	if(pow == 0)
		return(1);
	while(pow)
	{
		p = p * 2;
		pow--;
	}
	return(p);
}
