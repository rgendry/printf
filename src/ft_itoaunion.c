/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaunion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  blomo < blomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:09:50 by  blomo            #+#    #+#             */
/*   Updated: 2019/07/09 15:42:46 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_lenght(unsigned int n)
{
	unsigned long long int res;
	int count;
	res = n;
	count = 0;
	if (n == 0)
		count++;
	while (res != 0)
	{
		count++;
		res = res / 10;
	}
	return (count);
}

char			*ft_itoauun(unsigned int n)
{
	int				count;
	unsigned int				res;
	int				neg;
	char			*out;

	neg = 0;
	res = n;
	// if (n < 0)
	// {
	// 	ft->cur_len = -1;
	// 	neg = 0;
	// 	res = (unsigned)n * -1;
	// }
	count = ft_lenght(res) + neg;
	out = (char*)malloc(sizeof(char) * (count + 1));
	if (!(out))
		return (NULL);
	out[count] = '\0';
	// if (neg == 1)
	// 	out[0] = '-';
	while (count-- > neg)
	{
		out[count] = (char)(res % 10 + '0');
		res /= 10;
	}
	return (out);
}



char			*ft_itoaun(int n,t_param *ft)
{
	int				count;
	unsigned int				res;
	int				neg;
	char			*out;

	neg = 0;
	res = n;
	if (n < 0)
	{
		ft->cur_len = -1;
		neg = 0;
		res = (unsigned)n * -1;
	}
	count = ft_lenght(res) + neg;
	out = (char*)malloc(sizeof(char) * (count + 1));
	if (!(out))
		return (NULL);
	out[count] = '\0';
	// if (neg == 1)
	// 	out[0] = '-';
	while (count-- > neg)
	{
		out[count] = (char)(res % 10 + '0');
		res /= 10;
	}
	return (out);
}

static int		ft_lenghtsc(signed char n)
{
	unsigned char res;
	int count;

	res = n;
	count = 0;
	if (n == 0)
		count++;
	while (res != 0)
	{
		count++;
		res = res / 10;
	}
	return (count);
}

char			*ft_itoaunsc(signed char n,t_param *ft)
{

	int				count;
	unsigned char	res;
	int				neg;
	char			*out;

	neg = 0;
	res = n;
	if (n < 0)
	{
		ft->cur_len = -1;
		neg = 0;
		res = (unsigned)n * -1;
	}
	count = ft_lenghtsc(res) + neg;
	out = (char*)malloc(sizeof(char) * (count + 1));
	if (!(out))
		return (NULL);
	out[count] = '\0';
	// if (neg == 1)
	// 	out[0] = '-';
	while (count-- > neg)
	{
		out[count] = (char)(res % 10 + '0');
		res /= 10;
	}
	return (out);
}




static int		ft_lenghtsi(unsigned short  int n)
{
	unsigned	short  int res;
	int count;

	res = n;
	count = 0;
	if (n == 0)
		count++;
	while (res != 0)
	{
		count++;
		res = res / 10;
	}
	return (count);
}

char			*ft_itoaunsi(signed short int n,t_param *ft )
{
 	int				count;
	short unsigned int	res;
	int				neg;
	char			*out;

	neg = 0;
	res = n;
	if (n < 0)
	{
		ft->cur_len = -1;
		neg = 0;
		res = (unsigned)n * -1;
	}
	count = ft_lenghtsi(res) + neg;
	out = (char*)malloc(sizeof(char) * (count + 1));
	if (!(out))
		return (NULL);
	out[count] = '\0';
	if (neg == 1)
		out[0] = '-';
	while (count-- > neg)
	{
		out[count] = (char)(res % 10 + '0');
		res /= 10;
	}
	return (out);
}

static int		ft_lenghtll(unsigned long long int n)
{
	unsigned long long int res;
	int count;

	res = n;
	count = 0;
	if (n == 0)
		count++;
	while (res != 0)
	{
		count++;
		res = res / 10;
	}
	return (count);
}

char			*ft_itoaunll(unsigned long long int n)
{
	int				count;
	unsigned long long int	res;
	int				neg;
	char			*out;

	neg = 0;
	res = n;
	// if (n < 0)
	// {
	// 	ft->cur_len = -1;
	// 	neg = 0;
	// 	res = (unsigned)n * -1;
	// }
	count = ft_lenghtll(res) + neg;
	out = (char*)malloc(sizeof(char) * (count + 1));
	if (!(out))
		return (NULL);
	out[count] = '\0';
	// if (neg == 1)
	// 	out[0] = '-';
	while (count-- > neg)
	{
		out[count] = (char)(res % 10 + '0');
		res /= 10;
	}
	return (out);
}

static int		ft_lenghtsiU(unsigned short  int n)
{
	unsigned	short  int res;
	int count;

	res = n;
	count = 0;
	if (n == 0)
		count++;
	while (res != 0)
	{
		count++;
		res = res / 10;
	}
	return (count);
}

char			*ft_itoaunsiUU(unsigned short int n)
{
 	int				count;
	short unsigned int	res;
	int				neg;
	char			*out;

	neg = 0;
	res = n;

	count = ft_lenghtsiU(res) + neg;
	out = (char*)malloc(sizeof(char) * (count + 1));
	if (!(out))
		return (NULL);
	out[count] = '\0';
	if (neg == 1)
		out[0] = '-';
	while (count-- > neg)
	{
		out[count] = (char)(res % 10 + '0');
		res /= 10;
	}
	return (out);
}
