/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_C.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:10:13 by  blomo            #+#    #+#             */
/*   Updated: 2019/07/05 16:50:51 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_c(t_param *ft, va_list ap)
{
	char	*ptr;
	int		c;
	int		x;
	int		i;

	x = 0;
	i = 1;
	c = (char)va_arg(ap, int);
	ft->width > i ? i = ft->width : 1;
	if (c == 0)
		ft->cflag = 1;
	if (!(ptr = (char*)malloc(sizeof(char) * (i))))
		return (NULL);
	ptr[i] = '\0';
	if (ft->minus)
	{
		ptr[x] = c;
		x++;
		if (ft->width)
		{
			while (ft->width > 1)
			{
				ptr[x] = ' ';
				x++;
				ft->width--;
			}
			return (ptr);
		}
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
		ptr[x] = c;
	}
	if (!ft->minus && !ft->width)
		ptr[x] = c;
	return (ptr);
}
