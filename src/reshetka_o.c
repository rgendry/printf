/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reshetka_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  blomo < blomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:15:07 by  blomo            #+#    #+#             */
/*   Updated: 2019/07/02 21:15:16 by  blomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static void ft_minus(char *ptr,t_param *ft, char *str)
{
	int i;
	i = 0;
	int p;
	p = ft_strlen(str);
	if(ft->minus)
	{
    ptr[i++] = '0';
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
	}
}

char	*ft_printf_reshetkao(t_param *ft, char *str)
{
	char *ptr;
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
  //  p = p + 2;
  // if(ft->width)
  //   ft->width = ft->width -2;
	if(ft->minus)
	{
		ft_minus(ptr,ft,str);
		free(str);
    // i = strlen(ptr);
    // printf("%d\n",i);
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
			while(i > ft->precision + 2)
			{
				ptr[x] = ' ';
				x++;
				i--;
			}
      ptr[x++] = '0';
			while(ft->precision > p)
			{
				ptr[x] = '0';
				x++;
				ft->precision--;
			}

			//пробелы потом точность
		}
		else if (ft->precision > ft->width && ft->precision > p)
		{
      ptr[x++] = '0';

      p++;
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
			if(ft->zero)
			{
        ptr[x++] = '0';

        p++;
				while(ft->width > p)
				{
					ptr[x] = '0';
					x++;
					ft->width--;
				}

			}
      else
      {
			while(ft->width > p + 1)
			{
				ptr[x] = ' ';
				x++;
				ft->width--;
			}
      ptr[x++] = '0';

			//пробелы
      }
		}
	}
		if((!ft->precision && !ft->width ) || ft->width < p)
		{
      ptr[x++] = '0';
		}
		i = 0;
		while(str[i])
		{
			ptr[x] = str[i];
			i++;
			x++;
		}
		free(str);
		return(ptr);
}
