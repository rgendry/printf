#include "ft_printf.h"

char *parsflot(char *str,t_param *ft)
{
	int i;
	int c;
	int j;
	char *temp;
	temp = 0;
	j = 0;
	i = ft_strlen(str);
	if(ft->width > i)
		c = ft->width;
	else
		c = i;
	if(!(temp = (char *)malloc(sizeof(char) * (c + 1))))
		return (NULL);
	ft_bzero(temp,sizeof(temp));
	if(str[0] == '-' || ft->plus)
		ft->space = 0;
	if(ft->minus)
	{
		if(ft->space)
			temp[j++] = ' ';
		if(str[0] == '-')
		{
			temp[j++] = '-';
			ft->plus = 0;
		}
		if(ft->plus)
			temp[j++] = '+';
		if(*str == '-')
			str++;
		while(*str)
		{
			temp[j] = *str;
			str++;
			j++;
		}
		while(ft->width > j)
		{
			temp[j] = ' ';
			j++;
		}
		temp[j] = '\0';
	}
	else
	{
		if(str[0] == '-' || ft->plus)
			ft->width--;
		while(ft->width > i)
		{
			if(ft->zero)
			{
				if(ft->plus)
				{
					if(str[0] == '-')
					{
						temp[j++] = '-';
						ft->plus = 0;
					}
					else
					{
						temp[j++] = '+';
						ft->plus = 0;
					}
				}
				temp[j++] = '0';
			}
			else
				{
					temp[j] = ' ';
					j++;
				}
			ft->width--;
		}
		if(ft->plus && str[0] != '-')
			temp[j++] = '+';
		while(*str)
		{
			temp[j] = *str;
			j++;
			str++;
		}
	}
	temp[j] = '\0';
	return(temp);
}
