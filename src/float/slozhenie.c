/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slozhenie.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:28:42 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/10 21:40:04 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_end_pl(int len1, int i, char **ptr, char *str)
{
	int j;
	int temp[3];

	temp[0] = 0;
	temp[1] = i;
	temp[2] = 0;
	j = 0;
	while(len1 > -1)
	{
		while(i > - 1)
		{
			temp[0] = temp[0] + (int)ptr[i][len1] - '0';
			i--;
		}
		temp[2] = temp[0] % 10;
		str[j] = temp[2] + '0';
		j++;
		temp[0] = temp[0] / 10;
		len1--;
		i = temp[1];
	}
	if(temp[0] != 0)
	{
		str[j] = temp[0] + '0';
		j++;
	}
	str[j] = '\0';
}

void	ft_mid_pl(char **ptr, int len1, char *tempstr, char *str)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (ptr[j])
	{
		while (ptr[j][i])
			i++;
		while (len1 > i++)
		{
			tempstr[c] = '0';
			c++;
		}
		ft_strcpy(tempstr + c, ptr[j]);
		ft_strcpy(ptr[j], tempstr);
		c = 0;
		i = 0;
		j++;
	}
	while (ptr[i])
		i++;
	i--;
	len1--;
	ft_end_pl(len1, i, ptr, str);
}

void	ft_plus(char *str, char **ptr)
{
	int		len1;
	int		i;
	char	tempstr[20000];

	i = 0;
	while (ptr[i])
		i++;
	if (i == 1)
	{
		ft_strcpy(str, ptr[0]);
		return ;
	}
	len1 = ft_strlen(ptr[0]);
	ft_mid_pl(ptr, len1, tempstr, str);
}
