#ifndef FLOAT_H
#define FLOAT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct byte
{
			unsigned long long int mantissa:52;
  		unsigned int poryadok:11;
			unsigned int znak:1;
};
union Byte
{
    double i;
    struct byte bitfield;
};
typedef struct
{
	int minus;
	int count;
	unsigned long long int two;
	unsigned long long int one;
}flag;
typedef struct
{
	int pow;
	int znak;
	unsigned long long mant;
	int len;
	int count;
}number;
void delenie(char *str,unsigned long long int rem, unsigned long long int sub, int i);
void	ft_bzero(void *str, size_t len);
char *multiplication(char *a, char *b, int size1, int size2);
void vozvedenie(char *str5,int pow,char *c);
int ft_count_poryadok(double nbr);
int ft_znak(double nbr);
unsigned long long int ft_count_mantisa(double nbr);
char *rec_mas(char **str);
void otr_step(char *str,int pow);
char	**mantis_str (double nbr);
void   ft_plus(char *str,char **ptr);
int ft_power(int pow);


#endif
