/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:23:00 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/05 18:30:25 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printfper(t_param *ft, va_list ap)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * 1);
	ptr[1] = '\0';
	ptr[0] = '%';
	return (ptr);
}
