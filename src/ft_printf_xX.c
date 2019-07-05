/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:11:58 by  blomo            #+#    #+#             */
/*   Updated: 2019/07/05 18:32:25 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char		*ft_printf_x(t_param *ft, va_list ap, union u_format f)
{

	char *ptr;
	char *ptr1;
	if (ft->plus)
		ft->plus = 0;
	if (ft->space)
		ft->space = 0;
	if (ft->z || ft->l || ft->ll || ft->j)
	{
		f.ull = va_arg(ap, unsigned long long);
		ptr = ft_ulldtoa_base(f.ull, 16);
	}
	else if (ft->hh)
	{
		f.uc = va_arg(ap, unsigned int);
		ptr = ft_uhhdtoa_base(f.uc, 16);
	}
	else if (ft->h)
	{
		f.ushi = va_arg(ap,unsigned int);
		ptr = ft_uhhdtoa_base(f.uc, 16);
	}
	else
	{
		f.ud = va_arg(ap,unsigned int);
		ptr = ft_uldtoa_base(f.ud, 16);
	}
	if(ft->reshetka && *ptr != '0')
	{
		ptr1 = ft_printf_reshetka(ft,ptr);
	}
	else
		ptr1 = ft_printf_d_default(ft,ptr);
	return (ptr1);
}
char		*ft_printf_bigx(t_param *ft, va_list ap, union u_format f)
{

	char *ptr;
	char *ptr1;
	int i;
	i = 0;
	if(ft->plus)
		ft->plus = 0;
	if(ft->space)
		ft->space = 0;
	if (ft->z || ft->l || ft->ll || ft->j)
	{
		f.ull = va_arg(ap, unsigned long long);
		ptr = ft_ulldtoa_base(f.ull, 16);
	}
	else if (ft->hh)
	{
		f.uc = va_arg(ap, unsigned int);
		ptr = ft_uhhdtoa_base(f.uc, 16);
	}
	else if (ft->h)
	{
		f.ushi = va_arg(ap,unsigned int);
		ptr = ft_uhhdtoa_base(f.uc, 16);
	}
	else
	{
		f.ud = va_arg(ap,unsigned int);
		ptr = ft_uldtoa_base(f.ud, 16);
	}
	if(ft->reshetka && *ptr != '0')
	{
		ptr1 = ft_printf_reshetka(ft,ptr);
	}
	else
		ptr1 = ft_printf_d_default(ft,ptr);
	i = 0;
	while(ptr1[i])
	{
		if(ptr1[i] == 'a')
			ptr1[i] = 'A';
		if(ptr1[i] == 'b')
			ptr1[i] = 'B';
		if(ptr1[i] == 'c')
			ptr1[i] = 'C';
		if(ptr1[i] == 'd')
			ptr1[i] = 'D';
		if(ptr1[i] == 'e')
			ptr1[i] = 'E';
		if(ptr1[i] == 'f')
			ptr1[i] = 'F';
		if(ptr1[i] == 'x')
			ptr1[i] = 'X';
		i++;
	}
	return (ptr1);
}
