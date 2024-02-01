#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
int ft_printf(const char *str, ...);
void	ft_putchar(char c)
{
	write(1, &c, 1);
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

static char	*detect_next_char(char *str, va_list args)
{
	char *number_str = "";
	int value = va_arg(args, int);

	if (*str == 'd')
		number_str = ft_itoa(value);
	else if (*str == 'c')
		ft_putchar(value);
	else if (*str == 'p')
	// else if (*str == 'i')
	// else if (*str == 's')
	// else if (*str == 'u')
	// else if (*str == 'x')
	// else if (*str == 'X')
	// else if (*str == '%')
	write(1, number_str, ft_strlen(number_str));
	return str;
}

#include <stdio.h>
char * decToHex(long long int decimal) 
{
    if (decimal == 0) 
    {
        printf("Hexadecimal: 0\n");
        return;
    }

    char hexadecimal[100];
    int indx = 0;

    while (decimal > 0) 
    {
        int remainder = decimal % 16;

        if (remainder < 10)
            hexadecimal[indx++] = remainder + '0';
        else
            hexadecimal[indx++] = remainder + 'A' - 10;

        decimal /= 16;
    }

    printf("Hexadecimal number is: ");

    for (int i = indx - 1; i >= 0; i--)
        printf("%c", hexadecimal[i]);

    return (hexadecimal);
}

int main()
{
    int a = 100;
    long long int b = &a;
    ;
    
    printf("%s", decToHex(b));
    printf("%p", &a);
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

int	main()
{
	// char *string = "hell%od";
	ft_printf("-%d-  -%c-  -%d-", 5443,'s',5);
}