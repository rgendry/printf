#include "ft_printf.h"

void delenie(char *str,unsigned long long int rem, unsigned long long int sub, int i)
{
  unsigned long long int temp = sub;
  int quot = 0;
  if(rem == 0 || i == 1000)
  {
    str[i] = '\0';
    return ;
  }
  int add = 1;
  int shifts = 1;
  while( rem > sub )
  {
      sub <<= 1;
      add <<= 1;
      shifts++;
    }
    while( shifts )
    {
      while( rem >= sub )
      {
        rem -= sub;
        quot += add;
      }
      sub >>= 1;
      add >>= 1;
      shifts--;
    }
    str[i] = quot + 48;
    i++;
    delenie(str,rem * 10, temp, i);
}
