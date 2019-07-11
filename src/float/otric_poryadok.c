/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otric_poryadok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:19:35 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/11 16:04:18 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	otr_step_end(char **count, int p, char *str, int k)
{
	char	*ptr;

	ptr = multiplication(count[p], count[p - 1], ft_strlen(count[p]),
		ft_strlen(count[p - 1]));
	ft_strcpy(str, ptr);
	free(ptr);
	p = p - 2;
	while (p > -1)
	{
		ptr = multiplication(str, count[p], ft_strlen(str),
			ft_strlen(count[p]));
		ft_strcpy(str, ptr);
		free(ptr);
		p--;
	}
	p = 0;
	while (k > -1)
	{
		free(count[k]);
		k--;
	}
	free(count);
}

void	otr_step_mid(char **count, int i, char *str, int pow)
{
	int		k;
	int		p;
	int		c;
	char	*ptr1;

	k = i;
	p = 0;
	ptr1 = "000000000931322574615478515625";
	while (i > 0)
	{
		if (!(count[p] = (char*)malloc(sizeof(char) * 30)))
			return ;
		ft_bzero(count[p], sizeof(count[p]));
		ft_strcpy(count[p], ptr1);
		p++;
		i--;
	}
	pow = pow % 30;
	if (!(count[p] = (char*)malloc(sizeof(char) * 1000)))
		return ;
	c = ft_power(pow);
	ft_bzero(count[p], sizeof(count[p]));
	delenie(count[p], 1, c, 0);
	otr_step_end(count, p, str, k);
}

void	otr_step(char *str, int pow)
{
	int		i;
	int		c;
	char	**count;

	count = NULL;
	c = 1;
	if (pow > 30)
		i = pow / 30;
	else
	{
		c = ft_power(pow);
		delenie(str, 1, c, 0);
		return ;
	}
	if (i)
		if (!(count = (char**)malloc(sizeof(char*) * (i + 1))))
			return ;
	otr_step_mid(count, i, str, pow);
}
