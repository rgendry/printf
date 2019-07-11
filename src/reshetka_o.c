/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reshetka_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:15:07 by  blomo            #+#    #+#             */
/*   Updated: 2019/07/11 20:22:05 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_minus(char *ptr,t_param *ft, char *str)
{
	int i;
	int p;

	i = 0;
	p = ft_strlen(str);
	if (ft->minus)
	{
		ptr[i++] = '0';
		if (ft->precision > p)
		{
			while ((ft->precision - p) != 0)
			{
				ptr[i] = '0';
				i++;
				ft->precision--;
			}
		}
		while (*str)
		{
			ptr[i] = *str;
			str++;
			i++;
		}
		while (ft->width > i)
		{
			ptr[i] = ' ';
			i++;
		}
	}
}

char	*ft_printf_reshetkao(t_param *ft, char *str)
{
	char	temp[100];
	char	*ptr;
	int		i;
	int		c;
	int		p;
	int		x;

	x = 0;
	ft_bzero(temp,100);
	i = 0;
	p = ft_strlen(str);
	if(p > ft->precision && p > ft->width)
		c = p;
	else if ( ft->precision > ft->width)
		c = ft->precision;
	else
		c = ft->width;
	if (!(ptr = (char*)malloc(sizeof(char) * (c + 1))))
		return (NULL);
	if (ft->precision2 || ft->precision)
		ft->zero = 0;
	if (ft->minus)
	{
		ft_minus(ptr,ft,str);
		free(str);
		return(ptr);
	}
	else
	{
		if (ft->precision2 && ft->precision == 0 && *str == '0')
		{
			p = 0;
			*str = 0;
		}
		if (ft->precision < ft->width && ft->precision > p && ft->precision)
		{
			i = ft->width;
			while (i > ft->precision + 2)
			{
				ptr[x] = ' ';
				x++;
				i--;
			}
			ptr[x++] = '0';
			while (ft->precision > p)
			{
				ptr[x] = '0';
				x++;
				ft->precision--;
			}
		}
		else if (ft->precision > ft->width && ft->precision > p)
		{
			ptr[x++] = '0';
			p++;
			while (ft->precision > p)
			{
				ptr[x] = '0';
				x++;
				ft->precision--;
			}
		}
		else if (ft->precision < ft->width && ft->width > p)
		{
			if (ft->zero)
			{
				ptr[x++] = '0';
				p++;
				while (ft->width > p)
				{
					ptr[x] = '0';
					x++;
					ft->width--;
				}
			}
			else
			{
				while (ft->width > p + 1)
				{
					ptr[x] = ' ';
					x++;
					ft->width--;
				}
				ptr[x++] = '0';
			}
		}
	}
	if ((!ft->precision && !ft->width ))
	{
		ptr[x++] = '0';
		ft->cur_len = -1;
	}
	i = 0;
	if (str[0] != '0')
	{
		while (str[i])
		{
			ptr[x] = str[i];
			i++;
			x++;
		}
	}
	free(str);
	ptr[x] = '\0';
	return (ptr);
}
