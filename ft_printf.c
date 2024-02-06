#include "ft_printf.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putstr(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

static int	ft_putnbr(int nb)
{
	unsigned int	nbr;
	int				count;

	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= 10)
		count +=ft_putnbr(nbr / 10);
	count += ft_putchar(nbr % 10 + 48);
	return (count);
}

static int decToHex(long long int decimal, int is_pointer, int lower_upper)
{
	char	hexadecimal[100];
	char	hex_char;
	int		indx;
	int		count;

	indx = 0;
	count = 0;
	if (lower_upper)
			hex_char = 'a';
	else
			hex_char = 'A';
	if (decimal == 0)
			return 0;
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
	{
		count += 2;
		write(1, "0x", 2);
	}
	while (indx-- > 0)
	{
		write(1, &hexadecimal[indx], 1);
		count++;
	}
	return (count);
}

static char	 *detect_next_char(char *str, va_list args, int *count)
{
	if (*str == 'd' || *str == 'i')
		*count = *count + ft_putnbr(va_arg(args, long long int));
	else if (*str == 'c')
		*count = *count + ft_putchar(va_arg(args, long long int));
	else if (*str == 'x')
		*count = *count + decToHex(va_arg(args, long long int), 0, 1);
	else if (*str == 'X')
		*count = *count + decToHex(va_arg(args, long long int), 0, 0);
	else if (*str == 'p')
		*count = *count + decToHex(va_arg(args, long long int), 1, 1);
	else if (*str == 's')
		*count = *count + ft_putstr((char *)va_arg(args, long long int));
	else if (*str == 'u')
		*count = *count + ft_putnbr((unsigned long int)va_arg(args, unsigned long int));
	else if (*str == '%')
		*count = *count + ft_putchar('%');
	return str;
}

int ft_printf(const char *str, ...)
{
	int	count;

	count = 0;
	va_list args;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
			str = detect_next_char((char *)(str + 1), args, &count);
		else
			count += ft_putchar(*str);
		str++;
	}
	return (count);
}
// #include <stdio.h>
// int	 main()
// {
// 		 char *string = "hellsdad";
// 		 ft_printf("-%d- -%c- -%x- -%X- -%p- -%s- -%i- -%u- \n", 5443, 's', -124, -124, &string[0], &string[0], 3241, -42324);
// 			printf("-%d- -%c- -%x- -%X- -%p- -%s- -%i- -%u- \n", 5443, 's', -124, -124, &string[0], &string[0], 3241, -42324);
// }
// 		ft_printf("-%X-\n", -1);
// 		printf("-%X-\n", -1);	
// 		ft_printf("-%X-\n", 1);
// 		printf("-%X-\n", 1);
// 		ft_printf("-%X-\n", 9);
// 		printf("-%X-\n", 9);
// 		ft_printf("-%X-\n", 10);
// 		printf("-%X-\n", 10);
// 		ft_printf("-%X-\n", 11);
// 		printf("-%X-\n", 11);
// 		ft_printf("-%X-\n", 15);
// 		printf("-%X-\n", 15);
// 		ft_printf("-%X-\n", 16);
// 		printf("-%X-\n", 16);
// 		ft_printf("-%X-\n", 17);
// 		printf("-%X-\n", 17);
// 		ft_printf("-%X-\n", 99);
// 		printf("-%X-\n", 99);
// 		ft_printf("-%X-\n", 100);
// 		printf("-%X-\n", 100);
// 		ft_printf("-%X-\n", 101);
// 		printf("-%X-\n", 101);
// 		ft_printf("-%X-\n", -9);
// 		printf("-%X-\n", -9);
// 		ft_printf("-%X-\n", -10);
// 		printf("-%X-\n", -10);
// 		ft_printf("-%X-\n", -11);
// 		printf("-%X-\n", -11);
// 		ft_printf("-%X-\n", -14);
// 		printf("-%X-\n", -14);
// 		ft_printf("-%X-\n", -15);
// 		printf("-%X-\n", -15);
// 		ft_printf("-%X-\n", -16);
// 		printf("-%X-\n", -16);
// 		ft_printf("-%X-\n", -99);
// 		printf("-%X-\n", -99);
// 		ft_printf("-%X-\n", -100);
// 		printf("-%X-\n", -100);
// 		ft_printf("-%X-\n", -101);
// 		printf("-%X-\n", -101);

// 		printf("%c\n", '0');
// 		ft_printf("%c\n", '0');
// 		printf(" %c \n", '0');
// 		ft_printf(" %c \n", '0');
// 		printf(" %c\n", '0' - 256);
// 		ft_printf(" %c\n", '0' - 256);
// 		printf("%c \n", '0' + 256);
// 		ft_printf("%c \n", '0' + 256);
// 		printf(" %c %c %c \n", '0', 0, '1');
// 		ft_printf(" %c %c %c \n", '0', 0, '1');
// 		printf(" %c %c %c \n", ' ', ' ', ' ');
// 		ft_printf(" %c %c %c \n", ' ', ' ', ' ');
// 		printf(" %c %c %c \n", '1', '2', '3');
// 		ft_printf(" %c %c %c \n", '1', '2', '3');
// 		printf(" %c %c %c \n", '2', '1', 0);
// 		ft_printf(" %c %c %c \n", '2', '1', 0);
//         printf(" %c %c %c \n", 0, '1', '2');
//         ft_printf(" %c %c %c \n", 0, '1', '2');
// }