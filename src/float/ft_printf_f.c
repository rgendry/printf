#include "ft_printf.h"

char		*ft_printf_f(t_param *ft, va_list ap)
{
	ft->cur_len = 1;
	number d;
	char **ptr;
	union Byte x;
	x.i = va_arg(ap,double);
	// int pow;
	// int mant;
	// int znak;
	char *dores;
	x.i = 54;
	char exponenta[150];
	char mantissa[150];
	char itogres[150];
	//char result[500];
	ft_bzero(exponenta,150);
	ft_bzero(mantissa,150);
	//ft_bzero(result,500);
	char *result;
	d.znak = ft_znakk(x.i);
	d.pow = ft_count_poryadok(x.i);
	d.mant = ft_count_mantisa(x.i);
	printf("powpow = %d\n",d.pow);
	printf("man = %llu\n",d.mant);
	printf("znak = %d",d.znak);
	ptr = mantis_str(x.i);
	ft_plus(mantissa,ptr);


	if (d.pow >= 0)
		{
			vozvedenie(exponenta,d.pow,"2");
			d.len = strlen(exponenta);   //d.len x2
		}
	else
	{
		d.count = -1;
		d.pow = d.pow * (-1);
		otr_step(exponenta,d.pow);
	}
	printf("exponenta = %s\n",exponenta);
	d.len = strlen(exponenta);
	printf("%d\n",d.len);
	result = multiplication(mantissa, exponenta, strlen(mantissa), strlen(exponenta));
	printf("result = %s\n",result);
	printf("%.40f\n",x.i);

	printf("%d\n",d.pow);
		if (d.count == -1)
		{
			if(d.znak == -1)
			{
				itogres[0] = '-';
				itogres[1] = '0';
				itogres[2] = '.';
				strcpy(itogres + 3, result + 2);
			}
			else
			{
				itogres[0] = '0';
				itogres[1] = '.';
				strcpy(itogres + 2, result + 2);
			}
		}
		else
		{

			if(d.znak == -1)
			{
				itogres[0] = '-';
				d.count = 1;

			while(d.len)
			{
				itogres[d.count] = result[d.count];
				d.len--;
				d.count++;
			}
			itogres[d.count] = '.';
			strcpy(itogres + d.count + 1, result + d.count);
			}
			else
			{
				d.count = 0;
				while(d.len)
				{
					itogres[d.count] = result[d.count + 1];
					d.len--;
					d.count++;
				}
				itogres[d.count] = '.';
				strcpy(itogres + d.count + 1, result + d.count + 1);
			}
		}
	free(result);
	printf("itoooooooog = %s\n",itogres);
	dores = ft_strdup(itogres);
		return (dores);
}
