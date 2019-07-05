#include "ft_printf.h"

void   ft_plus(char *str,char **ptr)
{
	//char *str2;
	//char *str1;
	int len1;
	//int len2;
	//int len3;
	int i;
	int j;
	//int c;
	int temp;
	int temp1;
	int count;
	temp1 = 0;
	temp = 0;
	//c = 0;
	j = 0;
	i = 0;
	while(ptr[i])
	{
		printf("ptr = %s\n",ptr[i]);
		i++;
	}
	if(i == 1)
		{
			str[0] = '1';
			strcpy(str + 1,ptr[0] + 1);
			free(ptr);
		}
	i--;

	len1 = strlen(ptr[i]);
	i = 0;
	while(ptr[j])
	{
		while(ptr[j][i])
			i++;
		while(len1 > i)
		{
			ptr[j][i] = '0';
			i++;
		}
		i = 0;
		j++;
	}
	len1--;
	j--;
	count = j;
	while(len1 > -1)
	{
		while(j > -1)
		{
			//if(ptr[j][len1] != '0')
				temp = temp1 + temp + ((int)(ptr[j][len1]-48));
				temp1 = 0;
			j--;
		}
	temp1 = temp / 10;
	temp = temp % 10;
	str[len1] = temp + 48;
	temp = 0;
	j = count;
	len1--;
	}
	str[0] = '1';
	printf("ptr = %s\n",str);
	i = 0;
	while(ptr[i])
	{
		free(ptr[i]);
		i++;
	}

	// while(j <= i && i != 1)
	// {
	// 	len1 = strlen(ptr[i]);
	// 	len2 = strlen(ptr[i-1]);
	// 	str = (char*)malloc(sizeof(char) * (len1 + 1)
	//
	// }
	free(ptr);
}
