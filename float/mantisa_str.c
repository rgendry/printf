#include "float.h"


int ft_countbit(double nbr)
{
	flag ptr1;
	union Byte x;
	x.i = nbr;
	ptr1.count = 52;
	ptr1.two = 0;
	ptr1.one = 1;
	while(ptr1.count--)
	{
		if(x.bitfield.mantissa & ptr1.one)
			ptr1.two++;
		ptr1.one <<= 1;
	}
	return(ptr1.two);
}

char	**mantis_str (double nbr)
{
	//char ll[300];
	char **ptr;
	union Byte x;
	flag ptr1;
	x.i = nbr;
	// int c;
	// c = 0;
	ptr1.two = ft_countbit(nbr);
	printf("countbit = %llu\n",ptr1.two);
	if(!(ptr = (char**)malloc(sizeof(char*) * (ptr1.two + 1))))
		return(NULL);
	if(ptr1.two == 0)
		{
			if(!(ptr[0] = (char*)malloc(sizeof(char) * 1)))
				return(NULL);
			ptr[1] = 0;
			ptr[0] = "0";
			return(ptr);
		}
	ptr[ptr1.two] = 0;
	ptr1.two = 0;
	ptr1.one = 2251799813685248;
	ptr1.minus = 70;
	ptr1.count = 1;
	//ptr1.two--;
	while(ptr1.count < 53)
	{
		if(x.bitfield.mantissa & ptr1.one)
		{
			printf("ptrrrrrrrrrrrrrrrr      %d\n",ptr1.count);
			//printf("ptrrrrrrrrrrrrrrrfffffffffr      %d\n",ptr1.count);
			// otr_step(ll, ptr1.count);
			// ptr1.minus = strlen(ll);
			if(!(ptr[ptr1.two] = (char*)malloc(sizeof(char) * ptr1.minus)))
				return(NULL);
			otr_step(ptr[ptr1.two],ptr1.count);
			printf("countbit = %llu\n",ptr1.one);
			ptr1.two++;
		}
		ptr1.one =  ptr1.one >> 1;
		ptr1.count++;
	}

	// while(ptr != 0)
	// {
	// 	printf("gjfjjfgj%s\n",*ptr);
	// 	ptr++;
	// }
	return(ptr);
}
