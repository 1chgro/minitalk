/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:54:48 by olachgue          #+#    #+#             */
/*   Updated: 2024/11/24 14:31:02 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_ptr_hex(unsigned long num)
{
	int		length;
	char	*hex_digits;

	length = 0;
	hex_digits = "0123456789abcdef";
	if (num >= 16)
		length += print_ptr_hex(num / 16);
	length += write(1, &hex_digits[num % 16], 1);
	return (length);
}

int	ft_printptr(void *ptr)
{
	int	length;

	length = 0;
	length += ft_printstr("0x");
	if (ptr == NULL)
		return (length + ft_printchar('0'));
	length += print_ptr_hex((unsigned long)ptr);
	return (length);
}
