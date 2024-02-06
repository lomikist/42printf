#include "ft_printf.h"

static void    ft_putchar(char c)
{
        write(1, &c, 1);
}

static void    ft_putstr(char *str)
{
        int i;

        i = 0;
        while (str[i])
        {
                ft_putchar(str[i]);
                i++;
        }
}

static void    ft_putnbr(int nb)
{
        unsigned int    nbr;

        if (nb < 0)
        {
                ft_putchar('-');
                nbr = nb * -1;
        }
        else
                nbr = nb;
        if (nbr >= 10)
                ft_putnbr(nbr / 10);
        ft_putchar(nbr % 10 + 48);
}

static void decToHex(long long int decimal, int is_pointer, int lower_upper)
{
        char    hexadecimal[100];
        char    hex_char;
        int             indx = 0;

        if (lower_upper)
                hex_char = 'a';
        else
                hex_char = 'A';
        if (decimal == 0)
                return;
        while (decimal > 0)
        {
                int remainder = decimal % 16;

                if (remainder < 10)
                        hexadecimal[indx++] = remainder + '0';
                else
                        hexadecimal[indx++] = remainder + hex_char - 10;
                decimal /= 16;
        }
        if (is_pointer)
                write(1, "0x", 2);
        while (indx-- > 0)
                write(1, &hexadecimal[indx], 1);
}

static char     *detect_next_char(char *str, va_list args)
{
        if (*str == 'd' || *str == 'i')
                ft_putnbr(va_arg(args, long long int));
        else if (*str == 'c')
                ft_putchar(va_arg(args, long long int));
        else if (*str == 'x')
                decToHex(va_arg(args, long long int), 0, 1);
        else if (*str == 'X')
                decToHex(va_arg(args, long long int), 0, 0);
        else if (*str == 'p')
                decToHex(va_arg(args, long long int), 1, 1);
        else if (*str == 's')
                ft_putstr((char *)va_arg(args, long long int));
		else if (*str == 'u')
                ft_putnbr((unsigned long int)va_arg(args, unsigned long int));
		else if (*str == '%')
                ft_putchar('%');
        return str;
}

int ft_printf(const char *str, ...)
{
        va_list args;
        va_start(args, str);
        while (*str != '\0')// str + 1
        {
                if (*str == '%')
                        str = detect_next_char((char *)(str + 1), args);
                else
                        write(1, str, 1);
                str++;
        }
        return 1;
}
#include <stdio.h>
int     main()
{
        char *string = "hellsdad";
        ft_printf("-%d- -%c- -%x- -%X- -%p- -%s- -%i- -%u- \n", 5443, 's', -124, -124, &string[0], &string[0], 3241, -42324);
           printf("-%d- -%c- -%x- -%X- -%p- -%s- -%i- -%u- \n", 5443, 's', -124, -124, &string[0], &string[0], 3241, -42324);
		ft_printf("-%X-\n", -1);
		printf("-%X-\n", -1);	
		ft_printf("-%X-\n", 1);
		printf("-%X-\n", 1);
		ft_printf("-%X-\n", 9);
		printf("-%X-\n", 9);
		ft_printf("-%X-\n", 10);
		printf("-%X-\n", 10);
		ft_printf("-%X-\n", 11);
		printf("-%X-\n", 11);
		ft_printf("-%X-\n", 15);
		printf("-%X-\n", 15);
		ft_printf("-%X-\n", 16);
		printf("-%X-\n", 16);
		ft_printf("-%X-\n", 17);
		printf("-%X-\n", 17);
		ft_printf("-%X-\n", 99);
		printf("-%X-\n", 99);
		ft_printf("-%X-\n", 100);
		printf("-%X-\n", 100);
		ft_printf("-%X-\n", 101);
		printf("-%X-\n", 101);
		ft_printf("-%X-\n", -9);
		printf("-%X-\n", -9);
		ft_printf("-%X-\n", -10);
		printf("-%X-\n", -10);
		ft_printf("-%X-\n", -11);
		printf("-%X-\n", -11);
		ft_printf("-%X-\n", -14);
		printf("-%X-\n", -14);
		ft_printf("-%X-\n", -15);
		printf("-%X-\n", -15);
		ft_printf("-%X-\n", -16);
		printf("-%X-\n", -16);
		ft_printf("-%X-\n", -99);
		printf("-%X-\n", -99);
		ft_printf("-%X-\n", -100);
		printf("-%X-\n", -100);
		ft_printf("-%X-\n", -101);
		printf("-%X-\n", -101);
}