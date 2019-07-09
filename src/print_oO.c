/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oO.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  blomo < blomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:14:38 by  blomo            #+#    #+#             */
/*   Updated: 2019/07/09 15:54:46 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char		*ft_printf_o(t_param *ft, va_list ap, union u_format f)
{
	char *ptr;
	char *ptr1;
	if(ft->plus)
		ft->plus = 0;
	if(ft->space)
		ft->space = 0;
	if (ft->z || ft->l || ft->ll || ft->j)
	{
		f.ull = va_arg(ap, unsigned long long);
		ptr = ft_ulldtoa_base(f.ull, 8);
	}
	else if (ft->hh)
	{
		f.uc = va_arg(ap, unsigned int);
		ptr = ft_uhhdtoa_base(f.uc, 8);
	}
	else if (ft->h)
	{
		f.ushi = va_arg(ap,unsigned int);
		ptr = ft_uhhdtoa_baseo(f.ushi, 8);
	}
	else
	{
		f.ud = va_arg(ap,unsigned int);
		ptr = ft_uldtoa_base(f.ud, 8);
	}
	if(ft->reshetka )
	{
		ptr1 = ft_printf_reshetkao(ft,ptr);
	}
	else
		ptr1 = ft_printf_d_default(ft,ptr);
	return (ptr1);
}
