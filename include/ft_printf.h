/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 12:54:30 by olesgedz          #+#    #+#             */
/*   Updated: 2019/07/10 17:53:34 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
# include <float.h>
# include <limits.h>

typedef struct				s_param
{
	int						plus:1;
	int						minus:1;
	int						space:1;
	int						reshetka:1;
	int						zero:1;
	int						l:1;
	int						ll:1;
	int						h:1;
	int						hh:1;
	int						j:1;
	int						z:1;
	int						L:1;
	int						width;
	int						precision;
	int						precision1;
	int						precision2;
	int						cur_len;
	int						cflag;
}							t_param;

union						u_format
{
	char					c;
	char					*s;
	signed char				sc;
	unsigned char			uc;
	wchar_t					*ws;
	wchar_t					wc;
	int						d;
	short int				shi;
	unsigned short int		ushi;
	unsigned int			ud;
	unsigned long			ul;
	unsigned long long		ull;
	long					ld;
	long long				lld;
};

struct						byte
{
	unsigned long long int	mantissa:64;
	unsigned int			poryadok:15;
	unsigned int			znak:1;
};

union						Byte
{
	long double				i;
	struct byte				bitfield;
};

typedef struct
{
	unsigned long long int	minus;
	signed long long int	count;
	unsigned long long int	two;
	unsigned long long int	one;
}							flag;

typedef struct
{
	int						pow;
	int						znak;
	unsigned long long		mant;
	int						len;
	int						count;
}							number;

int					ft_printf(char *format, ...);
char				*ft_param(t_param *p, char **format, va_list ap);
void				ft_parammode(t_param *param, char **format, va_list ap);
void				ft_printf_flags(t_param *param, char **format);
int					ft_nlen_base(long i, int base);
void				ft_printf_lenmod(t_param *param, char **format);
char				*ft_printf_d_default(t_param *ft, char *str);
char				*ft_printf_d(t_param *ft, va_list ap, union u_format f);
char				*ft_itoaunsc(signed char n, t_param *ft);
char				*ft_itoauun(unsigned int n);
char				*ft_printf_u(t_param *ft, va_list ap, union u_format f);
void				ft_strcpy(char *dest, const char *src);
char				*ft_printfper(t_param *ft);
char				*ft_addjoin(char *s1, char *s2);
char				*ft_tmp_str(t_param *ft, int size);
char				*ft_printf_p(t_param *ft, va_list ap);
char				*ft_itoaun(int n, t_param *ft);
char				*ft_itoaunsi(short signed int n, t_param *ft);
char				*ft_itoaunll(unsigned long long int n);
char				*ft_itoaunsiUU(unsigned short int n);
void				ft_bzero(void *str, size_t len);
int					ft_atoi(const char *str);
char				*ft_printf_c(t_param *ft, va_list ap);
char				*ft_printf_s(t_param *ft, va_list ap);
char				*ft_printf_x(t_param *ft, va_list ap, union u_format f);
int					ft_lldlen_base(long long value, int base);
int					ft_ulld_len_base(unsigned long long value, int base);
int					ft_uld_len_base(unsigned long value, int base);
int					ft_ud_len_base(unsigned int value, int base);
int					ft_nlen_base(long value, int base);
char				*ft_ulldtoa_base(unsigned long long value, int base);
char				*ft_uldtoa_base(unsigned long value, int base);
char				*ft_lldtoa_base(long long value, int base);
char				*ft_uhhdtoa_base(unsigned char value, int base);
char				*ft_uhhdtoa_baseo(unsigned short int value, int base);
char				*ft_ulldtoa_base_alt(unsigned long long value, int base);
char				*ft_printf_bigx(t_param *ft, va_list ap, union u_format f);
char				*ft_printf_reshetka(t_param *ft, char *str);
char				*ft_printf_o(t_param *ft, va_list ap, union u_format f);
char				*ft_printf_reshetkao(t_param *ft, char *str);
size_t				ft_strlen(const char *s);
void				ft_putstr(char const *s);
char				*ft_printf_f(t_param *ft, va_list ap);
void				delenie(char *str, unsigned long long int rem, unsigned long long int sub, int i);
void				ft_bzero(void *str, size_t len);
char				*multiplication(char *a, char *b, int size1, int size2);
void				vozvedenie(char *str, int pow, char *c);
int					ft_count_poryadok(long double nbr);
int					ft_znakk(long double nbr);
char				*rec_mas(char **str);
void				otr_step(char *str, int pow);
void				ft_plus(char *str, char **ptr);
unsigned long int	ft_power(int pow);
char				**realpart(long double nbr, int count);
char				**drobpart(long double nbr, int count);
void				ft_plus_drob(char *str, char **ptr);
char				**drobpartminus(long double nbr, int count);
void				ft_plus_minus(char *str, char **ptr);
char				*ft_strdup(const char *src);
void				plusodinwithprecision(char *str, t_param *ft);
void				plusonereal(char *str);
char				*parsflot(char *str, t_param *ft);

#endif
