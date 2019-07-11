/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vozvedenie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:29:06 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/11 14:21:58 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	vozvedenie(char *str, int pow, char *c)
{
	int		i;
	char	*ptr;

	ptr = NULL;
	i = 0;
	str[0] = '1';
	while (pow > 0)
	{
		pow--;
		ptr = multiplication(str, c, ft_strlen(str), 1);
		while (ptr[i] == '0')
			i++;
		ft_strcpy(str, ptr + i);
		i = 0;
		free(ptr);
	}
}
