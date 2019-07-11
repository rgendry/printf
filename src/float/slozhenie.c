/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slozhenie.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:28:42 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/11 15:12:52 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_end_pl(int len1, int i, char **ptr, char *str)
{
	int j[4];

	j[0] = 0;
	j[1] = i;
	j[2] = 0;
	j[3] = 0;
	while (len1 > -1)
	{
		while (i > -1)
		{
			j[0] = j[0] + (int)ptr[i][len1] - '0';
			i--;
		}
		j[2] = j[0] % 10;
		str[j[3]] = j[2] + '0';
		j[3]++;
		j[0] = j[0] / 10;
		len1--;
		i = j[1];
	}
	if (j[0] != 0)
	{
		str[j[3]] = j[0] + '0';
		j[3]++;
	}
	str[j[3]] = '\0';
}

void	ft_mid_pl(char **ptr, int len1, char *tempstr, char *str)
{
	int	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (ptr[i[1]])
	{
		while (ptr[i[1]][i[0]])
			i[0]++;
		while (len1 > i[0]++)
		{
			tempstr[i[2]] = '0';
			i[2]++;
		}
		ft_strcpy(tempstr + i[2], ptr[i[1]]);
		ft_strcpy(ptr[i[1]], tempstr);
		i[2] = 0;
		i[0] = 0;
		i[1]++;
	}
	while (ptr[i[0]])
		i[0]++;
	i[0]--;
	len1--;
	ft_end_pl(len1, i[0], ptr, str);
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
