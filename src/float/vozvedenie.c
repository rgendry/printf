#include "ft_printf.h"

void vozvedenie(char *str, int pow, char *c)
{
  int i;
  char *ptr;
	ptr = NULL;
  i = 0;
  str[0] = '1';
  while (pow > 0)
    {
      pow--;
      ptr = multiplication(str,c,ft_strlen(str), 1);
      while(ptr[i] == '0')
        i++;
      ft_strcpy(str,ptr + i);
      i = 0;
      free(ptr);
    }
}
