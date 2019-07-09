#include <stdio.h>
#include "ft_printf.h"


int main()
{
   int i ;
	 int c;
    // ft_printf("asdasds%10.d  zzzz\n", 454657);
    // printf("asdasds%10.hhd  zzzz\n", -129);
  //   //
  //   ft_printf("asdasds%+10.0d  zzzz\n", 454657);
  //   printf("asdasds%+10.0d  zzzz\n", 454657);
  //
  //   ft_printf("asdasds% 10.3d  zzzz\n", 454657);
  //   printf("asdasds% 10.3d  zzzz\n", 454657);
  //   //
  //   ft_printf("asdasds%#10.3d  zzzz\n", 454657);
  //   printf("asdasds%#10.3d  zzzz\n", 454657);
  //
  //   ft_printf("asdasds%+-10.3d  zzzz\n", 454657);
  //   printf("asdasds%+-10.3d  zzzz\n", 454657);
  //
  //   ft_printf("asdasds%0+10.3d  zzzz\n", 454657);
  //   printf("asdasds%0+10.3d  zzzz\n", 454657);
  //   //
  //   ft_printf("asdasds%0+-10.3d  zzzz\n", -454657);
  //   printf("asdasds%0+-10.3d  zzzz\n", -454657);
  //
  //
  //   ft_printf("asdasds% 10.3d  zzzz\n", 0);
  //   printf("asdasds% 10.3d  zzzz\n", 0);
  //
  //   ft_printf("asdasds%10.3d  zzzz\n", -454657);
  //   printf("asdasds%10.3d  zzzz\n", -454657);
  //   ft_printf("asdasds%+10.3d  zzzz\n", -454657);
  //   printf("asdasds%+10.3d  zzzz\n", -454657);
  //
  //   ft_printf("asdasds%+-10.3d  zzzz\n", -454657);
  //   printf("asdasds%+-10.3d  zzzz\n", -454657);
  //
  //   ft_printf("asdasds%0+10.3d  zzzz\n",-454657);
  //   printf("asdasds%0+10.3d  zzzz\n",-454657);
  //
  //   ft_printf("asdasds%0+-10.3d  zzzz\n", -454657);
  //   printf("asdasds%0+-10.3d  zzzz\n", -454657);
  //
  //   ft_printf("asdasds%+-10.30d  zzzz\n", -4546);
  //   printf("asdasds%+-10.30d  zzzz\n", -4546);
  //
  //   ft_printf("asdasds%0+10.30d  zzzz\n", -454657);
  //   printf("asdasds%0+10.30d  zzzz\n", -454657);
  //
  //   ft_printf("asdasds%0+-10.30d  zzzz\n", -454657);
  //   printf("asdasds%0+-10.30d  zzzz\n", -454657);
  //
  //   ft_printf("%0+5d\n", 42);
  //   printf("%0+5d\n", 42);
  //   ft_printf("%05d\n", -42);
  //   printf("%05d\n", -42);
  //   ft_printf("@moulitest: %5.d %5.0d\n", 0, 0);
  //   printf("@moulitest: %5.d %5.0d\n", 0, 0);
  //   ft_printf("@moulitest: %0.7d %.d\n", 4, 0);
  //   printf("@moulitest: %0.7d %.d\n", 4, 0);
  //   ft_printf("@moulitest: %.10d\n", -42);
  //   printf("@moulitest: %.10d\n", -42);
  //
  //   ft_printf("%0+5d\n", -42);
  //   printf("%0+5d\n", -42);
  //
  //   ft_printf("%-5d\n", -42);
  //   printf("%-5d\n", -42);
  //   ft_printf("%-05d\n", -42);
  //   printf("%-05d\n", -42);
  //   ft_printf("%hd\n", 32768);
  //   printf("%hd\n", 32768);
  //   ft_printf("%hd\n", 92768);
  //   printf("%hd\n", 92768);
  //   ft_printf("%hhd\n", 32768);
  //   printf("%hhd\n", 32768);
  //   ft_printf("%-10.5d\n", 4242);
  //   printf("%-10.5d\n", 4242);
  //   ft_printf("%-+10.5d\n", 4242);
  //   printf("%-+10.5d\n", 4242);
  //   ft_printf("%03.2d\n", -1);
  //   printf("%03.2d\n", -1);
  //   ft_printf("%hd\n", 32768);
  //   printf("%hd\n", 32768);
  //   ft_printf("% +d\n", 42);
  //   printf("% +d\n", 42);
  //   ft_printf("%+ d\n", 42);
  //   printf("%+ d\n", 42);
  //   ft_printf("% -5d\n", 0);
  //   printf("% -5d\n", 0);
  //   ft_printf("% -05d\n", 555);
  //   printf("% -05d\n", 555);
  //   ft_printf("% +05d\n", 555);
  //   printf("% +05d\n", 555);
  //   ft_printf("% +05d\n", 555);
  //   printf("% +05d\n", 555);
  //   ft_printf("% +05.d\n", 0);
  //   printf("% +05.d\n", 0);
  //   ft_printf("% +05.2d\n", 0);
  //   printf("% +05.2d\n", 0);
  //   ft_printf("% +05d\n", 0);
  //   printf("% +05d\n", 0);
  //   ft_printf("%d\n", 2147483648);
  //   printf("%d\n", 2147483648);
  //   ft_printf("%d\n", -2147483648);
  //   printf("%d\n", -2147483648);
  //   ft_printf("%hhd\n", 128);
  //   printf("%hhd\n", 128);
  //   ft_printf("%hhd\n", -128);
  //   printf("%hhd\n", -128);
  //   ft_printf("%c\n", 'f');
  //   printf("%c\n", 'f');
  //   ft_printf("% c\n", 'f');
  //   printf("% c\n", 'f');
  //   ft_printf("%5c\n", 'f');
  //   printf("%5c\n", 'f');
  //   ft_printf("%-5c\n", 'f');
  //   printf("%-5c\n", 'f');
  //   ft_printf("%.2c\n", NULL);
  //   printf("%.2c\n", NULL);
  //   ft_printf("%-5c\n", 42);
  //   printf("%-5c\n", 42);
  //   ft_printf("@moulitest: %cr\n", 0);
  //   printf("@moulitest: %cr\n", 0);
  //   ft_printf("%2cr\n", 0);
  //   printf("%2cr\n", 0);
  //   ft_printf("null %c and textr\n", 0);
  //   printf("null %c and textr\n", 0);
  //   ft_printf("% cr\n", 0);
  //   printf("% cr\n", 0);
  //   ft_printf("%.2c\n", NULL);
  //   printf("%.2c\n", NULL);
  //   ft_printf("%5.2s is a string\n", "this");
  //   printf("%5.2s is a string\n", "this");
  //   ft_printf("%5.2sis a string\n", "");
  //   printf("%5.2sis a string\n", "");
  //   ft_printf("%5.3sis a string\n", "");
  //   printf("%5.3sis a string\n", "");
  //   ft_printf("@moulitest: %10s\n", NULL);
  //   printf("@moulitest: %10s\n", NULL);
  //   ft_printf("%5.7s is a string\n", "");
  //   printf("%5.7s is a string\n", "");
  //   ft_printf("%.7s is a string\n", "");
  //   printf("%.7s is a string\n", "");
  //   ft_printf("%.2s is a string\n", "this");
  //   printf("%.2s is a string\n", "this");
  //
  //   ft_printf("asdasds%10.0030d  zzzz\n", 454657);
  //   printf("asdasds%10.0030d  zzzz\n", 454657);
  //   ft_printf("%u\n", -1);
  //   printf("%u\n", -1);
  //   ft_printf("% u\n", 4294967295);
  //   printf("% u\n", 4294967295);
  //   ft_printf("%+u\n", 4294967295);
  //   printf("%+u\n", 4294967295);
  //   ft_printf("%+x\n", 4294967295);
  //   printf("%+x\n", 4294967295);
  //   ft_printf("%+.8x\n", 0xacc);
  //   printf("%+.8x\n", 0xacc);
  //   ft_printf("%X\n", 42);
  //   printf("%X\n", 42);
  //   ft_printf("%#x\n", 0);
  //   printf("%#x\n", 0);
  //   ft_printf("%#X\n", 42);
  //   printf("%#X\n", 42);
  //   ft_printf("%#08x\n", 42);
  //   printf("%#08x\n", 42);
  //   ft_printf("%#08.4x\n", 42);
  //   printf("%#08.4x\n", 42);
  //   ft_printf("%#8.4x\n", 42);
  //   printf("%#8.4x\n", 42);
  //   ft_printf("%#01x\n", 42);
  //   printf("%#01x\n", 42);
  //   ft_printf("%-#8.4x\n", 42);
  //   printf("%-#8.4x\n", 42);
  //   ft_printf("%#X\n", 42);
  //   printf("%#X\n", 42);
  //   ft_printf("%#8x\n", 42);
  //   printf("%#8x\n", 42);
  //   ft_printf("%#-08x\n", 42);
  //   printf("%#-08x\n", 42);
  //   ft_printf("%#X\n", 42);
  //   printf("%#X\n", 42);
  //   ft_printf("%%\n");
  //   printf("%%\n");
  //   ft_printf("%#6o\n", 2500);
  //   printf("%#6o\n", 2500);
  //   ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
  //   printf("@moulitest: %#.o %#.0o\n", 0, 0);
  //   ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
  //   printf("@moulitest: %#.x %#.0x\n", 0, 0);
  //   ft_printf("%.2c2\n", NULL);
  //   printf("%.2c2\n", NULL);
  //   ft_printf("%-5c2\n", 42);
  //   printf("%-5c2\n", 42);
  //   ft_printf("%.2c34%c4\n", NULL,'g');
  //   printf("%.2c34%c4\n", NULL,'g');
  //   ft_printf("%c2\n", NULL);
  //   printf("%c2\n", NULL);
  //   ft_printf("%-5+d\n", -42);
  //   printf("%-5+d\n", -42);
  //   printf("\n");
  //ft_printf("%");
  //   printf("%");
  // ft_printf("as%.30f  zzzz\n", 3452.783424149);
	// printf("as%.30f  zzzz\n", 3452.783424149);
	// ft_printf("as%.30f  zzzz\n", 3452.783424149);
	// printf("as%.30f  zzzz\n", 3452.783424149);
	// ft_printf("as%.30f  zzzz\n", 1.783424149);
	// printf("as%.30f  zzzz\n", 1.783424149);
	// // ft_printf("as%f  zzzz\n", 0.783424149);
	// // printf("as%f  zzzz\n", 0.783424149);
	// ft_printf("as%+f  zzzz\n", 1043636436.263636397893);
	// ft_printf("as%+f  zzzz\n", 034564363.2363633);

	// ft_printf("as%+.10f  zzzz\n", 0.0);
	// printf("as%+.10f  zzzz\n", 0.0);

	// ft_printf("as%+f  zzzz\n", -164363460.2463633);
	//
	// printf("\n\n\n\n\n");
	// ft_printf("as%+.10000Lf  zzzz\n", LDBL_MIN);
	// printf("as%+.10000Lf  zzzz\n", LDBL_MIN);
	// ft_printf("as%-+15f  zzzz\n", -99.5);
	// printf("as%-+15f  zzzz\n", -99.5);
	// ft_printf("as%-+15f  zzzz\n", 0.5);
	// printf("as%-+15f  zzzz\n", 0.5);
	// ft_printf("as%-+15f  zzzz\n", 99.5);
	// printf("as%0+15f  zzzz\n", 0.4445);
	// ft_printf("as%0+15f  zzzz\n", 0.44446346363636363635);
	// printf("as%-+15f  zzzz\n", 99.5);
	// ft_printf("as%-+15f  zzzz\n", 99.5);
	// printf("as%-+15f  zzzz\n", 99.5);
	// ft_printf("as%-+15f  zzzz\n", 99.5);
	// printf("as%-+15f  zzzz\n", 99.5);
	// ft_printf("as%-+15f  zzzz\n", 99.5);
	// printf("as%-+15f  zzzz\n", 99.5);
	// ft_printf("as%-+15f  zzzz\n", 99.5);
	// printf("as%-+15f  zzzz\n", 99.5);
	// ft_printf("as%-+15f  zzzz\n", 99.5);
	// printf("as%-+15f  zzzz\n", 99.5);
	// ft_printf("as%-+15f  zzzz\n", 99.5);
	// printf("as%-+15f  zzzz\n", 99.5);
	// ft_printf("as%-+15f  zzzz\n", 99.5);
	// printf("as%-+15f  zzzz\n", 99.5);
	// ft_printf("as%f  zzzz\n", -9.56456377375475);
	// printf("as%f  zzzz\n", -9.56456377375475);
	// ft_printf("as%f  zzzz\n", 9.56456377375475);
	// printf("as%f  zzzz\n", 9.56456377375475);
	// ft_printf("as%f  zzzz\n", 9.56456377375475);
	// printf("as%f  zzzz\n", 9.56456377375475);
	// ft_printf("as%.10f  zzzz\n", 0.56456377375475);
	// printf("as%.10f  zzzz\n", 0.56456377375475);
	// ft_printf("as%.f  zzzz\n", 1.5);
	// printf("as%.f  zzzz\n", 1.5);
	// ft_printf("as%.f  zzzz\n", 9.490);
	// printf("as%.f  zzzz\n", 9.490);
	// ft_printf("as%.f  zzzz\n", 9.520);
	// printf("as%.f  zzzz\n", 9.520);
	// ft_printf("as%f  zzzz\n", -99.500);
	// printf("as%f  zzzz\n", -99.500);
	// ft_printf("as%f  zzzz\n", 9.555555);
	// printf("as%f  zzzz\n", 9.555555);
	// ft_printf("as%f  zzzz\n", 98.9999999);
	// printf("as%f  zzzz\n", 98.9999999);
	// ft_printf("as%f  zzzz\n", 99.9999999);
	// printf("as%f  zzzz\n",99.9999999);
	// printf("as%.1f  zzzz\n", 9.500000000001);
	// ft_printf("as%.30f  zzzz\n", 3452.783424149);
	// printf("as%.30f  zzzz\n", 3452.783424149);
	// ft_printf("as%.30f  zzzz\n", 3452.783424149);
	// printf("as%.30f  zzzz\n", 3452.783424149);
	// ft_printf("as%.30f  zzzz\n", -3452.783424149);
	// printf("as%.30f  zzzz\n", -3452.783424149);
	// ft_printf("as%.30f  zzzz\n", -1.783424149);
	// printf("as%.30f  zzzz\n", -1.783424149);
	// ft_printf("as%f  zzzz\n", -0.783424149);
	// printf("as%f  zzzz\n", -0.783424149);
	// ft_printf("as%f  zzzz\n", -0.25);
	// printf("as%f  zzzz\n", -0.25);
	// ft_printf("as%.30f  zzzz\n", 0.25);
	// printf("as%.30f  zzzz\n", 0.25);
	// ft_printf("as%.30f  zzzz\n", 0.25);
	// printf("as%.30f  zzzz\n", 0.25);
	// printf("as%f  zzzz\n", 3452.783424149);
	// printf("as%Lf  zzzz\n", 54.5e400);
	// ft_printf("as%f  zzzz\n", 0.5e100);
	// ft_printf("as%f  zzzz\n", 1.5e100);
	// ft_printf("as%f  zzzz\n", -1.5e100);
	// ft_printf("as%f  zzzz\n", -0.5e100);
	// ft_printf("as%f  zzzz\n", 2.5e100);
	// ft_printf("as%f  zzzz\n", 00.5e100);
	// ft_printf("as%f  zzzz\n", 4.5e100);
	// printf("as%.2f  zzzz\n", 0.1250000000);
	// printf("as%.2f  zzzz\n", 3.55);
	//
	// printf("as% +-7.2fkk  zzzz\n", 1.0);

  // ft_printf("as%.10000Lf  zzzz\n", LDBL_MIN);
  // printf("as%.10000Lf  zzzz\n", LDBL_MIN);
  // printf("as%05.3f  zzzz\n", 54);
  // printf("as%2.5f  zzzz\n", 54);
  // printf("as%+f  zzzz\n", 54);
  // printf("as%.8f  zzzz\n", 54);
	// ft_printf("%#llxhh\n", 9223372036854775807);
	// printf("%#llxhh\n", 9223372036854775807);
	ft_printf("%");
	printf("%");
	ft_printf("%hu, %hu\n", 0, USHRT_MAX);
	printf("%hu, %hu\n", 0, USHRT_MAX);
	ft_printf("%ho, %ho\n", 0, USHRT_MAX);
	printf("%ho, %ho\n", 0, USHRT_MAX);
	ft_printf("%hx, %hx\n", 0, USHRT_MAX);
	printf("%hx, %hx\n", 0, USHRT_MAX);
	ft_printf("%hX, %hX\n", 0, USHRT_MAX);
	printf("%hX, %hX\n", 0, USHRT_MAX);
	ft_printf("%p\n", 0);
	printf("%p\n", 0);
	ft_printf("%hhu, %hhu\n", 0, UCHAR_MAX);
	printf("%hhu, %hhu\n", 0, UCHAR_MAX);
	ft_printf("%#o\n", 0);
	printf("%#o\n", 0);
	ft_printf("%.4d\n", -424242);
	printf("%.4d\n", -424242);
	ft_printf("%15.4d\n", -42);
	printf("%15.4d\n", -42);
	ft_printf("%15.4s\n", "42");
	printf("%15.4s\n", "42");
	ft_printf("%15.4s\n", 0);
	printf("%15.4s\n", 0);
	i = ft_printf("%s\n", "42 is the answer");
	c = printf("%s\n", "42 is the answer");
	printf("%d%d\n",i,c);
	ft_printf("%.p, %.p\n", 0, 0);
	printf("%.p, %.p\n", 0, 0);
	ft_printf("{%#.5x}\n", 1);
	printf("{%#.5x}\n", 1);
	ft_printf("{%-15p}\n", 0);
	printf("{%-15p}\n", 0);
	ft_printf("{% 03d}\n", 0);
	printf("{% 03d}\n", 0);
	ft_printf("%#.3o\n", 1);
	printf("%#.3o\n", 1);
	ft_printf("%#.o, %#.0o\n", 0, 0);
	printf("%#.o, %#.0o\n", 0, 0);
	ft_printf("{%*d}\n", -5, 42);
	printf("{%*d}\n", -5, 42);
	ft_printf("{%*c}\n", -15, 0);
	printf("{%*c}\n", -15, 0);
	ft_printf("{%-15c}\n", 0);
	printf("{%-15c}\n", 0);
	ft_printf("{%*c}\n", -15, 0);
	printf("{%*c}\n", -15, 0);
	ft_printf("{%.*s}\n", 0, "42");
	printf("{%.*s}\n", 0, "42");
	ft_printf("{%05.*d}\n", -15, 42);
	printf("{%05.*d}\n", -15, 42);
	ft_printf("{%05.15d}\n", 42);
	printf("{%05.15d}\n", 42);















}
