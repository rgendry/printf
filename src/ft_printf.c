/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  blomo < blomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:56:53 by  blomo            #+#    #+#             */
/*   Updated: 2019/07/09 18:41:54 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	int i;
	char *ptr;
	ptr = NULL;
	va_list ap;
	t_param p;
	int x;
	x = 0;
	char printstr[20000];
	ft_bzero(printstr, sizeof(printstr));
	i = 0;
	ft_bzero(&p, sizeof(p));
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ptr = ft_param(&p , &format, ap);
			if (p.cflag == 2)
				printstr[i++] = '\0';
			if(ptr)
			{
			while(ptr[x] && ptr)
				printstr[i++] = ptr[x++];
			}
			if (p.cflag == 1)
				printstr[i++] = '\0';
			ft_bzero(&p, sizeof(p));

			if(ptr != 0)
			{
				free(ptr);
				ptr = NULL;
			}
			x = 0;
		}
		else
		{

			if(*format != '\0')
				printstr[i++] = *format;
		}

		if(*format != '\0')
			format++;
	}
	// i = ft_strlen(printstr);
	// ft_putstr(printstr);
	write(1,&printstr,i);
	va_end(ap);
	return (i);
}
