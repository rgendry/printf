/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  blomo < blomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:13:03 by  blomo            #+#    #+#             */
/*   Updated: 2019/07/09 18:49:26 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char		*ft_printf_s(t_param *ft, va_list ap)
{
  char *ptr;
	ptr = NULL;
  char *str;
  char *str1;
  str1 = NULL;
  int x;
  x = 0;
  int i;
  int z;
  i = 0;
	if(ft->precision2 && ft->precision == 0)
	{
		return(ptr);
	}
  str = va_arg(ap,char *);
  if(str1 != str)
    i = ft_strlen(str);
  else
    i = 6;
  if(ft->width > i)
    z = ft->width;
  else if (ft->precision && ft->precision > i)
    z = ft->precision;
  else
    z = i;
  // if(i == 0 && ft->width)
  //   ft->width+=2;
  if(i == 0)
    ft->precision = 0;
  if(!(ptr = (char*)malloc(sizeof(char) * (z))))
    return(NULL);
  ptr[z] = '\0';
  if(str == str1)
  {
    str = "(null)";
  }
  if(ft->minus)
  {
    if(ft->precision)
      {
        while(ft->precision)
        {
          ptr[x] = *str;
          x++;
          str++;
          ft->precision--;
        }
      }
      else
      {
        while(*str)
        {
          ptr[x] = *str;
          x++;
          str++;
        }
      }

    while(ft->width > x)
    {
      ptr[x] = ' ';
      x++;
    }
    return(ptr);
  }
  else
  {
    if(ft->width && ft->precision && ft->width > ft->precision && ft->precision > i)
      z = ft->width - i;
		else if(ft->width && ft->precision && ft->width > ft->precision && ft->precision < i)
			z = ft->width - ft->precision;
    else if (ft->width && ft->width > i)
      z = ft->width - i;
    else
      z = 0;
    //printf("z= %d\n",z);
    while(z)
    {
      ptr[x] = ' ';
      x++;
      z--;
    }
    if(ft->precision)
      {
        while(ft->precision && *str)
        {
          ptr[x] = *str;
          x++;
          if(i != 0)
          str++;
          ft->precision--;
        }
      }

      else
      {
        while(*str)
        {
          ptr[x] = *str;
          x++;
          str++;
        }
      }
}
return(ptr);
}
