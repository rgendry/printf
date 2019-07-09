#include "ft_printf.h"

int ft_znakk(long double nbr)
{
	union Byte x;
	int i;
	x.i = nbr;
	if(x.bitfield.znak & 1)
		i = -1;
	else
		i = 0;
	return(i);
}
