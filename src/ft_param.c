/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 18:37:07 by  blomo            #+#    #+#             */
/*   Updated: 2019/07/09 21:43:35 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_mix1(t_param *ft, char **format, va_list ap, union u_format f)
{
	if (*(*format) == 'c')
		return (ft_printf_c(ft, ap));
	if (*(*format) == 'f')
		return (ft_printf_f(ft, ap));
	if (*(*format) == '%')
		return (ft_printfper(ft));
	if (*(*format) == 'p')
		return (ft_printf_p(ft, ap));
	if (*(*format) == 'd' || *(*format) == 'i')
		return (ft_printf_d(ft, ap, f));
	if (*(*format) == 'u')
		return (ft_printf_u(ft, ap, f));
	if (*(*format) == 's')
		return (ft_printf_s(ft, ap));
	if (*(*format) == 'x')
		return (ft_printf_x(ft, ap, f));
	if (*(*format) == 'X')
		return (ft_printf_bigx(ft, ap, f));
	if (*(*format) == 'o')
		return (ft_printf_o(ft, ap, f));
	if (*(*format) == 'O')
		return (ft_printf_o(ft, ap, f));
	return (0);
}

char	*ft_param(t_param *p, char **format, va_list ap)
{
	char			*ptr;
	union u_format	f;

	ptr = NULL;
	f.d = 0;
	ft_parammode(p, format, ap);
	if (*(*format) == 'c' || *(*format) == 'C' || *(*format) == 'i' ||
		*(*format) == 'd' || *(*format) == 'D' || *(*format) == 's' ||
		*(*format) == 'u' || *(*format) == 'x' || *(*format) == 'X' ||
		*(*format) == 'o' || *(*format) == 'O' || *(*format) == 'f' ||
		*(*format) == '%' || *(*format) == 'p')
		return (ft_mix1(p, format, ap, f));
	return (ft_mix1(p, format, ap, f));
}
