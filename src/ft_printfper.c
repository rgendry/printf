/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:23:00 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/09 15:09:53 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printfper(t_param *ft)
{
	int		x;
	char	*ptr;
	ptr = NULL;
	x = 0;
	if (!ft->width)
	{
		ptr = (char *)malloc(sizeof(char) * 1);
		ptr[1] = '\0';
		ptr[0] = '%';
		return (ptr);
	}
	ptr = (char *)malloc(sizeof(char) * ft->width);
	if (ft->minus)
	{
		ptr[x] = '%';
		x++;
		while (ft->width > 1)
		{
			ptr[x] = ' ';
			x++;
			ft->width--;
		}
		return (ptr);
	}
	if (ft->width)
	{
		while (ft->width > 0)
		{
			ptr[x] = ' ';
			x++;
			ft->width--;
		}
		x--;
		ptr[x] = '%';
	}
	return (ptr);
}
