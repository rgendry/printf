/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_C.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  blomo < blomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:10:13 by  blomo            #+#    #+#             */
/*   Updated: 2019/07/09 18:42:18 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char	*ft_printf_c(t_param *ft, va_list ap)
{
	char	*ptr;
	ptr = NULL;
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
		if(c != 0)
			ptr[x++] = c;
			if (c == 0)
				ft->cflag = 2;
		if (ft->width)
		{
			while (ft->width > 1)
			{
				ptr[x] = ' ';
				x++;
				ft->width--;
			}
			ptr[x] = '\0';
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
