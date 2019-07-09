#include "ft_printf.h"


static int ft_countbit(long double nbr,int count)
{
	flag ptr1;
	union Byte x;
	x.i = nbr;
	ptr1.count = 63;
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

char	**drobpartminus (long double nbr,int count)
{
	char **ptr;
	union Byte x;
	flag ptr1;
	ptr = NULL;
	x.i = nbr;
	ptr1.two = ft_countbit(nbr,count) + 1;
  if(ptr1.two == 0)
    return(NULL);
	if(!(ptr = (char**)malloc(sizeof(char*) * (ptr1.two + 1))))
		return(NULL);
	ptr1.minus = 20000;
	ptr[ptr1.two] = 0;
	ptr1.two = 0;
	count = count * -1;
	if(!(ptr[ptr1.two] = (char*)malloc(sizeof(char) * ptr1.minus)))
		return(NULL);
	ft_bzero(ptr[ptr1.two],sizeof(ptr[ptr1.two]));
	otr_step(ptr[ptr1.two], count);
	ptr1.two++;
	ptr1.one = 1;
	ptr1.count = 63;
	count = count + 63;
	while(ptr1.count)
	{
		if(x.bitfield.mantissa & ptr1.one)
		{
			if(!(ptr[ptr1.two] = (char*)malloc(sizeof(char) * ptr1.minus)))
				return(NULL);
			ft_bzero(ptr[ptr1.two],sizeof(ptr[ptr1.two]));
			otr_step(ptr[ptr1.two],count);
			ptr1.two++;
		}
		ptr1.one =  ptr1.one << 1;
		ptr1.count--;
		count--;
	}
	return(ptr);
}
