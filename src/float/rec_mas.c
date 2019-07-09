#include "ft_printf.h"

char *rec_mas(char **str)
{
	char *result;
	result = NULL;
	int i;
	int i1;
	char c;
	int temp1;
	result = *str;
	i = ft_strlen(result) - 1;
  temp1 = 0;
  i1 = i;
  while(i != temp1)
  {
    c = result[i1];
    result[i1] = result[temp1];
    result[temp1] = c;
    i--;
    if(i == temp1)
      break;
    temp1++;
    i1--;
  }
	return(result);
}
