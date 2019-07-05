#include "float.h"

char *multiplication(char *a, char *b, int size1, int size2)
{
	flag ptr;
  char *result;
  int i1;
  int i;
  ptr.one = 0;
  i = 0;
  i1 = 0;
  result = (char*)malloc(sizeof(char) * (size1 + size2 + 1));
  ft_bzero(result,size1 + size2 +1);
  while(--size2 > -1)
  {
		ptr.count = size1;
    while(--ptr.count > -1)
    {
			if(i == 0)
				 ptr.two = (ptr.one + (a[ptr.count] - 48) * (b[size2] - 48));
			else
      	ptr.two = (ptr.one + (a[ptr.count] - 48) * (b[size2] - 48)) + (result[i1] - 48);
      ptr.one = ptr.two / 10;
      result[i1++] = (ptr.two % 10) + '0';
    }
    result[i1] = ptr.one + '0';
    ptr.one = 0;
    i++;
    i1 = i;
  }
	rec_mas(&result);
  return(result);
}
