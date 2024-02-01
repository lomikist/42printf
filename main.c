#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
int ft_printf(const char *str, ...);

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

static void	detect_next_char(char *str, va_list args)
{
	int	i = 0;
	int j = 0;
	char *number_str;

	int value = va_arg(args, int);
	if (str[i] == 'd')
		number_str = ft_itoa(value);
	write(1, number_str, ft_strlen(number_str));
	while (str[i] != '%' && str[i] != '\0')
	{
		write(1, &str[i], 1);
		++i; 
	}
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int i = 0;
	va_start(args, str);

	while (str[i] != '%' && str[i] != '\0' && str[i + 1] != '\0')
	{
		detect_next_char((char *)&str[i + 1], args);
		i++;
	}
}

int	main()
{
	char *string = "hell%od";
	ft_printf("h  %d   f   %d  k  %d    k", 5443,4,5);
}