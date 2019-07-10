/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slozhenieminusdrob.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:28:56 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/10 21:03:17 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_end_pm(int len1, int i, char *str, char **ptr)
{
	int	j;
	int	temp[3];

	j = 0;
	temp[0] = 0;
	temp[1] = i;
	temp[2] = 0;
	while (len1-- > -1)
	{
		while (i-- > - 1)
			temp[0] = temp[0] + (int)ptr[i][len1] - '0';
		temp[2] = temp[0] % 10;
		str[j] = temp[2] + 48;
		j++;
		temp[0] = temp[0] / 10;
		i = temp[1];
	}
	if (temp[0] != 0)
	{
		str[j] = temp[0] + '0';
		j++;
	}
	str[j] = '\0';
}

void	ft_mid_pm(char **ptr, char *str)
{
	int	len1;
	int	i;
	int	j;

	len1 = ft_strlen(ptr[1]);
	i = 0;
	j = 0;
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
	len1--;
	ft_end_pm(len1, i, str, ptr);
}

void	ft_plus_minus(char *str, char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	if (i == 1)
	{
		ft_strcpy(str, ptr[0]);
		return ;
	}
	ft_mid_pm(ptr, str);
}
