/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:13:03 by  blomo            #+#    #+#             */
/*   Updated: 2019/07/11 20:14:13 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_s(t_param *ft, va_list ap)
{
	char	*ptr;
	char	*str;
	char	*str1;
	int		x;
	int		i;
	int		z;

	str1 = NULL;
	ptr = NULL;
	x = 0;
	i = 0;
	str = va_arg(ap, char *);
	if (ft->precision2 && ft->precision == 0 && !ft->width)
		return (ptr);
	if (ft->precision2 && ft->precision == 0 && ft->width)
	{
		if (!(ptr = (char*)malloc(sizeof(char) * (ft->width + 1))))
			return (NULL);
		while (ft->width--)
			ptr[x++] = ' ';
		ptr[x] = '\0';
		return (ptr);
	}
	if (str1 != str)
		i = ft_strlen(str);
	else
		i = 6;
	if (ft->width > i)
		z = ft->width;
	else if (ft->precision && ft->precision > i)
		z = ft->precision;
	else
		z = i;
	if (i == 0)
		ft->precision = 0;
	if (!(ptr = (char*)malloc(sizeof(char) * (z))))
		return (NULL);
	if (str == str1)
		str = "(null)";
	if (ft->minus)
	{
		if (ft->precision)
		{
			while (ft->precision)
			{
				ptr[x] = *str;
				x++;
				str++;
				ft->precision--;
			}
		}
		else
		{
			while (*str)
			{
				ptr[x] = *str;
				x++;
				str++;
			}
		}
		while (ft->width > x)
		{
			ptr[x] = ' ';
			x++;
		}
		return (ptr);
	}
	else
	{
		if (ft->width && ft->precision && ft->width > ft->precision && ft->precision > i)
			z = ft->width - i;
		else if (ft->width && ft->precision && ft->width > ft->precision && ft->precision < i)
			z = ft->width - ft->precision;
		else if (ft->width && ft->width > i)
			z = ft->width - i;
		else
			z = 0;
		while (z)
		{
			ptr[x] = ' ';
			x++;
			z--;
		}
		if (ft->precision)
		{
			while (ft->precision && *str)
			{
				ptr[x] = *str;
				x++;
				if (i != 0)
					str++;
				ft->precision--;
			}
		}
		else
		{
			while (*str)
			{
				ptr[x] = *str;
				x++;
				str++;
			}
		}
	}
	ptr[x] = '\0';
	return (ptr);
}
