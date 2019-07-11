/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingfloat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:50:15 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/11 16:18:57 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*parsflot_mid(t_param *ft, char *temp, char *str)
{
	int j;

	j = 0;
	if (ft->space)
		temp[j++] = ' ';
	if (str[0] == '-')
	{
		temp[j++] = '-';
		ft->plus = 0;
	}
	if (ft->plus)
		temp[j++] = '+';
	if (*str == '-')
		str++;
	while (*str)
		temp[j++] = *str++;
	while (ft->width > j)
	{
		temp[j] = ' ';
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

char	*parsflot_end1(t_param *ft, char *temp, char *str, int j)
{
	if (ft->plus && str[0] != '-')
		temp[j++] = '+';
	while (*str)
		temp[j++] = *str++;
	temp[j] = '\0';
	return (temp);
}

char	*parsflot_end(t_param *ft, char *temp, char *str, int i)
{
	int j;

	j = 0;
	if (str[0] == '-' || ft->plus)
		ft->width--;
	if (ft->space)
		temp[j++] = ' ';
	while (ft->width-- > i)
	{
		if (ft->zero)
		{
			if (ft->plus)
			{
				(str[0] == '-') ? temp[j++] = '-' : '+';
				ft->plus = 0;
			}
			temp[j++] = '0';
		}
		else
		{
			temp[j] = ' ';
			j++;
		}
	}
	return (parsflot_end1(ft, temp, str, j));
}

char	*parsflot(char *str, t_param *ft)
{
	int		i;
	int		c;
	char	*temp;

	c = 0;
	i = ft_strlen(str);
	ft->width > i ? c = ft->width : i;
	if (!(temp = (char *)malloc(sizeof(char) * (c + 1))))
		return (NULL);
	ft_bzero(temp, sizeof(temp));
	(str[0] == '-' || ft->plus) ? ft->space = 0 : ft->space;
	if (ft->minus)
		temp = parsflot_mid(ft, temp, str);
	else
		temp = parsflot_end(ft, temp, str, i);
	return (temp);
}
