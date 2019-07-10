/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 14:22:45 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/10 15:50:57 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_addjoin(char *s1, char *s2)
{
	int		i;
	char	*str;
	int j;
	j = 0;
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
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
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
	if(!(str = (char *)malloc(sizeof(char) * (ft->width - size - 1 ))))
		return(NULL);
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
	char 	*str1;
	char *str2;
	if (ft->precision)
	{
		if (ft->width < ft->precision)
			ft->width = ft->precision;
		str = ft_tmp_str(ft, (int)ft_strlen(ptr));
		ptr = ft_addjoin("0x", ft_addjoin(str, ptr));
		ft->precision1 = 1;
	}
	if (ft->width > (int)ft_strlen(ptr))
	{
		str = ft_tmp_str(ft, (int)ft_strlen(ptr));
		if (ft->minus)
		{
			str1 = ft_addjoin("0x", ptr);
			str2 = ft_addjoin(str1 , str);
			free(str);
			free(str1);
			return(str2);
		}
		if (ft->precision1)
			ptr = ft_addjoin(str, ptr);
		else
			ptr = ft_addjoin(ft_addjoin(str, "0x"), ptr);
		free(str);
	}
	else if (!ft->precision)
	{
		str1 = ft_addjoin("0x", ptr);
		// if(ptr != NULL)
		// 	free(ptr);
		return(str1);
	}
	return (ptr);
}

char	*ft_printf_p(t_param *ft, va_list ap)
{
	void			*a;
	char			*ptr;
	char 			*str1;
	unsigned long	add;

	a = va_arg(ap, void*);
	add = (unsigned long)a;
	ptr = ft_ulldtoa_base(add, 16);
	if (!a && ft->precision2 && ft->precision == 0)
	{
		free(ptr);
		// ptr = (char *)malloc(sizeof(char) * 1);
		// ptr[0] = '\0';
		ptr = "\0";
	}
	else if (!a && !ft->precision2)
	{
		free(ptr);
		// ptr = (char *)malloc(sizeof(char) * 2);
		// ptr[0] = '0';
		// ptr[1] = '\0';
		ptr = "0\0";
	}
	else if(!ft->precision && !ft->width && ptr!= NULL)
	{
		str1 = ft_addjoin("0x", ptr);
		free(ptr);
		return(str1);
	}
	return (ft_end_p(ft, ptr));
}
