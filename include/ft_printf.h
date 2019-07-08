/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 12:54:30 by olesgedz          #+#    #+#             */
/*   Updated: 2019/07/07 20:45:22 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** --------------------------- Librairies --------------------------------------
*/

//# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>

typedef struct	s_sub
{
	int			i;
	int			j;
	int			k;
}				t_sub;

typedef struct	s_param
{
	int		plus:1;
	int		minus:1;
	int		space:1;
	int		reshetka:1;
	int		zero:1;
	int		l:1;
	int		ll:1;
	int		h:1;
	int		hh:1;
	int		j:1;
	int		z:1;
	int		width;
	int		precision;
	int		precision1;
	int		precision2;
	int		cur_len;
	int		cflag;
}			t_param;

union u_format
{
	char				c;
	char				*s;
	signed char			sc;
	unsigned char		uc;
	wchar_t				*ws;
	wchar_t				wc;
	int					d;
	short int			shi;
	unsigned short int	ushi;
	unsigned int		ud;
	unsigned long		ul;
	unsigned long long	ull;
	long				ld;
	long long			lld;
};

int		ft_printf(char *format, ...);
char	*ft_param(t_param *p, char **format, va_list ap);
char	*ft_printf_mix1(t_param *ft, char **format, va_list ap, union u_format f);
// int		ft_printf_mix2(t_param *ft, char **format, va_list ap, union u_format f);
void	ft_parammode(t_param *param, char **format);
void	ft_printf_flags(t_param *param, char **format);
int		ft_nlen_base(long i, int base);
void	ft_printf_lenmod(t_param *param, char **format);
char	*ft_printf_d_default(t_param *ft, char *str);
char	*ft_printf_d(t_param *ft, va_list ap, union u_format f);
char	*ft_itoaunsc(signed char n,t_param *ft);
char	*ft_itoauun(unsigned int n);
char	*ft_printf_u(t_param *ft, va_list ap, union u_format f);

// int		ft_printf_d(t_param *ft, char **fmt, va_list ap, union u_format f);
// int		ft_lldlen_base(long long value, int base);
// void	ft_putlong(long n);
// void	ft_putlong_r(long n);
// void	ft_putlld(long long lld);
// void	ft_putlld_r(long long lld);
// void	ft_printf_d_default(t_param *ft, va_list ap, union u_format f);
// int		ft_putchar_times(int c, int times);
// void	ft_printf_d2(t_param *ftoken, union u_format f);
// void	ft_puthhd(signed char n);
// void	ft_puthhd_r(signed char n);
// void	ft_putnbr(int n);
// void	ft_putnbr_r(int n);
// void	ft_puthd_r(short int n);
// void	ft_puthd(short int n);

char			*ft_itoaun(int n,t_param *ft);
char			*ft_itoaunsi(short signed int n, t_param *ft);
char			*ft_itoaunll(unsigned long long int n);



void	ft_bzero(void *str, size_t len);
int		ft_atoi(const char *str);
void	ft_putchar(char c);

char	*ft_printf_p(t_param *ft, va_list ap);
char	*ft_printf_c(t_param *ft, va_list ap);
char	*ft_printf_s(t_param *ft,  va_list ap);
char	*ft_printf_x(t_param *ft,  va_list ap, union u_format f);
int		ft_lldlen_base(long long value, int base);
int		ft_ulld_len_base(unsigned long long value, int base);
int		ft_uld_len_base(unsigned long value, int base);
int		ft_ud_len_base(unsigned int value, int base);
int		ft_nlen_base(long value, int base);
char	*ft_ulldtoa_base(unsigned long long value, int base);
char	*ft_uldtoa_base(unsigned long value, int base);
char	*ft_lldtoa_base(long long value, int base);
char	*ft_uhhdtoa_base(unsigned char value, int base);
char	*ft_ulldtoa_base_alt(unsigned long long value, int base);
char	*ft_printf_bigx(t_param *ft, va_list ap, union u_format f);
char	*ft_printf_reshetka(t_param *ft, char *str);
char	*ft_printf_o(t_param *ft,  va_list ap, union u_format f);
char	*ft_printf_reshetkao(t_param *ft, char *str);
size_t	ft_strlen(const char *s);
void	ft_putstr(char const *s);
char	*ft_printfper(t_param *ft);

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
char *multiplication(char *a, char *b, int size1, int size2);
void vozvedenie(char *str5,int pow,char *c);
int ft_count_poryadok(double nbr);
int ft_znakk(double nbr);
unsigned long long int ft_count_mantisa(double nbr);
char *rec_mas(char **str);
void otr_step(char *str,int pow);
char	**mantis_str (double nbr);
void   ft_plus(char *str,char **ptr);
int ft_power(int pow);
char		*ft_printf_f(t_param *ft, va_list ap);
char	*ft_strdup(const char *src);












