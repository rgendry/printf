#include "ft_printf.h"

void otr_step(char *str,int pow)
{
	char **count;
	char *ptr;
	char *ptr1;
	ptr = NULL;
	ptr1 = NULL;
	count = NULL;
	ptr1 = "000000000931322574615478515625";
	int i;
	int p;
	int c;
	int k;
	c = 1;
	p = 0;
	if(pow > 30)
		i = pow / 30;
	else
	{
		c = ft_power(pow);
		delenie(str ,1, c, 0);
		return;
	}
	if(i)
		if(!(count = (char**)malloc(sizeof(char*) * (i + 1))))
			return;
	k = i;
	while (i > 0)
	{
		if(!(count[p] = (char*)malloc(sizeof(char) * 30)))
			return;
		ft_bzero(count[p],sizeof(count[p]));
		ft_strcpy(count[p],ptr1);
		p++;
		i--;
	}
	pow = pow % 30;
	if(!(count[p] = (char*)malloc(sizeof(char) * 1000)))
		return ;
	c = ft_power(pow);
	ft_bzero(count[p],sizeof(count[p]));
	delenie(count[p] ,1, c, 0);
	ptr = multiplication(count[p],count[p - 1],ft_strlen(count[p]), ft_strlen(count[p-1]));
	ft_strcpy(str,ptr);
	free(ptr);
	p = p - 2;
	while(p > -1)
	{
		ptr = multiplication(str,count[p],ft_strlen(str), ft_strlen(count[p]));
		ft_strcpy(str,ptr);
		free(ptr);
		p--;
	}
	p = 0;
	while(k > -1)
	{
		free(count[k]);
		k--;
	}
	free(count);

}
