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

static int dec_to_hex(long int  decimal, char *base, size_t divider)
{
	char	hexadecimal[100];
	int		i;
	int		count;
	int		remainder;

	i = 0;
	count = 0;
	remainder = 0;
	if (decimal == 0)
		count = ft_putchar('0');
	while (decimal != 0)
	{
		remainder = decimal % divider;
		hexadecimal[i] = base[remainder];
		decimal /= divider;
		++i;
	}
	while (i-- > 0)
	{
		write(1, &hexadecimal[i], 1);
		count++;
	}
	return (count);
}

int prepear_for_hex(long long int number, char specify, int base_count)
{
	int	count;

	count = 0;
	if ((specify == 'd' || specify == 'i' || specify == 'u') && number < 0)
	{
		if (specify == 'u')
			number = (unsigned)number;
		else 
		{
			count += ft_putchar('-');
			number = -number;
		}
	}
	if(specify == 'p' && !number)
	{
		write(1, "0x0", 3);
		count += 3;
	}
	else if(specify == 'p')
	{
		write(1, "0x", 2);
		count += 2;
	}
	dec_to_hex(number, "0123456789abcdef", base_count);
	return (count);
}

static char	 *detect_next_char(char *str, va_list args, int *count)
{
	if (*str == 'd' || *str == 'i')
		*count = *count + prepear_for_hex(va_arg(args, int), 'd', 10);//!TODO ask it to Davo if its is right.
	else if (*str == 'c')
		*count = *count + ft_putchar(va_arg(args, long long int));
	else if (*str == 'x')
		*count = *count + dec_to_hex(va_arg(args, long int), "0123456789abcdef", 16);
	else if (*str == 'X')
		*count = *count + dec_to_hex(va_arg(args, ssize_t), "0123456789ABCDEF", 16);
	else if (*str == 'p')
		*count = *count + prepear_for_hex(va_arg(args, long long int), 'p', 16);
	else if (*str == 's')
		*count = *count + ft_putstr((char *)va_arg(args, long long int));
	else if (*str == 'u')
		*count = *count + prepear_for_hex(va_arg(args, long long int), 'u', 10);
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
#include <stdio.h>
int	 main()
{
		 char *string = "hellsdad";

// 		printf("-%%%x-\n", -42);
// 		ft_printf("-%%%x-\n", -42);
// 		printf("++++++++++++++++++++++++");
// }
// 		 ft_printf("-%d- -%c- -%x- -%X- -%p- -%s- -%i- -%u- \n", -5443, 's', -124, -124, &string[0], &string[0], 3241, -42324);
// 			printf("-%d- -%c- -%x- -%X- -%p- -%s- -%i- -%u- \n", -5443, 's', -124, -124, &string[0], &string[0], 3241, -42324);
// // }
// 		ft_printf("-%X-\n", -132);
// 		printf("-%X-\n", -132);
// // }	
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
		
		printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%%%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 , 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
		ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%%%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
}