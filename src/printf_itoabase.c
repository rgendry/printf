/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_itoabase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  blomo < blomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:14:48 by  blomo            #+#    #+#             */
/*   Updated: 2019/07/09 15:53:30 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char		*ft_ulldtoa_base(unsigned long long value, int base)
{
	static char			*hex = "0123456789abcdef";
	char				*result;
	unsigned long long	n;
	int					len;

	n = value;

	len = ft_ulld_len_base(n, base);
	result = (char*)malloc(len + 1);
	result[len--] = '\0';
	if (value == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (n)
	{
		result[len--] = hex[n % base];
		n /= base;
	}
	return (result);
}

char		*ft_uldtoa_base(unsigned long value, int base)
{
	static char			*hex = "0123456789abcdef";
	char				*result;
	unsigned long long	n;
	int					len;

	n = value;

	len = ft_uld_len_base(n, base);
	result = (char*)malloc(len + 1);
	result[len--] = '\0';
	if (value == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (n)
	{
		result[len--] = hex[n % base];
		n /= base;
	}
	return (result);
}

char		*ft_lldtoa_base(long long value, int base)
{
	static char			*hex = "0123456789abcdef";
	char				*result;
	long long			n;
	int					len;

	n = value;

	if (value < 0)
		n *= -1;
	len = ft_nlen_base(n, base);
	if (value < 0 && base == 10)
		len++;
	result = (char*)malloc(len + 1);
	result[len--] = '\0';
	if (value == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (n)
	{
		result[len--] = hex[n % base];
		n /= base;
	}
	if (value < 0 && base == 10)
		result[0] = '-';
	return (result);
}

char		*ft_uhhdtoa_base(unsigned char value, int base)
{
	static char			*hex = "0123456789abcdef";
	char				*result;
	long long			n;
	int					len;

	n = value;

	len = ft_nlen_base(n, base);
	result = (char*)malloc(len + 1);
	result[len--] = '\0';
	if (value == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (n)
	{
		result[len--] = hex[n % base];
		n /= base;
	}
	return (result);
}
char		*ft_uhhdtoa_baseo(unsigned short int value, int base)
{
	static char			*hex = "0123456789abcdef";
	char				*result;
	long long			n;
	int					len;

	n = value;

	len = ft_nlen_base(n, base);
	result = (char*)malloc(len + 1);
	result[len--] = '\0';
	if (value == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (n)
	{
		result[len--] = hex[n % base];
		n /= base;
	}
	return (result);
}

char		*ft_ulldtoa_base_alt(unsigned long long value, int base)
{
	static char			*hex = "0123456789ABCDEF";
	char				*result;
	unsigned long long	n;
	int					len;

	n = value;

	len = ft_ulld_len_base(n, base);
	result = (char*)malloc(len + 1);
	result[len--] = '\0';
	if (value == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (n)
	{
		result[len--] = hex[n % base];
		n /= base;
	}
	return (result);
}
