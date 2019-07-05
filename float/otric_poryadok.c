#include "float.h"

void otr_step(char *str,int pow)
{
	char **count;
	char *ptr;
	char *ptr1;
	ptr1 = "000000000931322574615478515625";
	int i;
	int p;
	int c;
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
	while (i > 0)
	{
		if(!(count[p] = (char*)malloc(sizeof(char) * 30)))
			return;
		strcpy(count[p],ptr1);
		p++;
		i--;
	}
	pow = pow % 30;
	if(!(count[p] = (char*)malloc(sizeof(char) * pow)))
		return;
	if(pow == 0)
		count[p] = "1";
	c = ft_power(pow);
	delenie(count[p] ,1, c, 0);
	ptr = multiplication(count[p],count[p - 1],strlen(count[p]), strlen(count[p-1]));
	strcpy(str,ptr);
	free(ptr);
	p = p - 2;
	while(p > -1)
	{
		ptr = multiplication(str,count[p],strlen(str), strlen(count[p]));
		strcpy(str,ptr);
		free(ptr);
		p--;
	}
	p = 0;
	while(p < i + 2)
	{
		free(count[p]);
		p++;
	}
	free(count);
}
