#include "float.h"

int ft_count_poryadok(double nbr)
{
	union Byte x;
	int pow;
	flag ptr;
	x.i = nbr;
	ptr.count = 11;
	pow = 0;
	ptr.two = 1;
	ptr.one = 1;
	while(ptr.count--)
	{
		if(x.bitfield.poryadok & ptr.one)
			pow = pow + ptr.two;
		ptr.two *= 2;
		ptr.one <<= 1;
	}
	pow = pow - 1023;
	return(pow);
}
