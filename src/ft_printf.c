/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:56:53 by blomo             #+#    #+#             */
/*   Updated: 2019/07/11 20:04:16 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	char	printstr[20000];
	int		i;
	char	*ptr;
	va_list	ap;
	t_param	p;

	ptr = NULL;
	int x;
	x = 0;
	ft_bzero(printstr, sizeof(printstr));
	i = 0;
	ft_bzero(&p, sizeof(p));
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ptr = ft_param(&p, &format, ap);
			if (p.cflag == 2)
				printstr[i++] = '\0';
			if (ptr)
			{
				while (ptr[x] && ptr)
					printstr[i++] = ptr[x++];
			}
			if (p.cflag == 1)
				printstr[i++] = '\0';
			ft_bzero(&p, sizeof(p));
			if (ptr != 0)
			{
				free(ptr);
				ptr = NULL;
			}
			x = 0;
		}
		else
		{
			if (*format != '\0')
				printstr[i++] = *format;
		}
		if (*format != '\0')
			format++;
	}
	write(1, &printstr, i);
	va_end(ap);
	return (i);
}
