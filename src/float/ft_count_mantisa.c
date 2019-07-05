#include "ft_printf.h"

unsigned long long int ft_count_mantisa(double nbr)
{
	union Byte x;
	unsigned long long man;
	flag ptr;
	x.i = nbr;
	ptr.count = 52;
	man = 1;
	ptr.two = 1;
	ptr.one = 1;
	while(ptr.count--)
	{
		if(x.bitfield.mantissa & ptr.one)
		{
			man = man + ptr.two;
			printf(" count = mant = %d\n", ptr.count);
		}
		ptr.two *= 2;
		ptr.one <<= 1;
	}
	return(man);
}
