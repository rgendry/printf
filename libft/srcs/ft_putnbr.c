/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:04:05 by blomo             #+#    #+#             */
/*   Updated: 2019/04/10 04:47:28 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int i;

	if (n < 0)
	{
		ft_putchar('-');
		i = (unsigned int)n * -1;
		n = n * -1;
	}
	i = (unsigned int)n;
	if (i <= 9)
		ft_putchar(i + 48);
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}
