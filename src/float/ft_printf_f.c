#include "ft_printf.h"

static void rec_realpart(char *str)
{
	int i;
	int i1;
	int temp1;
	char c;
	i = ft_strlen(str) - 1;
  temp1 = 0;
  i1 = i;
  while(i != temp1)
  {
    c = str[i1];
    str[i1] = str[temp1];
    str[temp1] = c;
    i--;
    if(i == temp1)
      break;
    temp1++;
    i1--;
  }
}


void ft_memdel(char **ptr)
{
	int i;
	i = 0;
	while(ptr[i])
		{
			free(ptr[i]);
			i++;
		}
	free(ptr);
}
static char *ft_itogres(char *str,char *str1,number *d,t_param *ft)
{
	char *result;
	int i;
	int j;
	int c;
	int p ;
	result = NULL;
	c = 0;
	i = 0;
	j = 1;
	p = 0;
	if(!(result = (char*)malloc(sizeof(char) * 20000)))
		return (NULL);
	ft_bzero(result,sizeof(result));
	if(d->znak == -1)
		result[i++] = '-';
	if(ft->precision)
	{
		plusodinwithprecision(str1 + 1,ft);
		if(ft->cur_len == -1)
			plusonereal(str);
	}
	else if(ft->precision == 0 && ft->precision2)
	{
		if(str1[1] != '0')
		{
			if(str1[1] > '5')
				plusonereal(str);
			else if(str1[1] == '5' && str1[2] != '\0')
				plusonereal(str);
			else if(str1[1] == '5'&& str1[2] == '\0')
			{
				while(str[p])
					p++;
				p--;
				if((str[p] - '0') % 2)
					plusonereal(str);
			}
		}
		while(str[c])
			result[i++] = str[c++];
		result[i] = '\0';
		return(result);
	}
	else if(ft->precision == 0 && ft->precision2 == 0)
	{
		ft->precision = 6;
		plusodinwithprecision(str1 + 1,ft);
		if(ft->cur_len == -1)
			plusonereal(str);
	}

	while(str[c])
	{
		result[i] = str[c];
		i++;
		c++;
	}
	result[i++] = '.';
	if(str1[j])
	{
		while(str1[j])
			result[i++] = str1[j++];
	}
	else
	 i++;
	// else
	// {
	// 	while(j++ < 7)
	// 		result[i++] = '0';
	// }
	result[i] = '\0';
	return(result);
}

static char *countmanexp(union Byte *x,number *d,t_param *ft)
{
	char **ptr;
	char **ptr1;
	char *result;
	char mantissa[20000];
	char itogres[20000];
	ptr = NULL;
	ptr1 = NULL;
	result = NULL;
	ft_bzero(mantissa,20000);
	ft_bzero(itogres,20000);

	if (d->pow > 0 )
	{
		ptr = realpart(x->i,d->pow);
		if(d->pow < 64)
			ptr1 = drobpart(x->i,d->pow);
		ft_plus(mantissa,ptr);
		if(ptr1)
			ft_plus_drob(itogres,ptr1);
		else
			itogres[0] = '0';
		rec_realpart(mantissa);
		if(ptr1 && ptr1[1] != 0)
			rec_realpart(itogres);
	}
	else if(d->pow == 0)
	{
		mantissa[0] = '1';
		ptr1 = drobpart(x->i,d->pow);
		if(ptr1)
			ft_plus_drob(itogres,ptr1);
		if(ptr1 && ptr1[1] != 0)
			rec_realpart(itogres);
	}
	else if (d->pow < 0)
	{
	mantissa[0] = '0';
	ptr1 = drobpartminus(x->i,d->pow);
	ft_plus_minus(itogres,ptr1);
	if(ptr1 && ptr1[1] != 0)
		rec_realpart(itogres);
	}
	if(ptr)
		ft_memdel(ptr);
	if(ptr1)
		ft_memdel(ptr1);
	result = ft_itogres(mantissa, itogres,d,ft);
	return(result);
}

char		*ft_printf_f(t_param *ft, va_list ap)
{
	char *result;
	char *itogres;
	result = NULL;
	itogres = NULL;
	number d;
	double f;
	union Byte x;
	if(ft->L)
		x.i = va_arg(ap,long double);
	else
	{
		f = va_arg(ap, double);
		x.i = (long double)f;
	}
	d.znak = ft_znakk(x.i);
	d.pow = ft_count_poryadok(x.i);
	if(x.i == 1.0/0.0)
		result = ft_strdup("infinity");
	else if(x.i == -1.0/0.0)
		result = ft_strdup("infinity");
	else if(x.i != x.i)
		result = ft_strdup("NaN");
	else
		result = countmanexp(&x,&d,ft);
	itogres = parsflot(result,ft);
	free(result);
	return(itogres);
}
