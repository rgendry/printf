/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 18:37:07 by  blomo            #+#    #+#             */
/*   Updated: 2019/07/05 18:33:24 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char	*ft_param(t_param *p, char **format, va_list ap)
{
	char			*ptr;
	union u_format	f;

	f.d = 0;
	ft_parammode(p, format);
	if (*(*format) == 'c' || *(*format) == 'C' || *(*format) == 'i' ||
		*(*format) == 'd' || *(*format) == 'D' || *(*format) == 's' ||
		*(*format) == 'u' || *(*format) == 'x' || *(*format) == 'X' ||
		*(*format) == 'o' || *(*format) == 'O' || *(*format) == 'f' ||
		*(*format) == '%')
		return (ft_printf_mix1(p, format, ap, f));
// U , S, p, C
	// if (*(*format) == '%')
	// {
	// 	ptr = (char *)malloc(sizeof(char) * 1);
	// 	ptr[1] = '\0';
	// 	ptr[0] = '%';
	// 	return (ptr);
	// }
	// while (*(*format) != '%')
	// 	(*format)--;
	// ptr = (char *)malloc(sizeof(char) * 1);
	// ptr[1] = '\0';
	// ptr[0] = '%';
	// return (ptr);
}

char	*ft_printf_mix1(t_param *ft, char **format, va_list ap, union u_format f)
{
	if (*(*format) == 'c')
		return (ft_printf_c(ft, ap));
	if (*(*format) == 'f')
		return (ft_printf_f(ft, ap));
	if (*(*format) == '%')
		return (ft_printfper(ft, ap));
	// else if (*(*format) == 'C')
	// {
	// 	(*format)++;
	// 	return (ft_putwchar(va_arg(ap, wchar_t)));
	// }
	 //else
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
	if (*(*format) == 'o' || *(*format) == 'O')
		return (ft_printf_o(ft, ap, f));
	// else if (*(*format) == 'D')
	// {
	// 	(*format)++;
	// 	f.ld = va_arg(ap, long);
	// 	ft_putlong(f.ld);
	// 	return (ft_lldlen_base(f.ld, 10));
	// }
	return (0);
}

//int		ft_printf_mix2(t_param *ft, char **format, va_list ap, union u_format f)
//{
	// if (*(*format) == 'o')
	// 	return (ft_printf_o(ft, format, ap, f));
	// if (*(*format) == 'O')
	// 	return (ft_printf_lo(ft, format, ap, f));
	// if (*(*format) == 'p')
	// 	return (ft_printf_p(ft, format, ap, f));
	// if (*(*format) == 's')
	// 	return (ft_printf_s(ft, format, ap, f));
	// if (*(*format) == 'S')
	// 	return (ft_printf_ls(ft, format, ap, f));
	// if (*(*format) == 'u')
	// 	return (ft_printf_u(ft, format, ap, f));
	// if (*(*format) == 'U')
	// 	return (ft_printf_lu(ft, format, ap, f));
	// if (*(*format) == 'x')
	// 	return (ft_printf_x(ft, format, ap, f));
	// if (*(*format) == 'X')
	// 	return (ft_printf_lx(ft, format, ap, f));
//	return (0);
//}
