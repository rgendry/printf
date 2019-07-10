/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:14:38 by  blomo            #+#    #+#             */
/*   Updated: 2019/07/10 13:20:49 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_o(t_param *ft, va_list ap, union u_format f)
{
	char *ptr;
	char *ptr1;

	ft->plus ? ft->plus = 0 : ft->plus;
	ft->space ? ft->space = 0 : ft->space;
	if (ft->z || ft->l || ft->ll || ft->j)
		ptr = ft_ulldtoa_base(va_arg(ap, unsigned long long), 8);
	else if (ft->hh)
		ptr = ft_uhhdtoa_base(va_arg(ap, unsigned int), 8);
	else if (ft->h)
		ptr = ft_uhhdtoa_baseo(va_arg(ap, unsigned int), 8);
	else
	{
		f.ud = va_arg(ap, unsigned int);
		ptr = ft_uldtoa_base(f.ud, 8);
	}
	if (ft->reshetka)
		ptr1 = ft_printf_reshetkao(ft, ptr);
	else
		ptr1 = ft_printf_d_default(ft, ptr);
	return (ptr1);
}
