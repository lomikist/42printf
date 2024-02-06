#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

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

void decToHex(long long int decimal) 
{
	char	hexadecimal[100];
	int		indx = 0;

	if (decimal == 0) 
		return;
	while (decimal > 0) 
	{
		int remainder = decimal % 16;

		if (remainder < 10)
			hexadecimal[indx++] = remainder + '0';
		else
			hexadecimal[indx++] = remainder + 'a' - 10;
		decimal /= 16;
	}
	write(1, "0x", 2);
	while (indx-- >= 0)
		write(1, &hexadecimal[indx], 1);
}

static char	*detect_next_char(char *str, va_list args)
{
	long long int	value;

	value = va_arg(args, long long int);
	if (*str == 'd')
		ft_putnbr(value);
	else if (*str == 'c')
		ft_putchar(value);
	else if (*str == 'x')
		decToHex(value);
	else if (*str == 'p')
		decToHex(value);
	else if (*str == 's')
		ft_putstr((char *)value);
	// else if (*str == 'i')
	// else if (*str == 's')
	// else if (*str == 'u')
	// else if (*str == 'x')
	// else if (*str == 'X')
	// else if (*str == '%')
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
int	main()
{
	char *string = "hellsdad";
	ft_printf("-%d-  -%d-  -%x-  -%s-\n", 5443, 's', 124, &string[0]);
	printf("-%d-  -%d-  -%x-  -%s-\n", 5443, 's', 124, &string[0]);
}