/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slosheniedrob.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:28:28 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/10 21:44:36 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_plus_drob(char *str,char **ptr)
{
	int len1;
	int i;
	int j;
	int temp;
	int temp1;
	int temp2;

	temp1 = 0;
	temp = 0;
	j = 0;
	i = 0;
	while (ptr[i])
		i++;
	if (i == 1)
	{
		ft_strcpy(str, ptr[0]);
		return ;
	}
	len1 = ft_strlen(ptr[0]);
	i = 0;
	while (ptr[j])
	{
		while (ptr[j][i])
			i++;
		while (len1 > i)
		{
			ptr[j][i] = '0';
			i++;
		}
		i = 0;
		j++;
	}
	while (ptr[i])
		i++;
	i--;
	temp1 = i;
	j = 0;
	len1--;
	while (len1 > -1)
	{
		while (i > - 1)
		{
			temp = temp + (int)ptr[i][len1] - '0';
			i--;
		}
		temp2 = temp % 10;
		str[j] = temp2 + '0';
		j++;
		temp = temp / 10;
		len1--;
		i = temp1;
	}
	if (temp != 0)
	{
		str[j] = temp + '0';
		j++;
	}
	str[j] = '\0';
}
