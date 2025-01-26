/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:06:35 by olachgue          #+#    #+#             */
/*   Updated: 2024/11/24 15:28:08 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_formats(va_list ap, const char specifier)
{
	int	length;

	length = 0;
	if (specifier == 'c')
		length += ft_printchar(va_arg (ap, int));
	else if (specifier == 's')
		length += ft_printstr(va_arg (ap, char *));
	else if (specifier == 'x')
		length += ft_printhex_lower(va_arg (ap, unsigned int));
	else if (specifier == 'X')
		length += ft_printhex_upper(va_arg (ap, unsigned int));
	else if (specifier == 'p')
		length += ft_printptr(va_arg (ap, void *));
	else if (specifier == 'd')
		length += ft_print_digit_integer(va_arg (ap, int));
	else if (specifier == 'i')
		length += ft_print_digit_integer((va_arg (ap, int)));
	else if (specifier == 'u')
		length += ft_print_unsigned_decimal((va_arg (ap, unsigned int)));
	else if (specifier == '%')
		length += ft_printpercent();
	else
		length += write(1, &specifier, 1);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		length;

	if (write(1, 0, 0) != 0)
		return (-1);
	va_start(ap, format);
	length = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			length += ft_print_formats(ap, *format);
		}
		else
		{
			length += ft_printchar(*format);
		}
		format++;
	}
	va_end(ap);
	return (length);
}
