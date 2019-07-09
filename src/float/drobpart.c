#include "ft_printf.h"

static int ft_countbit(long double nbr,int count)
{
	flag ptr1;
	union Byte x;
	x.i = nbr;
	ptr1.count = 63 - count;
	ptr1.two = 0;
	ptr1.one = 1;
	while(ptr1.count-- )
	{
		if(x.bitfield.mantissa & ptr1.one)
			ptr1.two++;
		ptr1.one =  ptr1.one << 1;
		count--;
	}
	return(ptr1.two);
}

char	**drobpart (long double nbr,int count)
{
	char **ptr;
	ptr = NULL;
	union Byte x;
	flag ptr1;
	x.i = nbr;
	ptr1.two = ft_countbit(nbr,count);
  if(ptr1.two == 0)
    return(NULL);
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
	ptr1.one = 1;
	ptr1.minus = 10000;
	ptr1.count = 63 - count;
	while(ptr1.count)
	{
		if(x.bitfield.mantissa & ptr1.one)
		{
			if(!(ptr[ptr1.two] = (char*)malloc(sizeof(char) * ptr1.minus)))
				return(NULL);
			ft_bzero(ptr[ptr1.two],sizeof(ptr[ptr1.two]));
			otr_step(ptr[ptr1.two],63 - count);
			ptr1.two++;
		}
		ptr1.one =  ptr1.one << 1;
		ptr1.count--;
		count++;
	}
	return(ptr);
}
