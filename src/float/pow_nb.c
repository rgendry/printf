#include "ft_printf.h"

unsigned long int ft_power(int pow)
{
	unsigned long int p;
	p = 1;
	if(pow == 0)
		return(1);
	while(pow)
	{
		p = p * 2;
		pow--;
	}
	return(p);
}
