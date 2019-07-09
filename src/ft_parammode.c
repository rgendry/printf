/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parammode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  blomo < blomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 18:37:30 by  blomo            #+#    #+#             */
/*   Updated: 2019/07/09 19:05:11 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parammode(t_param *param, char **format,va_list ap)
{
	if(*(*format))
		(*format)++;
	else
		return ;
	ft_printf_flags(param, format);
	if (*(*format) == '*')
	{
		param->width = va_arg(ap,int);
		if(param->width < 0)
		{
			param->width = param->width * -1;
			param->minus = 1;
		}
		(*format)++;
	}
	if (*(*format) >= '1' && *(*format) <= '9')
	{
		param->width = ft_atoi(*format);
		*format += ft_nlen_base(param->width, 10);
	}
	if (*(*format) == '.')
	{

		(*format)++;
		if (*(*format) == '*')
		{
			param->precision = va_arg(ap,int);
			// if(param->precision < 0)
			// {
			// 	param->precision = param->precision * -1;
			// }
			(*format)++;
		}
		while(*(*format) == '0')
			(*format)++;
		if (*(*format) >= '1' && *(*format) <= '9')
		{
			param->precision = ft_atoi(*format);
			*format += ft_nlen_base(param->precision, 10);
		}
		if (param->precision >= 0)
			param->precision2 = 1;
		else
		{
			param->precision2 = 0;
			param->precision = 0;
		}
		// else if (*(*format) == '0')
		// 	(*format)++;
	}
	ft_printf_lenmod(param, format);
}

void	ft_printf_flags(t_param *param, char **format)
{
	while (*(*format) == '#' || *(*format) == '-' || *(*format) == '+'
			|| *(*format) == '0' || *(*format) == ' ')
	{
		if (*(*format) == '#')
			param->reshetka = 1;
		else if (*(*format) == '-')
			param->minus = 1;
		else if (*(*format) == '+')
			param->plus = 1;
		else if (*(*format) == ' ')
			param->space = 1;
		else if (*(*format) == '0')
			param->zero = 1;
		(*format)++;
	}
}

void	ft_printf_lenmod(t_param *param, char **format)
{
	while (*(*format) == 'l' || *(*format) == 'h' || *(*format) == 'j' || *(*format) == 'z' || *(*format) == 'L')
	{
		if (*(*format) == 'l' && *((*format) + 1) == 'l')
		{
			param->ll = 1;
			(*format)++;
		}
		else if (*(*format) == 'L')
			param->L = 1;
		else if (*(*format) == 'l')
			param->l = 1;

		if (*(*format) == 'h' && *((*format) + 1) == 'h')
		{
			(*format)++;
			param->hh = 1;
		}
		else if (*(*format) == 'h')
			param->h = 1;
		if (*(*format) == 'j')
			param->j = 1;
		if (*(*format) == 'z')
			param->z = 1;
		(*format)++;
	}
}
