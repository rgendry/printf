#include <stdio.h>
#include "include/ft_printf.h"

int main()
{
  // int i ;
  //   ft_printf("asdasds%10.d  zzzz\n", 454657);
  //   printf("asdasds%10.d  zzzz\n", 454657);
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
  //   ft_printf("%");
  //   printf("%");
  // ft_printf("as%f  zzzz\n", 54);
  // printf("as%.0f  zzzz\n", 54);
  // printf("as%.5f  zzzz\n", 54);
  // printf("as%05.3f  zzzz\n", 54);
  // printf("as%2.5f  zzzz\n", 54);
  // printf("as%+f  zzzz\n", 54);
  // printf("as%.8f  zzzz\n", 54);

}
