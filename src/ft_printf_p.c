/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 14:22:45 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/09 21:00:27 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_addjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * ((ft_strlen(s1)
		+ ft_strlen(s2) + 1)))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_tmp_str(t_param *ft, int size)
{
	char	*str;
	int		i;
	int		width;

	i = 0;
	if (!ft->precision1 && ft->precision)
		width = ft->precision - size;
	else if (ft->precision1)
		width = ft->width - size;
	else
		width = ft->width - size - 2;
	str = (char *)malloc(sizeof(char) * (ft->width - size - 1));
	while (i < width)
	{
		if (ft->precision1)
			str[i] = ' ';
		else if (ft->precision || ft->zero)
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_end_p(t_param *ft, char *ptr)
{
	char	*str;

	if (ft->precision)
	{
		if (ft->width < ft->precision)
			ft->width = ft->precision;
		str = ft_tmp_str(ft, (int)ft_strlen(ptr));
		ptr = ft_addjoin("0x", ft_addjoin(str, ptr));
		free(str);
		ft->precision1 = 1;
	}
	if (ft->width > (int)ft_strlen(ptr))
	{
		str = ft_tmp_str(ft, (int)ft_strlen(ptr));
		if (ft->minus)
			return (ft_addjoin(ft_addjoin("0x", ptr), str));
		if (ft->precision1)
			ptr = ft_addjoin(str, ptr);
		else
			ptr = ft_addjoin(ft_addjoin(str, "0x"), ptr);
		free(str);
	}
	else if (!ft->precision)
		ptr = ft_addjoin("0x", ptr);
	return (ptr);
}

char	*ft_printf_p(t_param *ft, va_list ap)
{
	void			*a;
	char			*ptr;
	unsigned long	add;

	a = va_arg(ap, void*);
	add = (unsigned long)a;
	ptr = ft_ulldtoa_base(add, 16);
	if (!a && ft->precision2 && ft->precision == 0)
	{
		free(ptr);
		ptr = (char *)malloc(sizeof(char));
		ptr[0] = '\0';
	}
	else if (!a && !ft->precision2)
	{
		free(ptr);
		ptr = (char *)malloc(sizeof(char) * 2);
		ptr[0] = '0';
		ptr[1] = '\0';
	}
	return (ft_end_p(ft, ptr));
}
