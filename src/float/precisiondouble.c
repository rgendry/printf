#include "ft_printf.h"

static void rec_double(char *str)
{
	int i;
	int i1;
	int temp1;
	char c;
	i = ft_strlen(str) - 1;
  temp1 = 0;
  i1 = i;
  while(i != temp1)
  {
    c = str[i1];
    str[i1] = str[temp1];
    str[temp1] = c;
    i--;
    if(i == temp1)
      break;
    temp1++;
    i1--;
  }
}

void plusodinwithprecision(char *str,t_param *ft)
{
	int i;
	int temp;
	i = 0;
	temp = 1;
	while(str[i])
		i++;
	if(i < ft->precision)
	{
		i = 0;
		while(i < ft->precision)
		{
			if(str[i])
				i++;
			else
				str[i++] = '0';
		}
		str[i] = '\0';
		return;
	}

	if(i > ft->precision)
		{
			if(str[ft->precision] != '\0' && str[ft->precision] > '5')
			{
				i = ft->precision -1;
				while(i > -1)
				{
					temp = temp + str[i] - '0';
					if(temp > 9)
							{
								str[i] = '0';
								temp = 1;
								i--;
							}
							else
							{
								str[i] = temp + '0';
								temp = 0;
								i--;
							}
				}
				if(temp)
					ft->cur_len = -1;
				}
				else if(str[ft->precision] == '5')
					{
						if(str[ft->precision+1] != '\0')
						{
							i = ft->precision-1;
							while(i > -1)
							{
								temp = temp + str[i] -'0';
								if(temp > 9)
										{
											str[i] = '0';
											temp = 1;
											i--;
										}
										else
										{
											str[i] = temp + '0';
											temp = 0;
											i--;
										}
							}
							if(temp)
								ft->cur_len = -1;
						}
				}
				str[ft->precision] = '\0';
			}
}

void plusonereal(char *str)
{
	int i;
	int j;
	int temp;
	char str1[20000];
	temp = 1;
	i = 0;
	j = 0;
	while(str[i])
		i++;
	i--;
	while(i > -1)
	{
		temp = temp + str[i] - '0';
		if(temp > 9)
		{
			str1[j] = '0';
			temp = 1;
		}
		else
		{
			str1[j] = temp + '0';
			temp = 0;
		}
		i--;
		j++;
	}
	if(temp)
		str1[j++] = '1';
	str1[j] = '\0';
	ft_bzero(str,sizeof(str));
	rec_double(str1);
	ft_strcpy(str,str1);
}
