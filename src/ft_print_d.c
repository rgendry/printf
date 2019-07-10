/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:57:08 by  blomo            #+#    #+#             */
/*   Updated: 2019/07/10 13:44:13 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void ft_minus(char *ptr,t_param *ft, char *str)
{
	int i;
	i = 0;
	int p;
	p = ft_strlen(str);
	if(ft->minus)
	{
		if (ft->space)
			ptr[i++] = ' ';
		if(ft->cur_len == -1)
			ptr[i++] = '-';
		else if(ft->plus && ft->cur_len != -1)
			ptr[i++] = '+';
		if(ft->precision > p)
		{
			while((ft->precision - p) != 0)
			{
				ptr[i] = '0';
				i++;
				ft->precision--;
			}
		}
		while(*str)
			{
				ptr[i] = *str;
				str++;
				i++;
			}
		while(ft->width > i)
		{
			ptr[i] = ' ';
			i++;
		}
		ptr[i] = '\0';
	}
}

static int ft_znak(char *ptr,t_param *ft,int x)
{
	if(ft->plus && ft->cur_len != -1)
	{
		if(x != 0)
			x--;
		ptr[x] = '+';
		x++;
		ft->plus = 0;
		ft->cur_len = 0;
		ft->width--;
	}
	else if (ft->cur_len == -1)
	{
		if(x != 0)
			x--;
		ptr[x] = '-';
		x++;
		ft->plus = 0;
		ft->cur_len = 0;
		ft->width--;
	}
	return(x);
}

char	*ft_printf_d_default(t_param *ft, char *str)
{
	char *ptr;
	ptr = NULL;
	int i;
	int c;
	int p;
	int x;
//	int ypc;
	//ypc = 0;
	x = 0;
	char temp[100];
	ft_bzero(temp,100);
	i = 0;
	p = ft_strlen(str);
	if(p > ft->precision && p > ft->width)
		c = p;
	else if ( ft->precision > ft->width)
		c = ft->precision;
	else
		c = ft->width;
	if(!(ptr = (char*)malloc(sizeof(char) * (c + 1))))
		return(NULL);
	if(ft->precision2 || ft->precision)
		ft->zero = 0;
	if(ft->plus || ft->cur_len == -1)
		ft->space = 0;

	if(ft->minus)
	{
		ft_minus(ptr,ft,str);
		free(str);
		return(ptr);
	}
	else
	{
		if(ft->precision2 && ft->precision == 0 && *str == '0')
		{
			p = 0;
			*str = 0;
		}
		if(ft->precision < ft->width && ft->precision > p && ft->precision)
		{

			i = ft->width;
			// if(ft->cur_len == -1)
			// 	i--;
			while(i > ft->precision)
			{
				ptr[x] = ' ';
				x++;
				i--;
			}
			x = ft_znak(ptr,ft,x);
			while(ft->precision > p)
			{
				ptr[x] = '0';
				x++;
				ft->precision--;
			}

			//пробелы потом точность
		}
		else if (ft->precision > ft->width && ft->precision -1 > p)
		{
			x = ft_znak(ptr,ft,x);
			while(ft->precision > p)
			{
				ptr[x] = '0';
				x++;
				ft->precision--;
			}
			//сразу точность
		}
		else if(ft->precision < ft->width && ft->width > p)
		{
			if(ft->space)
			{
				ptr[x++] = ' ';
				if(ft->width)
					ft->width--;
			}
			if(ft->zero)
			{
				x = ft_znak(ptr,ft,x);
				while(ft->width > p)
				{
					ptr[x] = '0';
					x++;
					ft->width--;
				}
			}
			while(ft->width > p)
			{
				ptr[x] = ' ';
				x++;
				ft->width--;
			}
			x = ft_znak(ptr,ft,x);
			//пробелы
		}
		else if(ft->precision < p)
			x = ft_znak(ptr,ft,x);
	}
		if(!ft->precision && !ft->width)
		{
			x = ft_znak(ptr,ft,x);
			if(ft->space)
				ptr[x++] = ' ';
		}
		i = 0;
		while(str[i])
		{
			ptr[x] = str[i];
			i++;
			x++;
		}
		ptr[x] = '\0';
		free(str);
		return(ptr);
}

char		*ft_printf_d(t_param *ft, va_list ap, union u_format f)
{

	char *ptr;
	char *ptr1;
	ptr = NULL;
	ptr1 = NULL;
	if(ft->cur_len == 2)
	{
		f.ud = va_arg(ap, unsigned int);
		ptr = ft_itoauun(f.ud);
		//printf("ptr = %s\n",ptr);
		ptr1 = ft_printf_d_default(ft,ptr);
		return (ptr1);
	}
	if (ft->z || ft->l || ft->ll || ft->j)
	{
		f.ld = va_arg(ap, long);
		if(f.ld < 0)
		{
			ft->cur_len = -1;
			f.ld = f.ld * -1;
		}
		ptr = ft_itoaunll(f.ld);
	}
	else if (ft->hh)
	{
		f.sc = va_arg(ap, int);
		// if(f.sc < 0)
		// {
		// 	ft->cur_len = -1;
		// 	f.sc = f.sc * -1;
		// }
		ptr = ft_itoaunsc(f.sc,ft);
	}
	else if (ft->h)
	{
		f.shi = va_arg(ap,int);
		// if(f.shi < 0)
		// {
		// 	ft->cur_len = -1;
		// 	f.shi = f.shi * -1;
		// }
		ptr = ft_itoaunsi(f.shi, ft);
	}
	else
	{
		f.d = va_arg(ap, int);
		// if(f.d < 0)
		// {
		// 	ft->cur_len = -1;
		// 	f.d = f.d * -1;
		// }
		ptr = ft_itoaun(f.d,ft);
	}
	ptr1 = ft_printf_d_default(ft,ptr);
	return (ptr1);
}
char		*ft_printf_u(t_param *ft,  va_list ap, union u_format f)
{

	char *ptr;
	char *ptr1;
	if(ft->plus)
		ft->plus = 0;
	if(ft->space)
		ft->space = 0;
	if (ft->z || ft->l || ft->ll || ft->j)
	{
		f.ul = va_arg(ap, unsigned long);
		ptr = ft_itoaunll(f.ld);
	}
	else if (ft->hh)
	{
		f.uc = va_arg(ap,unsigned int);
		// if(f.sc < 0)
		// {
		// 	ft->cur_len = -1;
		// 	f.sc = f.sc * -1;
		// }
		ptr = ft_itoaun(f.uc,ft);
	}
	else if (ft->h)
	{
		f.ushi = va_arg(ap,unsigned int);
		// if(f.shi < 0)
		// {
		// 	ft->cur_len = -1;
		// 	f.shi = f.shi * -1;
		// }
		ptr = ft_itoaunsiUU(f.ushi);
	}
	else
	{
		f.ud = va_arg(ap, unsigned int);
		// if(f.d < 0)
		// {
		// 	ft->cur_len = -1;
		// 	f.d = f.d * -1;
		// }
		ptr = ft_itoauun(f.ud);
	}
	ptr1 = ft_printf_d_default(ft,ptr);
	return (ptr1);
}
