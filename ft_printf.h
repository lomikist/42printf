/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:46:09 by arsargsy          #+#    #+#             */
/*   Updated: 2024/02/06 19:47:34 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>

// void    ft_putchar(char c);
// void    ft_putstr(char *str);
// void    ft_putnbr(int nb);
// void decToHex(long long int decimal, int is_pointer, int lower_upper);
// static char     *detect_next_char(char *str, va_list args);
int ft_printf(const char *str, ...);

#endif  /* FT_PRINTF_H */
