/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:56:53 by  blomo            #+#    #+#             */
/*   Updated: 2019/07/06 13:17:53 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	int i;
	char *ptr;
	va_list ap;
	t_param p;
	int x;
	x = 0;
	char printstr[100];
	ft_bzero(printstr, 100);
	i = 0;
	ft_bzero(&p, sizeof(p));
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ptr = ft_param(&p, &format, ap);
			while (ptr[x])
				printstr[i++] = ptr[x++];
			if (*format == 'c' && (p.cflag == 1))
				printstr[i++] = '\0';
			if (ptr != 0)
				free(ptr);
			ft_bzero(&p, sizeof(p));
			x = 0;
		}
		else
			printstr[i++] = *format;
		format++;
	}
	write(1, printstr, i);
	va_end(ap);
	return (i);
}