// # define PF_BUF_SIZE	64
// # define MAX(a, b)		((b & ((a - b) >> 31)) | (a & (~(a - b) >> 31)))
// # define MIN(a, b)		((a & ((a - b) >> 31)) | (b & (~(a - b) >> 31)))

// /*
// ** --------------------------- Masks Definition --------------------------------
// */
// /*
// typedef struct	s_flag
// {
// 	char		sharp : 1;
// 	char		space : 1;
// 	char		plus : 1;
// 	char		minus : 1;
// 	char		zero : 1;
// 	char		wildcard : 1;
// 	char		upcase : 1;
// 	char		short1 : 1;
// 	char		short2 : 1;
// 	char		long1 : 1;
// 	char		long2 : 1;
// 	char		intmax : 1;
// 	char		sizet : 1;
// 	char		min_len : 1;
// 	char		app_preci : 1;
// 	char		pointer : 1;
// }				t_flag;
// */
// # define F_SHARP		(1 << 0)
// # define F_SPACE		(1 << 1)
// # define F_PLUS 		(1 << 2)
// # define F_MINUS    	(1 << 3)
// # define F_ZERO			(1 << 4)
// # define F_WILDCARD		(1 << 5)
// # define F_UPCASE		(1 << 6)
// # define F_SHORT		(1 << 7)
// # define F_SHORT2		(1 << 8)
// # define F_LONG			(1 << 9)
// # define F_LONG2		(1 << 10)
// # define F_INTMAX		(1 << 11)
// # define F_SIZE_T		(1 << 12)
// # define F_MIN_LEN		(1 << 13)
// # define F_APP_PRECI	(1 << 14)
// # define F_POINTER		(1 << 15)

// /*
// ** --------------------------- ft_printf variables -----------------------------
// ** A) Printf writes the output and then returns the len (int)
// ** B) f stands for flag, defined above and extensively described in parsing.c
// ** C) min_length (digit after %) and precision (. after %) ~ parsing.c
// ** D) padding is the resulting from C and the output length.
// ** E) printed is the temporary len of chars to be send to the buffer
// ** F) fd is the file descriptor. 1 for ft_printf and can be any with ft_dprintf
// ** G) buffer_index and buff are related to the buffer function ~ buffer.c
// ** H) the variadic list (va_list ap) and the format are stored in the structure
// ** I) c is a temp char (as unsigned int) in order to have a single declaration
// */

// typedef struct	s_printf
// {
// 	int			len;
// //	t_flag		flag; //
// 	uint8_t		base;
// 	short		f;
// 	int			min_length;
// 	int			preci;
// 	int			padding;
// 	int			printed;
// 	int			fd;
// 	size_t		buffer_index;
// 	char		buff[PF_BUF_SIZE];
// 	va_list		ap;
// 	char		*format;
// 	unsigned	c;
// 	int			i;
// 	int			n;
// }				t_printf;

// /*
// ** function pointer to redirect to the correct function according to the
// ** corresponding conversion specifier
// */

// typedef void (*funPointerArray)(t_printf*);

// /*
// ** --------------------------- ft_printf main functions ------------------------
// */

// int				ft_printf(const char *format, ...);
// int				ft_dprintf(int fd, const char *format, ...);
// char			*ft_sprintf(const char *format, ...);
// void			parse_optionals(t_printf *p);
// void			cs_not_found(t_printf *p);

// /*
// ** --------------------------- number related functions ------------------------
// ** %d %D %i %f %F %b %B %o %O %u %U %h %H %a %A
// */

// void			pf_putnb(t_printf *p);
// void			pf_putnb_base(t_printf *p);
// void			itoa_printf(intmax_t d, t_printf *p, int len);
// void			itoa_base_printf(uintmax_t d, int b, t_printf *p);
// void			pf_putdouble(t_printf *p);

// /*
// ** --------------------------- number related functions ------------------------
// **  %s %S %c %C
// */

// void			pf_putstr(t_printf *p);
// void			pf_putwstr(t_printf *p);
// void			pf_character(t_printf *p);
// void			pf_puterror(t_printf *p);

// /*
// ** --------------------------- miscellaneous functions -------------------------
// */

// void			buffer(t_printf *p, void *new, size_t size);
// void			padding(t_printf *p, int n);
// void			print_pointer_address(t_printf *p);

// /*
// ** --------------------------- colors related defines --------------------------
// */

// # define PF_RED			"\033[31m"
// # define PF_GREEN		"\033[32m"
// # define PF_YELLOW		"\033[33m"
// # define PF_BLUE		"\033[34m"
// # define PF_PURPLE		"\033[35m"
// # define PF_CYAN		"\033[36m"
// # define PF_EOC			"\033[36m"

#endif
