/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_mas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:28:07 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/11 14:21:17 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*rec_mas(char **str)
{
	char	*result;
	int		i;
	int		i1;
	char	c;
	int		temp1;

	result = *str;
	i = ft_strlen(result) - 1;
	temp1 = 0;
	i1 = i;
	while (i != temp1)
	{
		c = result[i1];
		result[i1] = result[temp1];
		result[temp1] = c;
		i--;
		if (i == temp1)
			break ;
		temp1++;
		i1--;
	}
	return (result);
}
