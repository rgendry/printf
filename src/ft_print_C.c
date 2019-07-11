/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:10:13 by blomo             #+#    #+#             */
/*   Updated: 2019/07/11 20:03:14 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_miwidth(t_param *ft, char *ptr, int x)
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

char	*ft_end_c(t_param *ft, char *ptr, int x, int c)
{
	if (ft->width)
	{
		while (ft->width > 0)
		{
			ptr[x++] = ' ';
			ft->width--;
		}
		x--;
		ptr[x] = c;
	}
	if (!ft->minus && !ft->width)
		ptr[x] = c;
	return (ptr);
}

char	*ft_printf_c(t_param *ft, va_list ap)
{
	char	*ptr;
	int		c;
	int		x;
	int		i;

	x = 0;
	i = 1;
	ptr = NULL;
	c = (char)va_arg(ap, int);
	ft->width > i ? i = ft->width : 1;
	c == 0 ? ft->cflag = 1 : 0;
	if (!(ptr = (char*)malloc(sizeof(char) * (i))))
		return (NULL);
	ptr[i] = '\0';
	if (ft->minus)
	{
		if (c != 0)
			ptr[x++] = c;
		c == 0 ? ft->cflag = 2 : 0;
		if (ft->width)
			return (ft_miwidth(ft, ptr, x));
	}
	return (ft_end_c(ft, ptr, x, c));
}
