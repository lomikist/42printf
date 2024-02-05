#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
int ft_printf(const char *str, ...);
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}
void	ft_putnbr(int nb)
{
	char	k;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		if (nb > 9)
			ft_putnbr(nb / 10);
		k = nb % 10 + '0';
		write (1, &k, 1);
	}
}

static int	int_size(long long int n)
{
	int	len;

	len = 0;
	if (n < 1)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*new_str(size_t n)
{
	char	*str;

	str = (char *)malloc(n + 1);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	m;
	int				sign;
	int				len;
	char			*str;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = int_size(n);
	str = new_str(len);
	if (!str)
		return (NULL);
	*(str + len) = '\0';
	if (n < 0)
		m = -n;
	else
		m = n;
	while (len--)
	{
		*(str + len) = 48 + m % 10;
		m /= 10;
	}
	if (sign)
		*(str) = 45;
	return (str);
}

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	printHex(long int decimal, int flag, int is_pointer) 
{
    char	hexadecimal[100];
    int		index;
	int		remainder;
	char	hex_char;

	if (flag)
		hex_char = 'a';
	else
		hex_char = 'A';
	index = 0;
    if (decimal == 0) 
        return ;
    while (decimal > 0) 
    {
        remainder = decimal % 16;
        if (remainder < 10)
            hexadecimal[index++] = remainder + '0';
        else
            hexadecimal[index++] = remainder + hex_char - 10;
        decimal /= 16;
    }
	if (is_pointer)
		write(1, "0x", 2);
	while (index >= 0)
		write(1, &hexadecimal[index--], 1);
}

static char	*detect_next_char(char *str, va_list args)
{
	long long int value = va_arg(args, long long int);

	if (*str == 'd')
		ft_putnbr(value);
	else if (*str == 'c')
		ft_putchar(value);
	else if (*str == 'p')
		printHex(value, 1, 1);
	else if (*str == 'x') 
		printHex(value, 1, 0);
	else if (*str == 'X')
		printHex(value, 0, 0);
	else if (*str == '%')
		ft_putchar('%');
	else if (*str == 's')
		ft_putstr((char *)value);
	// else if (*str == 'i')
	// else if (*str == 's')
	// else if (*str == 'u')
	// else if (*str == 'x')
	// else if (*str == 'X')
	// else if (*str == '%')
	// write(1, number_str, ft_strlen(number_str));
	return str;
}

int ft_printf(const char *str, ...)
{
	va_list args;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
			str = detect_next_char((char *)(str + 1), args);
		else
			write(1, str, 1);
		str++;
	}
	return 1;
}

int	main()
{
	// char *string = "hell%od";
	// ft_printf("-%d- -%c- -%d- -%p-", 5443, 's', 5, );
	char *somestr = "hello darkness my old friend";
	int a = 123;
	int *pa = &a;
	// long long int pval = pa;?
	// char k = 'l';
	printf("-%d- -%p- -%x- -%X- -%%- -%s- \n", a, pa, a, a, somestr);
	ft_printf("-%d- -%p- -%x- -%X- -%%- -%s-\n", a, pa, a, a, somestr);
	// printf("-%d-\n", pa);
	// printHex(pa);
}