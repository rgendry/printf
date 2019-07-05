#include "ft_printf.h"

int ft_power(int pow)
{
	int p;
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
